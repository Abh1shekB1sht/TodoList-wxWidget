#include "App.h"
#include "MainFrame.h"

wxIMPLEMENT_APP(App);

bool App::OnInit()
{
	MainFrame* mainFrame = new MainFrame("Todo List");
	mainFrame->SetSize(800, 600);
	mainFrame->Center();
	mainFrame->Show(true);
	return true;
}


