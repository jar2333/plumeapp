#include <wx/wx.h>
#include <libMultiMarkdown.h>

#include <App.hpp>
#include <Frame.hpp>

wxIMPLEMENT_APP(App);

bool App::OnInit() {
    Frame *frame = new Frame("Hello Everyone!", wxDefaultPosition, wxDefaultSize);
    frame->Show(true);
    return true;
}