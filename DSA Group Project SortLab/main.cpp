#include "MainForm.h"  // 

using namespace System;
using namespace System::Windows::Forms;
using namespace DSAGroupProjectSortLab;

[STAThreadAttribute]
int main(array<System::String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew MainForm());
    return 0;
}
