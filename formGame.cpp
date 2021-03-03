#include "formGame.h"
/// <summary>
/// 
/// </summary>
System::Void kursarkanoid::formGame::movesBall()
{
    movesBall(10);
}
/// <summary>
/// 
/// </summary>
/// <param name="speed"></param>
/// <returns></returns>
System::Void kursarkanoid::formGame::movesBall(int speed)
{
    Random^ rng = gcnew Random;
    const int rngMin = -2, rngMax = 2;
    const int yMarginTop = 75, yMarginBottom = 0;

    pic_ball->Left += moves_x;
    pic_ball->Top += moves_y;

    //  Pi³ka przy lewej stronie
    if (pic_ball->Left <= 0)
    {
        //pic_ball->Left = 0;
        moves_x = speed + rng->Next(rngMin, rngMax);
        pic_ball->Left += moves_x;
    }
    //  Pi³ka przy prawej stronie
    else if (pic_ball->Left >= (this->Width - pic_ball->Width))
    {
        //pic_ball->Left = (this->Width - pic_ball->Width);
        moves_x = -speed + rng->Next(rngMin, rngMax);
        pic_ball->Left += moves_x;
    }

    //  Pi³ka na górze
    if (pic_ball->Top <= yMarginTop)
    {
        //pic_ball->Top = y;
        moves_y = speed + rng->Next(rngMin, rngMax);
        pic_ball->Top += moves_y;
    }
    //  Pi³ka na dole
    /*else if (pic_ball->Top >= (this->Height))
    {
        //pic_ball->Top = this->Height - y;
        moves_y = -y + rng->Next(rngMin, rngMax);
        pic_ball->Top += moves_y;
    }*/
    //  Wykrycie kolizji z platform¹
    //  Je¿eli znajdujemy siê nad platform¹
    if ((pic_ball->Left >= pic_platform->Left) && (pic_ball->Left - pic_ball->Width <= pic_platform->Left + pic_platform->Width))
    {
        //  Je¿eli wysokoœæ pi³ki jest poni¿ej platformy
        if (pic_ball->Top >= pic_platform->Top - pic_ball->Height)
        {
            moves_y = -speed + rng->Next(rngMin, rngMax);
            pic_ball->Top += moves_y;
        }
    }

    //  Sprawdzenie kolizcji z doln¹ krawêdzi¹
    if ((pic_ball->Top >= pic_platform->Top + 5) && (status == 'G'))
    {
        status = 'F';
        life--;
        score -= 50;

        lbl_life->Text = Convert::ToString(life);
        lbl_score->Text = Convert::ToString(score);

        if (life > 0)
        {
            if (MessageBox::Show("RZyciu--", "Ojajciu!", MessageBoxButtons::OK, MessageBoxIcon::Hand) == System::Windows::Forms::DialogResult::OK)
            {
                newTour();
            }
        }
        else
        {
            if (MessageBox::Show("Udupi³es!", "Ojajciu!", MessageBoxButtons::OK, MessageBoxIcon::Error) == System::Windows::Forms::DialogResult::OK)
            {
                EndGame();
            }
        }
    }

    //  Sprawdzenie kolizji z ceg³a
    for each (Control^ var in Controls)
    {
        if ((var->Tag == "red") && (var->Visible == true))
        {
            if ((pic_ball->Left >= var->Left) && (pic_ball->Left - pic_ball->Width <= var->Left + var->Width))
            {
                if ((pic_ball->Top <= var->Top + var->Height) && pic_ball->Top >= var->Top)
                {
                    var->Visible = false;
                    speedBall += 5;
                    moves_y = -moves_y;
                    pic_ball->Top += moves_y;
                    score += 10;
                    lbl_score->Text = Convert::ToString(score);
                }
            }
        }
    }


    // Info diagnostyczne
    lbl_dev1->Text = "(" + Convert::ToString(pic_ball->Left) + "," + Convert::ToString(pic_ball->Top) + ")+("
        + Convert::ToString(moves_x) + "," + Convert::ToString(moves_y) + ")";
}

    
/// <summary>
/// 
/// </summary>
/// <param name="key"></param>
/// <returns></returns>
System::Void kursarkanoid::formGame::movesPlatform(char key)
{
    movesPlatform(key, 20);
}
/// <summary>
/// 
/// </summary>
/// <param name="key"></param>
/// <returns></returns>
System::Void kursarkanoid::formGame::movesPlatform(char key, int speed)
{
    switch (key)
    {
    case 'L':
        pic_platform->Left -= speed;
        break;
    case 'R':
        pic_platform->Left += speed;
        default:
        break;
    }
    if (pic_platform->Left < 0) pic_platform->Left = 0;
    if (pic_platform->Left >= (this->Width - pic_platform->Width)) pic_platform->Left = (this->Width - pic_platform->Width);
}
/// <summary>
/// 
/// </summary>
/// <returns></returns>
System::Void kursarkanoid::formGame::InitPosition()
{
    pic_ball->Left = (this->Width / 2) - (pic_ball->Width / 2);
    pic_ball->Top = pic_platform->Top - pic_ball->Height;

    pic_platform->Left = (this->Width / 2) - (pic_platform->Width / 2);

}
/// <summary>
/// 
/// </summary>
/// <returns></returns>
System::Void kursarkanoid::formGame::newGame()
{
    //  Ukrycie rysunków
    pic_troll->Visible = false;
    btn_end->Visible = false;
    btn_again->Visible = false;
    //  Zerowanie statystyk
    life = 3;
    score = 0;
    lbl_life->Text = Convert::ToString(life);
    lbl_score->Text = Convert::ToString(score);
    //  Zerowanie prêdkoœci
    speedBall = 10;
    speedPlatform = 20;
    //  Ustawienie pozycji poczatkowej
    InitPosition();
    //  Nowy status do automatu
    status = 'N';
}
/// <summary>
/// 
/// </summary>
/// <returns></returns>
System::Void kursarkanoid::formGame::newTour()
{
    //speedBall += 5;
    speedPlatform--;
    InitPosition();
    status = 'R';
}
/// <summary>
/// 
/// </summary>
/// <returns></returns>
System::Void kursarkanoid::formGame::EndGame()
{
    //  Pokazanie rysunków
    pic_troll->Visible = true;
    btn_end->Visible = true;
    btn_again->Visible = true;
    lbl_life->Text = ":/";
    status = 'E';
}
/// <summary>
/// 
/// </summary>
/// <param name="sender"></param>
/// <param name="e"></param>
/// <returns></returns>
System::Void kursarkanoid::formGame::tmr_Tick(System::Object^ sender, System::EventArgs^ e)
{
    switch (status)
    {
    case 'R':
        this->movesPlatform(key);   //  Wywo³anie ruchu platformy
        pic_ball->Left = pic_platform->Left + (pic_platform->Width / 2) - (pic_ball->Width / 2);
        pic_ball->Top = pic_platform->Top - pic_ball->Height - 3;
        break;

    case 'E':   //  Koniec gry
        break;

    case 'G':   //  Gra
        this->movesPlatform(key, speedPlatform);   //  Wywo³anie ruchu platformy
        this->movesBall(speedBall);  //  Wywo³anie ruchu pi³eczki
        break;

    case 'F':   //  Status po przegranej
        break;

    case 'W':   //  Czekanie
        break;

    default:
        break;
    }
    //  Info diagnostyczne
    lbl_dev2->Text = Convert::ToString(status);
    
}
/// <summary>
/// 
/// </summary>
/// <param name="sender"></param>
/// <param name="e"></param>
/// <returns></returns>
System::Void kursarkanoid::formGame::getKeys(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
{
    if (e->KeyCode == Keys::Left) key = 'L';
    if (e->KeyCode == Keys::Right) key = 'R';
    if (e->KeyCode == Keys::Space)
    {
        if ((status == 'F') || (status == 'N') || (status == 'R')) 
        {
            status = 'G';
        }
    }
    
}
/// <summary>
/// 
/// </summary>
/// <param name="sender"></param>
/// <param name="e"></param>
/// <returns></returns>
System::Void kursarkanoid::formGame::getKeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
{
    key = ' ';
}

System::Void kursarkanoid::formGame::formGame_Load(System::Object^ sender, System::EventArgs^ e)
{
    newGame();
}

System::Void kursarkanoid::formGame::btn_end_Click(System::Object^ sender, System::EventArgs^ e)
{
    //Application::Exit();
    this->Close();  
}

System::Void kursarkanoid::formGame::btn_again_Click(System::Object^ sender, System::EventArgs^ e)
{
    newGame();
}
