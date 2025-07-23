#pragma once
#include "InputForm.h"

namespace DSAGroupProjectSortLab {

	using namespace System;
	using namespace System::Windows::Forms;
	using namespace System::Drawing;

	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm()
		{
			InitializeComponent();
		}

	protected:
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		System::Windows::Forms::Button^ btnStart;
	private: System::Windows::Forms::Label^ label1;
		   System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->btnStart = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// btnStart
			// 
			this->btnStart->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->btnStart->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnStart->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->btnStart->Location = System::Drawing::Point(387, 324);
			this->btnStart->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->btnStart->Name = L"btnStart";
			this->btnStart->Size = System::Drawing::Size(347, 185);
			this->btnStart->TabIndex = 0;
			this->btnStart->Text = L"Let\'s Sort!";
			this->btnStart->UseVisualStyleBackColor = false;
			this->btnStart->Click += gcnew System::EventHandler(this, &MainForm::OnStartClick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"STHupo", 72, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->label1->ForeColor = System::Drawing::SystemColors::InactiveBorder;
			this->label1->Location = System::Drawing::Point(300, 102);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(520, 149);
			this->label1->TabIndex = 1;
			this->label1->Text = L"SortLab";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label1->Click += gcnew System::EventHandler(this, &MainForm::label1_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1120, 773);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btnStart);
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"SortLab";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private:
		System::Void OnStartClick(System::Object^ sender, System::EventArgs^ e)
		{
			InputForm^ form = gcnew InputForm();
			form->Show();
			this->Hide();
		}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}