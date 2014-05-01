#include "LogViewer.h"
#include "MainFrame.h"

LogViewer::LogViewer()
{
}

LogViewer::~LogViewer()
{
}

IMPLEMENT_APP(LogViewer)

bool LogViewer::OnInit()
{
    if (!wxApp::OnInit())
        return false;

    // Create the main frame window
    DLLogViewer::MainFrame *frame = new DLLogViewer::MainFrame(wxT("LogViewer"), 50, 50, 450, 600);

    // Show the frame
    frame->Show(true);

    return true;
}