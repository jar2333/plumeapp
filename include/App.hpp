#pragma once

#include <wx/app.h>

class App : public wxApp {
    private:
        wxFrame *frame;

    public:
        virtual bool OnInit() override;
};