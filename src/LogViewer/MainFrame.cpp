#include "MainFrame.h"
#include "..\logger\logger.h"

using namespace DLLogViewer;

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
    EVT_MENU(ID_Hello, MainFrame::OnHello)
    EVT_MENU(wxID_EXIT, MainFrame::OnExit)
    EVT_MENU(wxID_ABOUT, MainFrame::OnAbout)
wxEND_EVENT_TABLE()

MainFrame::~MainFrame()
{
}

MainFrame::MainFrame(const wxString& title, int x, int y, int w, int h)
: wxFrame((wxFrame *)NULL, wxID_ANY, title, wxPoint(x, y), wxSize(w, h))
, m_pLogFileView(0)
{
    InitLogging("sample_%N.log");
    // This reduces flicker effects - even better would be to define
    // OnEraseBackground to do nothing. When the tree control's scrollbars are
    // show or hidden, the frame is sent a background erase event.
    SetBackgroundColour(*wxWHITE);

    wxMenu *menuFile = new wxMenu;
    menuFile->Append(ID_Hello, "&Hello...\tCtrl-H", "Help string shown in status bar for this menu item");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);

    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);

    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");
    SetMenuBar(menuBar);

    CreateStatusBar();
    SetStatusText("Welcome to LogViewer!");
    CreateLogFileView();
}

void MainFrame::OnExit(wxCommandEvent& /*event*/)
{
    Close(true);
}

void MainFrame::OnAbout(wxCommandEvent& /*event*/)
{
    wxMessageBox("LogViewer", "LogViewer", wxOK | wxICON_INFORMATION);
}

void MainFrame::OnHello(wxCommandEvent& /*event*/)
{
    wxMessageBox("Hello world from LogViewer!", "LogViewer", wxOK | wxICON_INFORMATION);
}

void MainFrame::CreateLogFileView()
{
    LOG(info) << " Creating log file view";
    if (m_pLogFileView)
    {
        delete m_pLogFileView;
        m_pLogFileView = 0;
    }

    m_pLogFileView = new LogFileView(this, ID_LOG_FILE_VIEW,
        wxDefaultPosition, wxDefaultSize,
        wxLC_REPORT | wxLC_VIRTUAL |
        wxBORDER_THEME | wxLC_EDIT_LABELS);

    m_pLogFileView->AppendColumn(wxT("First Column"));
    m_pLogFileView->AppendColumn(wxT("Second Column"));
    m_pLogFileView->SetColumnWidth(0, 150);
    m_pLogFileView->SetColumnWidth(1, 150);
    m_pLogFileView->SetItemCount(1000000);
}