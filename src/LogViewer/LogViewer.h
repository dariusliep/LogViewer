#pragma once
#include <wx/app.h>

class LogViewer : public wxApp
{
public:
    LogViewer();
    ~LogViewer();

    virtual bool OnInit();
};