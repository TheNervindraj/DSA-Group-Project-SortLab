#pragma once
#include <vector>
#include <algorithm>

namespace DSAGroupProjectSortLab {

	using namespace System;
	using namespace System::Windows::Forms;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;

	public ref class ResultForm : public Form
	{
	private:
		List<int>^ originalNumbers;
		List<List<int>^>^ mergeSortSteps;
		List<List<int>^>^ bubbleSortSteps;
		int currentStep;
		int bubbleCurrentStep;
		Timer^ animationTimer;
		Timer^ bubbleAnimationTimer;
		int bubbleSortStepCount;
		int mergeSortStepCount;

		Label^ lblBubble;
		Label^ lblMerge;
		PictureBox^ bubbleBox;
		PictureBox^ mergeBox;
		DataGridView^ grid;
		Button^ btnRetry;
		Button^ btnExit;
		Label^ lblNumbers;
		DataGridViewTextBoxColumn^ colWorkPrinc;
		DataGridViewTextBoxColumn^ colTimeComp;
		DataGridViewTextBoxColumn^ colSpaceComp;
		DataGridViewTextBoxColumn^ colSteps;
		System::ComponentModel::IContainer^ components;

	public:
		
		ResultForm()
		{
			InitializeComponent();
			this->StartPosition = FormStartPosition::CenterScreen;
		}

		ResultForm(String^ inputNumbers);

		void ParseInputNumbers(String^ inputNumbers);
		void StartBubbleSortVisualization();
		void StartMergeSortVisualization();
		void BubbleSort(List<int>^ arr);
		void MergeSort(List<int>^ arr, int left, int right);
		void Merge(List<int>^ arr, int left, int mid, int right);
		void OnBubbleAnimationTick(Object^ sender, EventArgs^ e);
		void OnAnimationTick(Object^ sender, EventArgs^ e);
		void DrawBubbleSortStep(List<int>^ numbers);
		void DrawMergeSortStep(List<int>^ numbers);
		void PopulateComparisonGrid();
		System::Void OnRetryClick(System::Object^ sender, System::EventArgs^ e);
		System::Void OnExitClick(System::Object^ sender, System::EventArgs^ e);

	protected:
		~ResultForm()
		{
			if (components)
			{
				delete components;
			}
		}

#pragma region Windows Form Designer generated code
		void InitializeComponent(void);
#pragma endregion
	};

} // namespace
