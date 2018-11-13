#pragma once
#include "MyForm1.h"
#include <string.h>
#include <fstream>
#include <iostream>
#include <list>
#using <system.dll>

namespace Project1 {

	using namespace System;
	using namespace System::IO;	
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace IO;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Sumário para MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:

		ref struct schedule
		{
			
			String^ number;
			String^ name;

		};

		MyForm(void)
		{
			InitializeComponent();

		}
		MyForm(String^ name_Myform, String^ number_Myform) {

			schedule^ Schedule = gcnew schedule();
			Schedule->name = name_Myform;
			Schedule->number = number_Myform;




		}


	protected:
		/// <summary>
		/// Limpar os recursos que estão sendo usados.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
 
	public: LinkedList<schedule^>^ scheduleAction;






	private: System::Windows::Forms::Button^  button5;	 			 					  
	private: System::Windows::Forms::Button^  button1;

	protected:

	private:
		/// <summary>
		/// Variável de designer necessária.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necessário para suporte ao Designer - não modifique 
		/// o conteúdo deste método com o editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(12, 199);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(348, 64);
			this->button5->TabIndex = 6;
			this->button5->Text = L"SAIR";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click_1);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 129);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(348, 64);
			this->button1->TabIndex = 7;
			this->button1->Text = L"AGENDA";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click_2);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(372, 275);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->button5);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);

		}



#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void listBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {	
	}
	private: System::Void button1_Click_1(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void button2_Click_1(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void button3_Click_1(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void button4_Click_1(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void button5_Click_1(System::Object^  sender, System::EventArgs^  e) {

		Close();

	}
	private: System::Void button1_Click_2(System::Object^  sender, System::EventArgs^  e) {

		OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog;

		openFileDialog1->InitialDirectory = "c:\\";
		openFileDialog1->Filter = "txt files (*.txt)|*.txt";
		openFileDialog1->FilterIndex = 1;
		openFileDialog1->RestoreDirectory = true;

		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			String^ directory = openFileDialog1->FileName;

			string dire = msclr::interop::marshal_as< std::string >(directory);

			ifstream arquive(dire);
			if (!arquive) {
				MessageBox::Show("Arquivo já está sendo utilizado em outro programa.\nFeche-o e tente novamente.");
			}
			else {
				std::getline(arquive, dire);
				if (dire != "SCHEDULE_NAME,SCHEDULE_NUMBER") {
					MessageBox::Show("Arquivo inválido.");
				}
				else {
					String^ document = directory;
					arquive.close();

					MyForm1^ tela = gcnew MyForm1(document);
					tela->ShowDialog();
					Hide();
					Show();
					Close();
				}
			}

		}
	}
	};
	}
