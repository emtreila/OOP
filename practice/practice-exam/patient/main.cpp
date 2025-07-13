#include <QApplication>

#include "doctorwindow.h"
#include "Service.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    Repo repo;
    Service service(repo);

    auto doctors = service.getDoctors();
    auto patients = service.getPatients();


    std::vector<doctorWindow *> windows;
    for (const auto &doctor: doctors) {
        auto *win = new doctorWindow(doctor, service);
        service.addObserver(*win);
        win->show();
        windows.push_back(win);
    }

    auto code = a.exec();
    return code;
}
