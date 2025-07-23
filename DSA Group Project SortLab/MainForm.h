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
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->btnStart = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btnStart
			// 
			this->btnStart->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnStart->Location = System::Drawing::Point(414, 298);
			this->btnStart->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->btnStart->Name = L"btnStart";
			this->btnStart->Size = System::Drawing::Size(270, 130);
			this->btnStart->TabIndex = 0;
			this->btnStart->Text = L"Let\'s Sort!";
			this->btnStart->UseVisualStyleBackColor = true;
			this->btnStart->Click += gcnew System::EventHandler(this, &MainForm::OnStartClick);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1120, 773);
			this->Controls->Add(this->btnStart);
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"SortLab";
			this->ResumeLayout(false);

		}
#pragma endregion

	private:
		System::Void OnStartClick(System::Object^ sender, System::EventArgs^ e)
		{
			InputForm^ form = gcnew InputForm();
			form->Show();
			this->Hide();
		}
	};
}