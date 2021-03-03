#include "formHome.h"
#include "formGame.h"
#include "formAuthor.h"

using namespace kursarkanoid;

void CloseWindow(Object^ sender, FormClosedEventArgs^ e)
{
	if (Application::OpenForms->Count == 0)
	{
		Application::Exit();
	}
	else
	{
		Application::OpenForms[0]->FormClosed += gcnew FormClosedEventHandler(CloseWindow);
	}
}

[STAThreadAttribute]

int main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	
	formHome^ home = gcnew formHome();
	home->FormClosed += gcnew FormClosedEventHandler(CloseWindow);
	home->Show();




	Application::Run();

	return 0;
}