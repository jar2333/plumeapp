#include <wx/stattext.h>

#include <Frame.hpp>

Frame::Frame(
    const wxString &title, 
    const wxPoint &pos, 
    const wxSize &size
) : wxFrame(NULL, wxID_ANY, title, pos, size) {
    // no need to delete - the parent will do it automatically
    new wxStaticText(this, wxID_ANY, "Good Morning!");
}
