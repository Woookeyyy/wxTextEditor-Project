#include "MainFrame.h"
#include <wx/menu.h>
#include <wx/wx.h>
#include <wx/datetime.h>
#include <wx/file.h>
#include <wx/textfile.h>
#include <fstream>
#include "LoadFile.h"
#include "OpenFile.h"
#include "SaveFile.h"
#include "SaveText.h"

enum {
	ID_TEXTBOX = 2,
	ID_MENU_OPEN,
	ID_MENU_SAVE
};

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
EVT_MENU(ID_MENU_OPEN, MainFrame::OnOpenFile)
EVT_MENU(ID_MENU_SAVE, MainFrame::OnSaveFile)
wxEND_EVENT_TABLE()

MainFrame::MainFrame(const wxString& title) : wxFrame(NULL, wxID_ANY, title)
{
	
	// Create a menu bar
	wxMenuBar* menuBar = new wxMenuBar;

	// Create a file menu
	wxMenu* fileMenu = new wxMenu;

	// Create a menu item
	fileMenu->Append(ID_MENU_OPEN, "&Open\tCtrl+0", "Open a text file");
	fileMenu->Append(ID_MENU_SAVE, "&Save\tCtrl+S", "Open a text file");


	// Add fileMenu to menuBar
	menuBar->Append(fileMenu, "&File");
	// Set the menu bar
	SetMenuBar(menuBar);

	

	// Create text control
	wxTextCtrl* text = new wxTextCtrl(this, ID_TEXTBOX, "", wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE | wxTE_RICH, wxDefaultValidator, wxTextCtrlNameStr);

	// Add status bar
	CreateStatusBar();
	// SetStatus to Time and Date

	// Set status text to current time and date
	SetStatusText(wxDateTime::Now().Format());

}
