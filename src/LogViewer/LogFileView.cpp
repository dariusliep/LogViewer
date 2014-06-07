#include "LogFileView.h"

using namespace DLLogViewer;

BEGIN_EVENT_TABLE(LogFileView, wxListCtrl)

END_EVENT_TABLE()


LogFileView::LogFileView(wxWindow *parent,
    const wxWindowID id,
    const wxPoint& pos,
    const wxSize& size,
    long style)
    : wxListCtrl(parent, id, pos, size, style)
{
}


LogFileView::~LogFileView()
{
}

wxString LogFileView::OnGetItemText(long item, long column) const
{
    return wxString::Format(wxT("Column %ld of item %ld"), column, item);
}