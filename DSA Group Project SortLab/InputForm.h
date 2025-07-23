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
	private: System::Windows::Forms::Label^ lblEnterNum;

		   System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(InputForm::typeid));
			this->txtInput = (gcnew System::Windows::Forms::TextBox());
			this->btnSort = (gcnew System::Windows::Forms::Button());
			this->lblEnterNum = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// txtInput
			// 
			this->txtInput->ForeColor = System::Drawing::SystemColors::GrayText;
			this->txtInput->Location = System::Drawing::Point(360, 238);
			this->txtInput->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->txtInput->Multiline = true;
			this->txtInput->Name = L"txtInput";
			this->txtInput->Size = System::Drawing::Size(404, 95);
			this->txtInput->TabIndex = 0;
			this->txtInput->Text = L"Enter Number Here:";
			// 
			// btnSort
			// 
			this->btnSort->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->btnSort->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSort->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->btnSort->Location = System::Drawing::Point(360, 370);
			this->btnSort->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->btnSort->Name = L"btnSort";
			this->btnSort->Size = System::Drawing::Size(404, 185);
			this->btnSort->TabIndex = 1;
			this->btnSort->Text = L"Sort";
			this->btnSort->UseVisualStyleBackColor = false;
			this->btnSort->Click += gcnew System::EventHandler(this, &InputForm::OnSortClick);
			// 
			// lblEnterNum
			// 
			this->lblEnterNum->AutoSize = true;
			this->lblEnterNum->BackColor = System::Drawing::Color::Transparent;
			this->lblEnterNum->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblEnterNum->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->lblEnterNum->Location = System::Drawing::Point(356, 141);
			this->lblEnterNum->Name = L"lblEnterNum";
			this->lblEnterNum->Size = System::Drawing::Size(408, 46);
			this->lblEnterNum->TabIndex = 2;
			this->lblEnterNum->Text = L"Enter numbers separated by commas(,)\r\nFor Example: 1,2,3,4,5,6,7,8,9,10\r\n";
			// 
			// InputForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1120, 773);
			this->Controls->Add(this->lblEnterNum);
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
			String^ userInput = txtInput->Text;

			//slipt
			array<String^>^ parts = userInput->Split(',');

			//convert int
			System::Collections::Generic::List<int>^ numbers = gcnew System::Collections::Generic::List<int>();

			for each (String ^ part in parts)
			{
				int num;
				if (Int32::TryParse(part->Trim(), num))
				{
					numbers->Add(num);
				}
				else
				{
					MessageBox::Show("Invalid input: " + part, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return;
				}
			}

			//back to str
			array<String^>^ stringNumbers = gcnew array<String^>(numbers->Count);
			for (int i = 0; i < numbers->Count; i++)
			{
				stringNumbers[i] = numbers[i].ToString();
			}

			//join
			String^ inputNumbers = String::Join(", ", stringNumbers);

			//show result in RF
			ResultForm^ resultForm = gcnew ResultForm(inputNumbers);
			resultForm->Show();
			this->Hide();
		}
	private: System::Void InputForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}


///GIT TEST PUSH
