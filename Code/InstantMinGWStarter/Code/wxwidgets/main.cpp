#include <wx/wx.h>

class MyApp : public wxApp
{
public:
	virtual ~MyApp() {}
	
private:
    virtual bool OnInit();
};

IMPLEMENT_APP(MyApp)

class MyDialog : public wxDialog
{
public:
    MyDialog(wxWindow* parent, wxWindowID id, const wxString& title) : wxDialog(parent, id, title) {}
	virtual ~MyDialog() {}
};

bool MyApp::OnInit()
{
	MyDialog* dialog = new MyDialog(NULL, 0, _("wxWidgets application"));
	
	wxSizer* sizer = dialog ->CreateButtonSizer(wxOK | wxCANCEL);
	sizer->SetDimension(175, 50, 100, 100);
	
    while ( dialog ->ShowModal() == wxID_OK  )
	{
	    wxMessageBox(_("Message text"), 
                     _("Information"),
					 wxOK | wxICON_INFORMATION, dialog);
	}
	
	dialog ->Destroy();
    return true;
}
