#include "ResultForm.h"

namespace DSAGroupProjectSortLab {

	ResultForm::ResultForm(String^ inputNumbers)
	{
		InitializeComponent();
		this->StartPosition = FormStartPosition::CenterScreen;
		this->grid->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;


		lblNumbers->Text = "Entered Numbers: " + inputNumbers;
		ParseInputNumbers(inputNumbers);

		animationTimer = gcnew Timer();
		animationTimer->Interval = 1000;
		animationTimer->Tick += gcnew EventHandler(this, &ResultForm::OnAnimationTick);

		bubbleAnimationTimer = gcnew Timer();
		bubbleAnimationTimer->Interval = 800;
		bubbleAnimationTimer->Tick += gcnew EventHandler(this, &ResultForm::OnBubbleAnimationTick);

		StartBubbleSortVisualization();
		StartMergeSortVisualization();
		PopulateComparisonGrid();
	}

	void ResultForm::ParseInputNumbers(String^ inputNumbers) {
		originalNumbers = gcnew List<int>();
		array<String^>^ parts = inputNumbers->Split(',');
		for each(String ^ part in parts) {
			int num;
			if (Int32::TryParse(part->Trim(), num)) {
				originalNumbers->Add(num);
			}
		}
	}

	void ResultForm::StartBubbleSortVisualization() {
		List<int>^ temp = gcnew List<int>(originalNumbers);
		bubbleSortSteps = gcnew List<List<int>^>();
		BubbleSort(temp);
		bubbleCurrentStep = 0;
		bubbleAnimationTimer->Start();
	}

	void ResultForm::StartMergeSortVisualization() {
		List<int>^ temp = gcnew List<int>(originalNumbers);
		mergeSortSteps = gcnew List<List<int>^>();
		MergeSort(temp, 0, temp->Count - 1);
		currentStep = 0;
		animationTimer->Start();
	}

	void ResultForm::BubbleSort(List<int>^ arr) {
		bubbleSortSteps->Add(gcnew List<int>(arr));
		int n = arr->Count;
		bubbleSortStepCount = 0;
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < n - i - 1; j++) {
				if (arr[j] > arr[j + 1]) {
					int temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
					bubbleSortSteps->Add(gcnew List<int>(arr));
					bubbleSortStepCount++;
				}
			}
		}
	}

	void ResultForm::MergeSort(List<int>^ arr, int left, int right) {
		if (left >= right) return;
		int mid = (left + right) / 2;
		MergeSort(arr, left, mid);
		MergeSort(arr, mid + 1, right);
		Merge(arr, left, mid, right);
	}

	void ResultForm::Merge(List<int>^ arr, int left, int mid, int right) {
		List<int>^ temp = gcnew List<int>();
		int i = left, j = mid + 1;
		while (i <= mid && j <= right) {
			if (arr[i] <= arr[j]) temp->Add(arr[i++]);
			else temp->Add(arr[j++]);
		}
		while (i <= mid) temp->Add(arr[i++]);
		while (j <= right) temp->Add(arr[j++]);
		for (int k = 0; k < temp->Count; ++k)
			arr[left + k] = temp[k];
		mergeSortSteps->Add(gcnew List<int>(arr));
		mergeSortStepCount++;
	}

	void ResultForm::OnBubbleAnimationTick(Object^ sender, EventArgs^ e) {
		if (bubbleCurrentStep < bubbleSortSteps->Count) {
			DrawBubbleSortStep(bubbleSortSteps[bubbleCurrentStep++]);
		}
		else {
			bubbleAnimationTimer->Stop();
		}
	}

	void ResultForm::OnAnimationTick(Object^ sender, EventArgs^ e) {
		if (currentStep < mergeSortSteps->Count) {
			DrawMergeSortStep(mergeSortSteps[currentStep++]);
		}
		else {
			animationTimer->Stop();
		}
	}

	void ResultForm::DrawBubbleSortStep(List<int>^ numbers) {
		Bitmap^ bmp = gcnew Bitmap(bubbleBox->Width, bubbleBox->Height);
		Graphics^ g = Graphics::FromImage(bmp);
		int barWidth = bmp->Width / numbers->Count;
		for (int i = 0; i < numbers->Count; i++) {
			int height = numbers[i] * 2;
			g->FillRectangle(Brushes::GreenYellow, i * barWidth, bmp->Height - height, barWidth - 2, height);
		}
		bubbleBox->Image = bmp;
	}

	void ResultForm::DrawMergeSortStep(List<int>^ numbers) {
		Bitmap^ bmp = gcnew Bitmap(mergeBox->Width, mergeBox->Height);
		Graphics^ g = Graphics::FromImage(bmp);
		int barWidth = bmp->Width / numbers->Count;
		for (int i = 0; i < numbers->Count; i++) {
			int height = numbers[i] * 2;
			g->FillRectangle(Brushes::DarkOrange, i * barWidth, bmp->Height - height, barWidth - 2, height);
		}
		mergeBox->Image = bmp;
	}

	void ResultForm::PopulateComparisonGrid() {
		grid->Rows->Add("Bubble Sort", "O(n²)", "O(1)", bubbleSortStepCount.ToString());
		grid->Rows->Add("Merge Sort", "O(n log n)", "O(n)", mergeSortStepCount.ToString());
	}

	System::Void ResultForm::OnRetryClick(System::Object^ sender, System::EventArgs^ e) {
		Application::Restart();
	}

	System::Void ResultForm::OnExitClick(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit();
	}

}
void DSAGroupProjectSortLab::ResultForm::InitializeComponent(void)
{
	this->components = gcnew System::ComponentModel::Container();

	this->lblBubble = gcnew Label();
	this->lblMerge = gcnew Label();
	this->bubbleBox = gcnew PictureBox();
	this->mergeBox = gcnew PictureBox();
	this->grid = gcnew DataGridView();
	this->btnRetry = gcnew Button();
	this->btnExit = gcnew Button();
	this->lblNumbers = gcnew Label();
	this->colWorkPrinc = gcnew DataGridViewTextBoxColumn();
	this->colTimeComp = gcnew DataGridViewTextBoxColumn();
	this->colSpaceComp = gcnew DataGridViewTextBoxColumn();
	this->colSteps = gcnew DataGridViewTextBoxColumn();

	this->SuspendLayout();

	// Form settings
	this->Text = "Result Visualization";
	this->ClientSize = Drawing::Size(1120, 773);
	this->StartPosition = FormStartPosition::CenterScreen;

	this->BackgroundImage = Image::FromFile("resultform.jpeg");
	this->BackgroundImageLayout = ImageLayout::Stretch;


	// Labels
	this->lblBubble->Location = Point(262, 30);
	this->lblBubble->Text = "Bubble Sort [O(n²)]";
	this->lblBubble->AutoSize = true;
	this->lblBubble->ForeColor = Color::GreenYellow;
	this->lblBubble->Font = gcnew Drawing::Font("Segoe UI", 12, FontStyle::Bold);
	this->lblMerge->ForeColor = Color::DarkOrange;
	this->lblMerge->Font = gcnew Drawing::Font("Segoe UI", 12, FontStyle::Bold);
	this->lblNumbers->ForeColor = Color::LightGreen;
	this->lblNumbers->Font = gcnew Drawing::Font("Segoe UI", 12, FontStyle::Bold);
	this->lblBubble->BackColor = Color::Transparent;
	this->lblMerge->BackColor = Color::Transparent;
	this->lblNumbers->BackColor = Color::Transparent;


	this->lblMerge->Location = Point(703, 30);
	this->lblMerge->Text = "Merge Sort [O(n log n)]";
	this->lblMerge->AutoSize = true;

	// PictureBoxes
	this->bubbleBox->BackColor = Color::LightGray;
	this->bubbleBox->Location = Point(210, 60);
	this->bubbleBox->Size = Drawing::Size(274, 226);

	this->mergeBox->BackColor = Color::LightGray;
	this->mergeBox->Location = Point(636, 60);
	this->mergeBox->Size = Drawing::Size(274, 226);

	// Grid
	this->grid->Location = Point(210, 460);
	this->grid->Size = Drawing::Size(700, 179);
	this->grid->ReadOnly = true;
	this->grid->AllowUserToAddRows = false;
	this->grid->AllowUserToDeleteRows = false;
	this->grid->ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode::AutoSize;
	this->grid->RowTemplate->Height = 78;
	this->grid->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
	this->grid->Columns->AddRange(gcnew cli::array<DataGridViewColumn^>{ colWorkPrinc, colTimeComp, colSpaceComp, colSteps });


	this->colWorkPrinc->HeaderText = "Sort Method";
	this->colTimeComp->HeaderText = "Time Complexity";
	this->colSpaceComp->HeaderText = "Space Complexity";
	this->colSteps->HeaderText = "Steps Taken";

	// Buttons
	this->btnRetry = gcnew Button();
	this->btnRetry->Text = "Retry";
	this->btnRetry->Location = Point(210, 660);
	this->btnRetry->Size = Drawing::Size(176, 89);
	this->btnRetry->Font = gcnew Drawing::Font("Segoe UI", 12, FontStyle::Bold);
	this->btnRetry->BackColor = Color::Green;
	this->btnRetry->ForeColor = Color::White;
	this->btnRetry->Click += gcnew EventHandler(this, &ResultForm::OnRetryClick);


	this->btnExit->Text = "Exit";
	this->btnExit->Location = Point(734, 660);
	this->btnExit->Size = Drawing::Size(176, 89);
	this->btnExit->Font = gcnew Drawing::Font("Segoe UI", 12, FontStyle::Bold);
	this->btnExit->BackColor = Color::Red;
	this->btnExit->ForeColor = Color::White;
	this->btnExit->Click += gcnew EventHandler(this, &ResultForm::OnExitClick);

	// Label for input
	this->lblNumbers->Location = Point(210, 410);
	this->lblNumbers->Font = gcnew Drawing::Font("Segoe UI", 11);
	this->lblNumbers->AutoSize = true;

	// Add controls
	this->Controls->Add(this->lblBubble);
	this->Controls->Add(this->lblMerge);
	this->Controls->Add(this->bubbleBox);
	this->Controls->Add(this->mergeBox);
	this->Controls->Add(this->grid);
	this->Controls->Add(this->btnRetry);
	this->Controls->Add(this->btnExit);
	this->Controls->Add(this->lblNumbers);

	this->ResumeLayout(false);
	this->PerformLayout();
}
