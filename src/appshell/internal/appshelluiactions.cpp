#include "appshelluiactions.h"
#include "actions/dispatcher.h"
#include "interactive/internal/interactive.h"

#include <QApplication>
#include <QVariantMap>

using namespace gs::actions;
using namespace gs::interactive;
using namespace gs::appshell;

AppShellUiActions::AppShellUiActions()
{
    dispatcher()->reg(this, "about", [this](QVariantMap args) {this->about();});
    Interactive::instance()->regDialog("gslauncher://appshell/about", "AppShell/AboutDialog.qml");
}

void AppShellUiActions::about()
{
    Interactive::Params params;
    Interactive::instance()->openDialog("gslauncher://appshell/about", params);
}

void AppShellUiActions::aboutQt()
{
    qApp->aboutQt();
}
