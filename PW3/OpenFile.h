#pragma once
#include "MainFrame.h"
#include <wx/menu.h>
#include <wx/wx.h>
#include <wx/datetime.h>
#include <wx/file.h>
#include <wx/textfile.h>
#include <fstream>
#include "LoadFile.h"



void MainFrame::OnOpenFile(wxCommandEvent& event)
{

	//Create a file open dialog.
	//    The constructor arguments:
	//    - "Open text file" is the title
	//    - Default directory is "" (current folder)
	//    - Default filename is "" (nothing)
	//    - The wildcard "Text files (*.txt)|*.txt|All files (*.*)|*.*"
	//    - wxFD_OPEN means "open a file," and wxFD_FILE_MUST_EXIST
	//      means "must be an existing file"
	wxFileDialog openFileDialog(this, _("Open a text file"), "", "", "Text files (*.txt)|*.txt", wxFD_OPEN | wxFD_FILE_MUST_EXIST);

	// Actually show the dialog. If the user clicks OK, we proceed.
	if (openFileDialog.ShowModal() == wxID_OK)
	{
		//The user picked a file and clicked OK.
		//    Let's grab the path to that file
		wxString filePath = openFileDialog.GetPath();
		LoadFileIntoTextCtrl(filePath);

	}
}