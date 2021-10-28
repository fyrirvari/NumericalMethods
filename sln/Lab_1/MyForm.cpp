#include "MyForm.h"
#include <Windows.h>

//using namespace NumericalMethods;
using namespace System;
using namespace System::Windows::Forms;


int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);


	NumericalMethods::MyForm form;
	Application::Run(% form);

	return 0;
}
