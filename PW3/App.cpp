#include "App.h"
#include "MainFrame.h"
#include <wx/wx.h>


wxIMPLEMENT_APP(App);
bool App::OnInit()
{
	MainFrame* frame = new MainFrame("wxWidgets Program-of-the-Week 5");
	frame->Show(true);
	return true;
}
