#include "MainFrame.h"
#include <wx/menu.h>
#include <wx/wx.h>
#include <wx/datetime.h>

enum {
	ID_TEXTBOX = 2,
	ID_MENU_OPEN
};

MainFrame::MainFrame(const wxString& title) : wxFrame(NULL, wxID_ANY, title)
{
	// Create a panel
	//wxPanel* panel = new wxPanel(this);

	// Create a menu bar
	wxMenuBar* menuBar = new wxMenuBar;

	// Create a file menu
	wxMenu* fileMenu = new wxMenu;

	// Create a menu item
	fileMenu->Append(ID_MENU_OPEN, "&Open");

	// Add the file menu to the menu bar
	menuBar->Append(fileMenu, "&File");

	// Set the menu bar
	SetMenuBar(menuBar);

	// Create text control
	wxTextCtrl* text = new wxTextCtrl(this, ID_TEXTBOX, "", wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE | wxTE_RICH, wxDefaultValidator, wxTextCtrlNameStr);



	CreateStatusBar();
	// SetStatus to Time and Date


	SetStatusText(wxDateTime::Now().Format());



}
