#include <QApplication>

#include "researcherwindow.h"
#include "Service.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    Repo repo;
    Service service(repo);

    auto researchers = service.getAllResearchersService();
    auto ideas = service.getAllIdeasService();

    std::vector<researcherWindow *> windows;
    for (const auto &researcher: researchers) {
        auto *win = new researcherWindow(researcher, service);
        win->show();
        windows.push_back(win);
    }

    for (researcherWindow *sender: windows) {
        for (researcherWindow *receiver: windows) {
            QObject::connect(sender, &researcherWindow::ideaAdded, receiver, &researcherWindow::loadData);
        }
    }

    auto code = a.exec();
    return code;
}
