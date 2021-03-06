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
    if (Collision(pic_platform))
    {
        moves_y = -speed + rng->Next(rngMin, rngMax);
        pic_ball->Top += moves_y;
        PlaySound("wav/paletka.wav");
    }
    //  Je¿eli znajdujemy siê nad platform¹
    /*if ((pic_ball->Left >= pic_platform->Left) && (pic_ball->Left - pic_ball->Width <= pic_platform->Left + pic_platform->Width))
    {
        //  Je¿eli wysokoœæ pi³ki jest poni¿ej platformy
        if (pic_ball->Top >= pic_platform->Top - pic_ball->Height)
        {
            moves_y = -speed + rng->Next(rngMin, rngMax);
            pic_ball->Top += moves_y;
        }
    }*/

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
        //  JE¯ELI obiekt jest ceg³¹ ORAZ jest kolizyjny z pi³eczk¹
        if (IsBrick(var) && Collision(var) && var->Visible)
        {
            BrickCollisionAction(var);
            PlaySound("wav/zbicie.wav");
        }
        //  Sprawdzenie czy obiekt jest ceg³¹
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
/// Funkcja zwraca kolizjê obiektu z pi³k¹
/// </summary>
/// <param name="var"></param>
/// <returns></returns>
System::Boolean kursarkanoid::formGame::Collision(Control^ var)
{
    bool result = false;
    
    //  Sprawdzenie czy pi³ka pokrywa siê w osi X z obiektem
    if (((pic_ball->Left + pic_ball->Width) >= (var->Left))
        && ((pic_ball)->Left <= (var->Left + var->Width)))
    {
        //  Sprawdzenie czy pi³ka pokrywa siê w osi Y z obiektem
        if (((pic_ball->Top + pic_ball->Height) >= (var->Top )) 
            && ((pic_ball->Top) <= (var->Top+var->Height)))
        {
            result = true;
        }
    }
    return result;
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
    brickCnt = 0;
    //  Zerowanie prêdkoœci
    speedBall = 10;
    speedPlatform = 20;
    //  Ustawienie pozycji poczatkowej
    InitPosition();
    //  Losowanie cegielek
    BrickGenerate();
    //  Nowy status do automatu
    status = 'N';
}
/// <summary>
/// 
/// </summary>
/// <returns></returns>
System::Void kursarkanoid::formGame::newTour()
{
    speedBall = 10;
    speedPlatform = 20;
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
    PlaySound("wav/smiech.wav");
}
/// <summary>
/// 
/// </summary>
/// <returns></returns>
System::Void kursarkanoid::formGame::BrickGenerate()
{
    Random^ rng = gcnew Random;
    int imagesNumber = 0;
    for each (Control^ var in Controls)
    {
        if ((var->Tag == "brick") || (var->Tag == "brick_metal") || (var->Tag == "brick_metalCrack") 
            || (var->Tag == "brick_red") || (var->Tag == "brick_yellow") || (var->Tag == "brick_blue") 
            || (var->Tag == "brick_green"))
        {
            imagesNumber = rng->Next(1, 6);
            PictureBox^ brick = (PictureBox^)var;
            brick->Image = gfx_brick->Images[imagesNumber];
            switch (imagesNumber)
            {
            case 0:
                brick->Tag = "brick_metalCrack";
                break;
            case 1:
                brick->Tag = "brick_metal";
                break;
            case 2:
                brick->Tag = "brick_red";
                break;
            case 3:
                brick->Tag = "brick_yellow";
                break;
            case 4:
                brick->Tag = "brick_blue";
                break;
            case 5:
                brick->Tag = "brick_green";
                break;
            default:
                break;
            }

            
            brick->Visible = true;
        }
    }
}
/// <summary>
/// 
/// </summary>
/// <param name="brick"></param>
/// <returns></returns>
System::Void kursarkanoid::formGame::BrickCollisionAction(Control^ brick)
{
    //  Zmienne
    PictureBox^ brickPic = (PictureBox^)brick;

    if (brickPic->Tag == "brick_metalCrack")   //  metal rozbity
    {
        brickPic->Visible = false;
        score += 20;
        brickCnt++;
    }
    else if (brickPic->Tag == "brick_metal") //  metalowy
    {
        brickPic->Image = gfx_brick->Images[0];
        brickPic->Tag = "brick_metalCrack";
        PlaySound("wav/kruszenie.wav");
    }
    else if (brickPic->Tag == "brick_red") //  czerwony
    {
        brickPic->Visible = false;
        speedBall += 10;
        score += 10;
        brickCnt++;
    }
    else if (brickPic->Tag == "brick_yellow")   //  ¿ó³ty
    {
        brickPic->Visible = false;
        speedPlatform -= 5;
        score += 10;
        brickCnt++;
    }
    else if (brickPic->Tag == "brick_blue")   //  niebieski
    {
        brickPic->Visible = false;
        speedBall -= 5;
        score += 10;
        brickCnt++;
    }
    else if (brickPic->Tag == "brick_green")   //  zielony
    {
        brickPic->Visible = false;
        speedPlatform = 20;
        speedBall = 10;
        score += 10;
        brickCnt++;
    }

    if (speedBall < 10) speedBall = 10;
    if (speedPlatform < 2) speedBall = 2;

    moves_y = -moves_y;
    pic_ball->Top += moves_y;
    lbl_score->Text = Convert::ToString(score);

    if (brickCnt >= 40)
    {
        newGame();
        MessageBox::Show("Ty byku!", "Yupi!", MessageBoxButtons::OK, MessageBoxIcon::Information);
        PlaySound("wav/wygrana.wav");
    }



}
/// <summary>
/// 
/// </summary>
/// <param name="brick"></param>
/// <returns></returns>
System::Char kursarkanoid::formGame::BrickCollisionDir(Control^ brick)
{
    char dir = '?';
    if ((IsBrick(brick)) && (brick->Visible == true))
    {
        //  Sprawdzenie czy pi³ka pokrywa siê w osi X z ceg³¹
        if (((pic_ball->Left + pic_ball->Width) >= (brick->Left))
            && ((pic_ball)->Left <= (brick->Left + brick->Width)))
        {
            //  Sprawdzenie czy pi³ka pokrywa siê w osi Y z ceg³¹

            if ((pic_ball->Top <= brick->Top + brick->Height) && pic_ball->Top >= brick->Top)
            {
                //  Odleg³oœæ od zachodniej œcianki mniejsza ni¿ 5
                if (Math::Abs(pic_ball->Left - brick->Left) <= 5) dir = 'W';
                if (Math::Abs(pic_ball->Left - (brick->Left + brick->Width)) <= 5) dir = 'E';
                //  Odbicie od górnej krawêdzi
                if (Math::Abs(pic_ball->Top - (brick->Top) <= 5)) dir = 'N';
                //  Odbicie od dolnej krawêdzi
                if (Math::Abs(pic_ball->Top - (brick->Top+ + brick->Height) <= 5)) dir = 'S';
            }
        }
    }
    return dir;
}
/// <summary>
/// 
/// </summary>
/// <returns></returns>
System::Void kursarkanoid::formGame::Brick()
{
    return System::Void();
}
/// <summary>
/// 
/// </summary>
/// <param name="var"></param>
/// <returns></returns>
System::Boolean kursarkanoid::formGame::IsBrick(Control^ var)
{
    try
    {
        //  Próba przypisania typu PictureBox
        PictureBox^ pic = (PictureBox^)var;
        if ((pic->Tag == "brick") || (pic->Tag == "brick_metal") || (pic->Tag == "brick_metalCrack")
            || (pic->Tag == "brick_red") || (pic->Tag == "brick_yellow") || (pic->Tag == "brick_blue")
            || (pic->Tag == "brick_green"))
        {
            return true;
        }
        else
        {
            return false;
        }
            
    }
    catch (...)
    {
        return false;
    }

}
/// <summary>
/// 
/// </summary>
/// <param name="var"></param>
/// <returns></returns>
System::Void kursarkanoid::formGame::PlaySound(String^ var)
{
    try 
    {
        System::Media::SoundPlayer^ player = gcnew System::Media::SoundPlayer();
        player->SoundLocation = var;
        player->Load();
        player->Play();
    }
    catch (...)
    {
        MessageBox::Show("Kurza tfasz!", "Error handler MS office error on Linux\n Exception of Exception[]", MessageBoxButtons::AbortRetryIgnore, MessageBoxIcon::Error);
    }
    
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
