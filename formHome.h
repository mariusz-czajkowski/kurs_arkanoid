#pragma once

#include "formAuthor.h"
#include "formGame.h"

namespace kursarkanoid {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o formHome
	/// </summary>
	public ref class formHome : public System::Windows::Forms::Form
	{
	public:
		formHome(void)
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
		~formHome()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pic_play;
	protected:
	private: System::Windows::Forms::PictureBox^ pic_author;

	private:
		/// <summary>
		/// Wymagana zmienna projektanta.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Metoda wymagana do obs³ugi projektanta — nie nale¿y modyfikowaæ
		/// jej zawartoœci w edytorze kodu.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(formHome::typeid));
			this->pic_play = (gcnew System::Windows::Forms::PictureBox());
			this->pic_author = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pic_play))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pic_author))->BeginInit();
			this->SuspendLayout();
			// 
			// pic_play
			// 
			this->pic_play->BackColor = System::Drawing::Color::Transparent;
			this->pic_play->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pic_play->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pic_play.Image")));
			this->pic_play->Location = System::Drawing::Point(120, 338);
			this->pic_play->Name = L"pic_play";
			this->pic_play->Size = System::Drawing::Size(169, 86);
			this->pic_play->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pic_play->TabIndex = 0;
			this->pic_play->TabStop = false;
			this->pic_play->Click += gcnew System::EventHandler(this, &formHome::pic_play_Click);
			// 
			// pic_author
			// 
			this->pic_author->BackColor = System::Drawing::Color::Transparent;
			this->pic_author->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pic_author->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pic_author.Image")));
			this->pic_author->Location = System::Drawing::Point(419, 339);
			this->pic_author->Name = L"pic_author";
			this->pic_author->Size = System::Drawing::Size(169, 85);
			this->pic_author->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pic_author->TabIndex = 1;
			this->pic_author->TabStop = false;
			this->pic_author->Click += gcnew System::EventHandler(this, &formHome::pic_author_Click);
			// 
			// formHome
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(704, 501);
			this->Controls->Add(this->pic_author);
			this->Controls->Add(this->pic_play);
			this->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"formHome";
			this->Text = L"Gra::Arkanoid";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pic_play))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pic_author))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void pic_play_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		formGame^ playing = gcnew formGame;
		playing->Show();
		this->Close();
	}
	private: System::Void pic_author_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		formAuthor^ author = gcnew formAuthor;
		author->Show();
		//this->Close();
	}
	};
}
