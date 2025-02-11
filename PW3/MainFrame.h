#pragma once
#include <wx/wx.h>

class MainFrame : public wxFrame
{
public:
	MainFrame(const wxString& title);
	


private:
	// Event handler for the "Open" menu item
	void OnOpenFile(wxCommandEvent& event);

	// Event handler for the "Save" menu item
	void OnSaveFile(wxCommandEvent& event);

	// Function to load a file into the text control
	void SaveTextCtrlContentsToFile(const wxString& filePath);

	

	// Event table
	wxDECLARE_EVENT_TABLE();

	// Function to load a file into the text control
	void LoadFileIntoTextCtrl(const wxString& filePath);

	// Text control
	wxTextCtrl* textCtrl;
};

