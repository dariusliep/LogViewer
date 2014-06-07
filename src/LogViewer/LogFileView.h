#pragma once
#include <wx/listctrl.h>

namespace DLLogViewer
{
    class LogFileView : public wxListCtrl
    {
    public:
        LogFileView(wxWindow *parent,
            const wxWindowID id,
            const wxPoint& pos,
            const wxSize& size,
            long style);
        virtual ~LogFileView();


        virtual wxString OnGetItemText(long item, long column) const;


        wxDECLARE_NO_COPY_CLASS(LogFileView);
        DECLARE_EVENT_TABLE()
    };
}
