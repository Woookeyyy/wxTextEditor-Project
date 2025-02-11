#pragma once
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

void MainFrame::OnSaveFile(wxCommandEvent& event)
{
	//Create a file save dialog.
	//    The constructor arguments:
	//    - "Save text file" is the title
	//    - Default directory is "" (current folder)
	//    - Default filename is "" (nothing)
	//    - The wildcard "Text files (*.txt)|*.txt|All files (*.*)|*.*"
	//    - wxFD_SAVE means "save a file," and wxFD_OVERWRITE_PROMPT
	//      means "ask before overwriting"
	wxFileDialog saveFileDialog(this, _("Save a text file"), "", "", "Text files (*.txt)|*.txt", wxFD_SAVE | wxFD_OVERWRITE_PROMPT);
	// Actually show the dialog. If the user clicks OK, we proceed.
	if (saveFileDialog.ShowModal() == wxID_OK)
	{
		//The user picked a file and clicked OK.
		//    Let's grab the path to that file
		wxString filePath = saveFileDialog.GetPath();
		SaveTextCtrlContentsToFile(filePath);
	}
}