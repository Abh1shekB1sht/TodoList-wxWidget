#pragma once
#include <wx/wx.h>

class MainFrame : public wxFrame
{
public:
	MainFrame(const wxString& title);
private:
	// helper functions to create controls and bind event handlers
	void CreateControls();
	void BindEventHandlers();
	void AddSavedTasks();

	// event-handlers
	void OnAddButtonClicked(wxCommandEvent& evt);
	void OnInputEnter(wxCommandEvent& evt);
	void onListKeyDown(wxKeyEvent& evt);
	void OnClearButtonClicked(wxCommandEvent& evt);
	void onWindowClosed(wxCloseEvent& evt);

	// helper functions to add, delete, move and swap tasks
	void AddTaskFromInput();
	void DeleteSelectedTask();
	void MoveSelectedTask(int offset);
	void SwapTasks(int index1, int index2);

	// member variables for controls
	wxPanel* panel;
	wxStaticText* headlineText;
	wxTextCtrl* inputField;
	wxButton* addButton;
	wxCheckListBox* checkListBox;
	wxButton* clearButton;
};