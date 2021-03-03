#pragma once

namespace kursarkanoid {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o formAuthor
	/// </summary>
	public ref class formAuthor : public System::Windows::Forms::Form
	{
	public:
		formAuthor(void)
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
		~formAuthor()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lbl_author;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ btn_close;
	private: System::Windows::Forms::RichTextBox^ txtRich_doc;
	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(formAuthor::typeid));
			this->lbl_author = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->btn_close = (gcnew System::Windows::Forms::Button());
			this->txtRich_doc = (gcnew System::Windows::Forms::RichTextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// lbl_author
			// 
			this->lbl_author->AutoSize = true;
			this->lbl_author->BackColor = System::Drawing::Color::Transparent;
			this->lbl_author->Font = (gcnew System::Drawing::Font(L"Courier New", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->lbl_author->Location = System::Drawing::Point(67, 26);
			this->lbl_author->Name = L"lbl_author";
			this->lbl_author->Size = System::Drawing::Size(176, 64);
			this->lbl_author->TabIndex = 0;
			this->lbl_author->Text = L"Arkanoid\r\nwww.uengineering.net/\r\nMariusz Czajkowski\r\n(c) 2021";
			this->lbl_author->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lbl_author->Click += gcnew System::EventHandler(this, &formAuthor::lbl_author_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(35, 62);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(251, 200);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// btn_close
			// 
			this->btn_close->Font = (gcnew System::Drawing::Font(L"Courier New", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btn_close->Location = System::Drawing::Point(123, 209);
			this->btn_close->Name = L"btn_close";
			this->btn_close->Size = System::Drawing::Size(75, 23);
			this->btn_close->TabIndex = 2;
			this->btn_close->Text = L"Zamknij";
			this->btn_close->UseVisualStyleBackColor = true;
			this->btn_close->Click += gcnew System::EventHandler(this, &formAuthor::btn_close_Click);
			// 
			// txtRich_doc
			// 
			this->txtRich_doc->Dock = System::Windows::Forms::DockStyle::Fill;
			this->txtRich_doc->Location = System::Drawing::Point(0, 0);
			this->txtRich_doc->Name = L"txtRich_doc";
			this->txtRich_doc->Size = System::Drawing::Size(284, 261);
			this->txtRich_doc->TabIndex = 3;
			this->txtRich_doc->Text = L"";
			this->txtRich_doc->TextChanged += gcnew System::EventHandler(this, &formAuthor::txtRich_doc_TextChanged);
			this->txtRich_doc->LoadFile("doc/test_opisu.rtf");
			// 
			// formAuthor
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->txtRich_doc);
			this->Controls->Add(this->btn_close);
			this->Controls->Add(this->lbl_author);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"formAuthor";
			this->Text = L"GRA::Arkanoid::O mnie";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void lbl_author_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btn_close_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void txtRich_doc_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
