#pragma once

namespace DSAGroupProjectSortLab {

	using namespace System;
	using namespace System::Windows::Forms;
	using namespace System::Drawing;

	public ref class ResultForm : public System::Windows::Forms::Form
	{
	public:
		ResultForm()
		{
			InitializeComponent();
		}

	private:
		System::Windows::Forms::Label^ lblBubble;
		System::Windows::Forms::Label^ lblMerge;
		System::Windows::Forms::PictureBox^ bubbleBox;
		System::Windows::Forms::PictureBox^ mergeBox;
		System::Windows::Forms::DataGridView^ grid;
		System::Windows::Forms::Button^ btnRetry;
		System::Windows::Forms::Button^ btnExit;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colInput;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colSteps;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colTime;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colSpace;

		System::ComponentModel::Container^ components;

		void InitializeComponent(void)
		{
			this->lblBubble = (gcnew System::Windows::Forms::Label());
			this->lblMerge = (gcnew System::Windows::Forms::Label());
			this->bubbleBox = (gcnew System::Windows::Forms::PictureBox());
			this->mergeBox = (gcnew System::Windows::Forms::PictureBox());
			this->grid = (gcnew System::Windows::Forms::DataGridView());
			this->colInput = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colSteps = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colTime = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colSpace = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->btnRetry = (gcnew System::Windows::Forms::Button());
			this->btnExit = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bubbleBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->mergeBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->grid))->BeginInit();
			this->SuspendLayout();
			// 
			// lblBubble
			// 
			this->lblBubble->AutoSize = true;
			this->lblBubble->Location = System::Drawing::Point(100, 30);
			this->lblBubble->Name = L"lblBubble";
			this->lblBubble->Size = System::Drawing::Size(154, 20);
			this->lblBubble->TabIndex = 0;
			this->lblBubble->Text = L"Bubble Sort (O(n^2))";
			// 
			// lblMerge
			// 
			this->lblMerge->AutoSize = true;
			this->lblMerge->Location = System::Drawing::Point(500, 30);
			this->lblMerge->Name = L"lblMerge";
			this->lblMerge->Size = System::Drawing::Size(171, 20);
			this->lblMerge->TabIndex = 1;
			this->lblMerge->Text = L"Merge Sort (O(n log n))";
			// 
			// bubbleBox
			// 
			this->bubbleBox->BackColor = System::Drawing::Color::LightGray;
			this->bubbleBox->Location = System::Drawing::Point(80, 60);
			this->bubbleBox->Name = L"bubbleBox";
			this->bubbleBox->Size = System::Drawing::Size(200, 150);
			this->bubbleBox->TabIndex = 2;
			this->bubbleBox->TabStop = false;
			// 
			// mergeBox
			// 
			this->mergeBox->BackColor = System::Drawing::Color::LightGray;
			this->mergeBox->Location = System::Drawing::Point(480, 60);
			this->mergeBox->Name = L"mergeBox";
			this->mergeBox->Size = System::Drawing::Size(200, 150);
			this->mergeBox->TabIndex = 3;
			this->mergeBox->TabStop = false;
			// 
			// grid
			// 
			this->grid->AllowUserToAddRows = false;
			this->grid->AllowUserToDeleteRows = false;
			this->grid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->grid->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->colInput, this->colSteps,
					this->colTime, this->colSpace
			});
			this->grid->Location = System::Drawing::Point(50, 240);
			this->grid->Name = L"grid";
			this->grid->ReadOnly = true;
			this->grid->RowHeadersWidth = 62;
			this->grid->Size = System::Drawing::Size(700, 150);
			this->grid->TabIndex = 4;
			// 
			// colInput
			// 
			this->colInput->HeaderText = L"Input";
			this->colInput->MinimumWidth = 8;
			this->colInput->Name = L"colInput";
			this->colInput->ReadOnly = true;
			this->colInput->Width = 150;
			// 
			// colSteps
			// 
			this->colSteps->HeaderText = L"Steps";
			this->colSteps->MinimumWidth = 8;
			this->colSteps->Name = L"colSteps";
			this->colSteps->ReadOnly = true;
			this->colSteps->Width = 150;
			// 
			// colTime
			// 
			this->colTime->HeaderText = L"Time";
			this->colTime->MinimumWidth = 8;
			this->colTime->Name = L"colTime";
			this->colTime->ReadOnly = true;
			this->colTime->Width = 150;
			// 
			// colSpace
			// 
			this->colSpace->HeaderText = L"Space";
			this->colSpace->MinimumWidth = 8;
			this->colSpace->Name = L"colSpace";
			this->colSpace->ReadOnly = true;
			this->colSpace->Width = 150;
			// 
			// btnRetry
			// 
			this->btnRetry->Location = System::Drawing::Point(200, 450);
			this->btnRetry->Name = L"btnRetry";
			this->btnRetry->Size = System::Drawing::Size(75, 23);
			this->btnRetry->TabIndex = 5;
			this->btnRetry->Text = L"Retry";
			this->btnRetry->Click += gcnew System::EventHandler(this, &ResultForm::OnRetryClick);
			// 
			// btnExit
			// 
			this->btnExit->Location = System::Drawing::Point(400, 450);
			this->btnExit->Name = L"btnExit";
			this->btnExit->Size = System::Drawing::Size(75, 23);
			this->btnExit->TabIndex = 6;
			this->btnExit->Text = L"Exit";
			this->btnExit->Click += gcnew System::EventHandler(this, &ResultForm::OnExitClick);
			// 
			// ResultForm
			// 
			this->ClientSize = System::Drawing::Size(1120, 773);
			this->Controls->Add(this->lblBubble);
			this->Controls->Add(this->lblMerge);
			this->Controls->Add(this->bubbleBox);
			this->Controls->Add(this->mergeBox);
			this->Controls->Add(this->grid);
			this->Controls->Add(this->btnRetry);
			this->Controls->Add(this->btnExit);
			this->Name = L"ResultForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"SortLab";
			this->Load += gcnew System::EventHandler(this, &ResultForm::ResultForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bubbleBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->mergeBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->grid))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		System::Void OnRetryClick(System::Object^ sender, System::EventArgs^ e)
		{
			Application::Restart();
		}

		System::Void OnExitClick(System::Object^ sender, System::EventArgs^ e)
		{
			Application::Exit();
		}
	private: System::Void ResultForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
