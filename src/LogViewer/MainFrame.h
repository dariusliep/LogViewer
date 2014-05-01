#pragma once
// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif
#include "Defines.h"

namespace DLLogViewer
{
    class MainFrame : public wxFrame
    {
    public:
        // ctor and dtor
        MainFrame(const wxString& title, int x, int y, int w, int h);
        virtual ~MainFrame();

        void OnHello(wxCommandEvent& event);
        void OnExit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);

        wxDECLARE_EVENT_TABLE();
    };
}
