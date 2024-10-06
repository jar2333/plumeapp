#include <libMultiMarkdown.h>

#include <MainFrame.hpp>
#include <App.hpp>


wxIMPLEMENT_APP(App);

bool App::OnInit() {
    frame = new MainFrame("Hello Everyone!", wxDefaultPosition, wxDefaultSize);
    frame->Show(true);
    return true;
}