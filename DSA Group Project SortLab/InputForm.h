#pragma once
#include "ResultForm.h"

namespace DSAGroupProjectSortLab {

	using namespace System;
	using namespace System::Windows::Forms;

	public ref class InputForm : public Form
	{
	public:
		InputForm()
		{
			InitializeComponent();
		}

	protected:
		~InputForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		TextBox^ txtInput;
		Button^ btnSort;
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->txtInput = (gcnew System::Windows::Forms::TextBox());
			this->btnSort = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// txtInput
			// 
			this->txtInput->Location = System::Drawing::Point(75, 62);
			this->txtInput->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->txtInput->Name = L"txtInput";
			this->txtInput->Size = System::Drawing::Size(298, 26);
			this->txtInput->TabIndex = 0;
			this->txtInput->Text = L"Enter numbers separated by commas";
			// 
			// btnSort
			// 
			this->btnSort->Location = System::Drawing::Point(150, 123);
			this->btnSort->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->btnSort->Name = L"btnSort";
			this->btnSort->Size = System::Drawing::Size(150, 46);
			this->btnSort->TabIndex = 1;
			this->btnSort->Text = L"Sort";
			this->btnSort->UseVisualStyleBackColor = true;
			this->btnSort->Click += gcnew System::EventHandler(this, &InputForm::OnSortClick);
			// 
			// InputForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1120, 773);
			this->Controls->Add(this->txtInput);
			this->Controls->Add(this->btnSort);
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"InputForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"SortLab";
			this->Load += gcnew System::EventHandler(this, &InputForm::InputForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private:
		System::Void OnSortClick(System::Object^ sender, System::EventArgs^ e)
		{
			ResultForm^ result = gcnew ResultForm();
			result->Show();
			this->Hide();
		}
	private: System::Void InputForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
