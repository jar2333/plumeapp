#pragma once

#include <wx/wx.h>

class App : public wxApp {
    private:
        wxFrame *frame;

    public:
        virtual bool OnInit() override;
};