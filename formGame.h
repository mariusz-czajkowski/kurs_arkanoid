#pragma once

namespace kursarkanoid 
{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o formGame
	/// </summary>
	public ref class formGame : public System::Windows::Forms::Form
	{
	public:
		formGame(void)
		{
			InitializeComponent();
			//
			//TODO: W tym miejscu dodaj kod konstruktora
			//
		}

	protected:
		/// <summary>
		/// Wyczyœæ wszystkie u¿ywane zasoby.
		/// </summary>
		~formGame()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pic_ball;
	protected:
	private: System::Windows::Forms::Timer^ tmr;


	private: System::Windows::Forms::PictureBox^ pic_platform;
	private: System::Windows::Forms::Label^ lbl_score;
	private: System::Windows::Forms::Label^ lbl_life;
	private: System::Windows::Forms::PictureBox^ btn_end;
	private: System::Windows::Forms::PictureBox^ btn_again;
	private: System::Windows::Forms::PictureBox^ pic_troll;
	private: System::Windows::Forms::ImageList^ gfx_brick;
	private: System::Windows::Forms::PictureBox^ pic_brick1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::StatusStrip^ statusStrip1;
	private: System::Windows::Forms::ToolStripStatusLabel^ lbl_dev1;
	private: System::Windows::Forms::ToolStripStatusLabel^ lbl_dev2;

	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Wymagana zmienna projektanta.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Metoda wymagana do obs³ugi projektanta — nie nale¿y modyfikowaæ
		/// jej zawartoœci w edytorze kodu.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(formGame::typeid));
			this->pic_ball = (gcnew System::Windows::Forms::PictureBox());
			this->tmr = (gcnew System::Windows::Forms::Timer(this->components));
			this->pic_platform = (gcnew System::Windows::Forms::PictureBox());
			this->lbl_score = (gcnew System::Windows::Forms::Label());
			this->lbl_life = (gcnew System::Windows::Forms::Label());
			this->btn_end = (gcnew System::Windows::Forms::PictureBox());
			this->btn_again = (gcnew System::Windows::Forms::PictureBox());
			this->pic_troll = (gcnew System::Windows::Forms::PictureBox());
			this->gfx_brick = (gcnew System::Windows::Forms::ImageList(this->components));
			this->pic_brick1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->lbl_dev1 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->lbl_dev2 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pic_ball))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pic_platform))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btn_end))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btn_again))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pic_troll))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pic_brick1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			this->statusStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// pic_ball
			// 
			this->pic_ball->BackColor = System::Drawing::Color::Transparent;
			this->pic_ball->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pic_ball.Image")));
			this->pic_ball->Location = System::Drawing::Point(350, 425);
			this->pic_ball->Name = L"pic_ball";
			this->pic_ball->Size = System::Drawing::Size(25, 25);
			this->pic_ball->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pic_ball->TabIndex = 0;
			this->pic_ball->TabStop = false;
			// 
			// tmr
			// 
			this->tmr->Enabled = true;
			this->tmr->Interval = 50;
			this->tmr->Tick += gcnew System::EventHandler(this, &formGame::tmr_Tick);
			// 
			// pic_platform
			// 
			this->pic_platform->BackColor = System::Drawing::Color::Transparent;
			this->pic_platform->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pic_platform.Image")));
			this->pic_platform->Location = System::Drawing::Point(296, 448);
			this->pic_platform->Name = L"pic_platform";
			this->pic_platform->Size = System::Drawing::Size(133, 28);
			this->pic_platform->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pic_platform->TabIndex = 2;
			this->pic_platform->TabStop = false;
			// 
			// lbl_score
			// 
			this->lbl_score->AutoSize = true;
			this->lbl_score->BackColor = System::Drawing::Color::Transparent;
			this->lbl_score->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->lbl_score->Location = System::Drawing::Point(549, 22);
			this->lbl_score->Name = L"lbl_score";
			this->lbl_score->Size = System::Drawing::Size(21, 24);
			this->lbl_score->TabIndex = 3;
			this->lbl_score->Text = L"0";
			this->lbl_score->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// lbl_life
			// 
			this->lbl_life->AutoSize = true;
			this->lbl_life->BackColor = System::Drawing::Color::Transparent;
			this->lbl_life->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->lbl_life->Location = System::Drawing::Point(659, 22);
			this->lbl_life->Name = L"lbl_life";
			this->lbl_life->Size = System::Drawing::Size(21, 24);
			this->lbl_life->TabIndex = 4;
			this->lbl_life->Text = L"3";
			// 
			// btn_end
			// 
			this->btn_end->BackColor = System::Drawing::Color::Transparent;
			this->btn_end->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_end.Image")));
			this->btn_end->Location = System::Drawing::Point(265, 220);
			this->btn_end->Name = L"btn_end";
			this->btn_end->Size = System::Drawing::Size(199, 85);
			this->btn_end->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->btn_end->TabIndex = 5;
			this->btn_end->TabStop = false;
			this->btn_end->Visible = false;
			this->btn_end->Click += gcnew System::EventHandler(this, &formGame::btn_end_Click);
			// 
			// btn_again
			// 
			this->btn_again->BackColor = System::Drawing::Color::Transparent;
			this->btn_again->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_again.Image")));
			this->btn_again->Location = System::Drawing::Point(265, 302);
			this->btn_again->Name = L"btn_again";
			this->btn_again->Size = System::Drawing::Size(199, 86);
			this->btn_again->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->btn_again->TabIndex = 6;
			this->btn_again->TabStop = false;
			this->btn_again->Visible = false;
			this->btn_again->Click += gcnew System::EventHandler(this, &formGame::btn_again_Click);
			// 
			// pic_troll
			// 
			this->pic_troll->BackColor = System::Drawing::Color::Transparent;
			this->pic_troll->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pic_troll.Image")));
			this->pic_troll->Location = System::Drawing::Point(453, 279);
			this->pic_troll->Name = L"pic_troll";
			this->pic_troll->Size = System::Drawing::Size(251, 200);
			this->pic_troll->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pic_troll->TabIndex = 7;
			this->pic_troll->TabStop = false;
			this->pic_troll->Visible = false;
			// 
			// gfx_brick
			// 
			this->gfx_brick->ImageStream = (cli::safe_cast<System::Windows::Forms::ImageListStreamer^>(resources->GetObject(L"gfx_brick.ImageStream")));
			this->gfx_brick->TransparentColor = System::Drawing::Color::Transparent;
			this->gfx_brick->Images->SetKeyName(0, L"blok_metal_rozbity.png");
			this->gfx_brick->Images->SetKeyName(1, L"blok_metal.png");
			this->gfx_brick->Images->SetKeyName(2, L"blok_czerwony.png");
			this->gfx_brick->Images->SetKeyName(3, L"blok_zolty.png");
			this->gfx_brick->Images->SetKeyName(4, L"blok_niebieski.png");
			this->gfx_brick->Images->SetKeyName(5, L"blok_zielony.png");
			// 
			// pic_brick1
			// 
			this->pic_brick1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pic_brick1.Image")));
			this->pic_brick1->Location = System::Drawing::Point(12, 78);
			this->pic_brick1->Name = L"pic_brick1";
			this->pic_brick1->Size = System::Drawing::Size(76, 36);
			this->pic_brick1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pic_brick1->TabIndex = 8;
			this->pic_brick1->TabStop = false;
			this->pic_brick1->Tag = L"red";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(112, 113);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(76, 36);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox1->TabIndex = 9;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Tag = L"red";
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(181, 172);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(76, 36);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox2->TabIndex = 10;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->Tag = L"red";
			// 
			// pictureBox3
			// 
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(313, 130);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(76, 36);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox3->TabIndex = 11;
			this->pictureBox3->TabStop = false;
			this->pictureBox3->Tag = L"red";
			// 
			// statusStrip1
			// 
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) { this->lbl_dev1, this->lbl_dev2 });
			this->statusStrip1->Location = System::Drawing::Point(0, 479);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(704, 22);
			this->statusStrip1->TabIndex = 12;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// lbl_dev1
			// 
			this->lbl_dev1->Name = L"lbl_dev1";
			this->lbl_dev1->Size = System::Drawing::Size(32, 17);
			this->lbl_dev1->Text = L"dev1";
			// 
			// lbl_dev2
			// 
			this->lbl_dev2->Name = L"lbl_dev2";
			this->lbl_dev2->Size = System::Drawing::Size(32, 17);
			this->lbl_dev2->Text = L"dev2";
			// 
			// formGame
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(704, 501);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->pic_brick1);
			this->Controls->Add(this->btn_again);
			this->Controls->Add(this->btn_end);
			this->Controls->Add(this->lbl_life);
			this->Controls->Add(this->lbl_score);
			this->Controls->Add(this->pic_platform);
			this->Controls->Add(this->pic_ball);
			this->Controls->Add(this->pic_troll);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"formGame";
			this->Text = L"formGame";
			this->Load += gcnew System::EventHandler(this, &formGame::formGame_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &formGame::getKeys);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &formGame::getKeyUp);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pic_ball))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pic_platform))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btn_end))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btn_again))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pic_troll))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pic_brick1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		/// <summary>
		/// W³asne elementy
		/// </summary>
	private: int x = 10, y = 10;
	private: int moves_x = 10, moves_y = 10, speedBall = 10, speedPlatform = 20;
	private: char status = ' ';	//	G - Gra, F - Przegrana
	private: char key = ' ';
	private: int life = 5, score = 0;

	private: System::Void movesBall();
	private: System::Void movesBall(int speed);
	private: System::Void movesPlatform(char key);
	private: System::Void movesPlatform(char key, int speed);

	private: System::Void InitPosition();
	private: System::Void newGame();
	private: System::Void newTour();
	private: System::Void EndGame();
	private: System::Void Brick();

	private: System::Void tmr_Tick(System::Object^ sender, System::EventArgs^ e);
	private: System::Void getKeys(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e);
	private: System::Void getKeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e);
	
	private: System::Void formGame_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void btn_end_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void btn_again_Click(System::Object^ sender, System::EventArgs^ e);
};
};
