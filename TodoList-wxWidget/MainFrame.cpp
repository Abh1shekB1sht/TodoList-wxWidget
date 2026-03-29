#include "MainFrame.h"
#include <wx/wx.h>
#include <vector>
#include <string>
#include "Task.h"

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) 
{
	CreateControls();
	BindEventHandlers();
}

void MainFrame::CreateControls()
{
	wxFont headlineFont(wxFontInfo(wxSize(0, 36)).Bold());
	wxFont mainFont(wxFontInfo(wxSize(0, 24)));

	panel = new wxPanel(this);
	panel->SetFont(mainFont);

	headlineText = new wxStaticText(panel, wxID_ANY, "To-Do List", wxPoint(0, 22), wxSize(800, -1), wxALIGN_CENTER_HORIZONTAL);
	headlineText->SetFont(headlineFont);

	// added all the controls to the panel
	inputField = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(100, 80), wxSize(495, 35), wxTE_PROCESS_ENTER);
	addButton = new wxButton(panel, wxID_ANY, "Add", wxPoint(600, 80), wxSize(100, 35));
	checkListBox = new wxCheckListBox(panel, wxID_ANY, wxPoint(100, 120), wxSize(600, 400));
	clearButton = new wxButton(panel, wxID_ANY, "Clear", wxPoint(100, 525), wxSize(100, 35));
}

void MainFrame::BindEventHandlers()
{
	// binding the add button to the (click button) event handler 
	addButton->Bind(wxEVT_BUTTON, &MainFrame::OnAddButtonClicked, this);

	// binding the input field to the (press enter) event handler 
	inputField->Bind(wxEVT_TEXT_ENTER, &MainFrame::OnInputEnter, this);	

	// binding the check list box to the (press any key) event handler
	checkListBox->Bind(wxEVT_KEY_DOWN, &MainFrame::onListKeyDown, this);
}

void MainFrame::OnAddButtonClicked(wxCommandEvent& evt)
{
	AddTaskFromInput();
}

void MainFrame::OnInputEnter(wxCommandEvent& evt)
{
	AddTaskFromInput();
}

void MainFrame::onListKeyDown(wxKeyEvent& evt)
{
	// if the user presses the delete key, then we delete the selected task
	switch (evt.GetKeyCode()) {
		case WXK_DELETE:
			DeleteSelectedTask();
		break;
	}
}

void MainFrame::AddTaskFromInput()
{
	wxString description = inputField->GetValue();

	// if description not empty, then we insert it into the chechListBox
	if (!description.empty()) {
		checkListBox->Insert(description, checkListBox->GetCount());
		inputField->Clear();
	}

	// regain focus
	inputField->SetFocus();
}

void MainFrame::DeleteSelectedTask()
{
	// get the index of the selected task
	int selectedIndex = checkListBox->GetSelection();

	if (selectedIndex == wxNOT_FOUND) {
		return;
	}

	checkListBox->Delete(selectedIndex);
}

void MainFrame::MoveSelectedTask(int offset)
{

}

void MainFrame::SwapTasks(int index1, int index2)
{

}
