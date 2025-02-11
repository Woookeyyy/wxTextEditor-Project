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


void MainFrame::SaveTextCtrlContentsToFile(const wxString& filePath)
{
    // Grab text from the text box as a wxString
    wxString textToSave = textCtrl->GetValue();

    // Convert it to a standard string if you like
    std::string stdText = textToSave.ToStdString();

    // Use std::ofstream to write the file
    std::ofstream outFile(filePath.ToStdString());
    if (!outFile.is_open())
    {
        // If we couldn’t open the file, show an error and bail out
        wxMessageBox("Could not save the file!", "Error", wxOK | wxICON_ERROR);
        return;
    }

    // 5) Write out the text
    outFile << stdText;

    // 6) Optionally, close the file (happens automatically at scope end)
    outFile.close();

    // 7) Maybe tell the user it was successful?
    wxMessageBox("File saved successfully!", "Save", wxOK | wxICON_INFORMATION);
}
