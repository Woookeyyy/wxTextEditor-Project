#pragma once
#include <wx/wx.h>
#include <wx/menu.h>
#include "MainFrame.h"
#include <wx/file.h>
#include <wx/textfile.h>


void MainFrame::LoadFileIntoTextCtrl(const wxString& filePath)
{
	// Open the file
    wxTextFile file;
    if (file.Open(filePath))
    {
        // Build a wxString containing the entire file contents
        wxString text;
        for (size_t i = 0; i < file.GetLineCount(); i++)
        {
            text += file.GetLine(i) + "\n";
        }

        // Now set the textCtrl's content to 'text'
        textCtrl->SetValue(text);
    }
    else
    {
        wxMessageBox("Could not open the file!", "Error", wxOK | wxICON_ERROR);
    }
}
