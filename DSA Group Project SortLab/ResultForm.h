#pragma once

namespace DSAGroupProjectSortLab {

	using namespace System;
	using namespace System::Windows::Forms;
	using namespace System::Drawing;

	public ref class ResultForm : public System::Windows::Forms::Form
	{
	public:
		ResultForm(String^ inputNumbers)
		{
			InitializeComponent();
			lblNumbers->Text = "Entered Numbers: " + inputNumbers;
		}

	private:
		System::Windows::Forms::Label^ lblBubble;
		System::Windows::Forms::Label^ lblMerge;
		System::Windows::Forms::PictureBox^ bubbleBox;
		System::Windows::Forms::PictureBox^ mergeBox;
		System::Windows::Forms::DataGridView^ grid;
		System::Windows::Forms::Button^ btnRetry;
		System::Windows::Forms::Button^ btnExit;
		System::Windows::Forms::Label^ lblNumbers;






	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colWorkPrinc;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colTimeComp;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colSpaceComp;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colSteps;
	private: System::ComponentModel::IContainer^ components;



		   void InitializeComponent(void)
		   {
			   System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ResultForm::typeid));
			   this->lblBubble = (gcnew System::Windows::Forms::Label());
			   this->lblMerge = (gcnew System::Windows::Forms::Label());
			   this->bubbleBox = (gcnew System::Windows::Forms::PictureBox());
			   this->mergeBox = (gcnew System::Windows::Forms::PictureBox());
			   this->grid = (gcnew System::Windows::Forms::DataGridView());
			   this->btnRetry = (gcnew System::Windows::Forms::Button());
			   this->btnExit = (gcnew System::Windows::Forms::Button());
			   this->lblNumbers = (gcnew System::Windows::Forms::Label());
			   this->colWorkPrinc = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->colTimeComp = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->colSpaceComp = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->colSteps = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bubbleBox))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->mergeBox))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->grid))->BeginInit();
			   this->SuspendLayout();
			   // 
			   // lblBubble
			   // 
			   this->lblBubble->AutoSize = true;
			   this->lblBubble->BackColor = System::Drawing::Color::Transparent;
			   this->lblBubble->Font = (gcnew System::Drawing::Font(L"Perpetua Titling MT", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->lblBubble->ForeColor = System::Drawing::Color::Pink;
			   this->lblBubble->Location = System::Drawing::Point(206, 34);
			   this->lblBubble->Name = L"lblBubble";
			   this->lblBubble->Size = System::Drawing::Size(209, 23);
			   this->lblBubble->TabIndex = 0;
			   this->lblBubble->Text = L"Bubble Sort [O(n²)]";
			   // 
			   // lblMerge
			   // 
			   this->lblMerge->AutoSize = true;
			   this->lblMerge->BackColor = System::Drawing::Color::Transparent;
			   this->lblMerge->Font = (gcnew System::Drawing::Font(L"Perpetua Titling MT", 10));
			   this->lblMerge->ForeColor = System::Drawing::Color::Pink;
			   this->lblMerge->Location = System::Drawing::Point(638, 34);
			   this->lblMerge->Name = L"lblMerge";
			   this->lblMerge->Size = System::Drawing::Size(272, 23);
			   this->lblMerge->TabIndex = 1;
			   this->lblMerge->Text = L"Merge Sort [O(n log n)]";
			   // 
			   // bubbleBox
			   // 
			   this->bubbleBox->BackColor = System::Drawing::Color::LightGray;
			   this->bubbleBox->Location = System::Drawing::Point(210, 60);
			   this->bubbleBox->Name = L"bubbleBox";
			   this->bubbleBox->Size = System::Drawing::Size(274, 226);
			   this->bubbleBox->TabIndex = 2;
			   this->bubbleBox->TabStop = false;
			   // 
			   // mergeBox
			   // 
			   this->mergeBox->BackColor = System::Drawing::Color::LightGray;
			   this->mergeBox->Location = System::Drawing::Point(636, 60);
			   this->mergeBox->Name = L"mergeBox";
			   this->mergeBox->Size = System::Drawing::Size(274, 226);
			   this->mergeBox->TabIndex = 3;
			   this->mergeBox->TabStop = false;
			   // 
			   // grid
			   // 
			   this->grid->AllowUserToAddRows = false;
			   this->grid->AllowUserToDeleteRows = false;
			   this->grid->AllowUserToOrderColumns = true;
			   this->grid->AllowUserToResizeColumns = false;
			   this->grid->AllowUserToResizeRows = false;
			   this->grid->ColumnHeadersHeight = 34;
			   this->grid->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				   this->colWorkPrinc, this->colTimeComp,
					   this->colSpaceComp, this->colSteps
			   });
			   this->grid->Location = System::Drawing::Point(210, 355);
			   this->grid->Name = L"grid";
			   this->grid->ReadOnly = true;
			   this->grid->RowHeadersWidth = 97;
			   this->grid->Size = System::Drawing::Size(700, 179);
			   this->grid->TabIndex = 4;
			   // 
			   // btnRetry
			   // 
			   this->btnRetry->BackColor = System::Drawing::Color::Green;
			   this->btnRetry->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->btnRetry->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			   this->btnRetry->Location = System::Drawing::Point(210, 616);
			   this->btnRetry->Name = L"btnRetry";
			   this->btnRetry->Size = System::Drawing::Size(274, 89);
			   this->btnRetry->TabIndex = 5;
			   this->btnRetry->Text = L"Retry";
			   this->btnRetry->UseVisualStyleBackColor = false;
			   this->btnRetry->Click += gcnew System::EventHandler(this, &ResultForm::OnRetryClick);
			   // 
			   // btnExit
			   // 
			   this->btnExit->BackColor = System::Drawing::Color::DarkRed;
			   this->btnExit->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->btnExit->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			   this->btnExit->Location = System::Drawing::Point(636, 616);
			   this->btnExit->Name = L"btnExit";
			   this->btnExit->Size = System::Drawing::Size(274, 89);
			   this->btnExit->TabIndex = 6;
			   this->btnExit->Text = L"Exit";
			   this->btnExit->UseVisualStyleBackColor = false;
			   this->btnExit->Click += gcnew System::EventHandler(this, &ResultForm::OnExitClick);
			   // 
			   // lblNumbers
			   // 
			   this->lblNumbers->AutoSize = true;
			   this->lblNumbers->BackColor = System::Drawing::Color::Transparent;
			   this->lblNumbers->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11));
			   this->lblNumbers->ForeColor = System::Drawing::Color::SpringGreen;
			   this->lblNumbers->Location = System::Drawing::Point(205, 311);
			   this->lblNumbers->Name = L"lblNumbers";
			   this->lblNumbers->Size = System::Drawing::Size(194, 30);
			   this->lblNumbers->TabIndex = 7;
			   this->lblNumbers->Text = L"Entered Numbers: ";
			   // 
			   // colWorkPrinc
			   // 
			   this->colWorkPrinc->HeaderText = L"Working Principle";
			   this->colWorkPrinc->MinimumWidth = 8;
			   this->colWorkPrinc->Name = L"colWorkPrinc";
			   this->colWorkPrinc->ReadOnly = true;
			   this->colWorkPrinc->Width = 150;
			   // 
			   // colTimeComp
			   // 
			   this->colTimeComp->HeaderText = L"Time Complexity";
			   this->colTimeComp->MinimumWidth = 8;
			   this->colTimeComp->Name = L"colTimeComp";
			   this->colTimeComp->ReadOnly = true;
			   this->colTimeComp->Width = 150;
			   // 
			   // colSpaceComp
			   // 
			   this->colSpaceComp->HeaderText = L"Space Complexity";
			   this->colSpaceComp->MinimumWidth = 8;
			   this->colSpaceComp->Name = L"colSpaceComp";
			   this->colSpaceComp->ReadOnly = true;
			   this->colSpaceComp->Width = 150;
			   // 
			   // colSteps
			   // 
			   this->colSteps->HeaderText = L"Number of Steps";
			   this->colSteps->MinimumWidth = 8;
			   this->colSteps->Name = L"colSteps";
			   this->colSteps->ReadOnly = true;
			   this->colSteps->Width = 150;
			   // 
			   // ResultForm
			   // 
			   this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			   this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->ClientSize = System::Drawing::Size(1120, 773);
			   this->Controls->Add(this->lblBubble);
			   this->Controls->Add(this->lblMerge);
			   this->Controls->Add(this->bubbleBox);
			   this->Controls->Add(this->mergeBox);
			   this->Controls->Add(this->grid);
			   this->Controls->Add(this->btnRetry);
			   this->Controls->Add(this->btnExit);
			   this->Controls->Add(this->lblNumbers);
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

		   System::Void ResultForm_Load(System::Object^ sender, System::EventArgs^ e) {}

		   void DisplayNumbers(String^ inputNumbers)
		   {
			   this->lblNumbers->Text = "Entered Numbers: " + inputNumbers;
		   }
	
};
}
