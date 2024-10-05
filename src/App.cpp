#include <libMultiMarkdown.h>

#include <Frame.hpp>
#include <App.hpp>


wxIMPLEMENT_APP(App);

bool App::OnInit() {
    frame = new Frame("Hello Everyone!", wxDefaultPosition, wxDefaultSize);
    frame->Show(true);
    return true;
}