#include "PatientStatView.h"
#include <QPainter>
#include <map>

PatientStatView::PatientStatView(Service& srv, QWidget* parent)
    : QWidget(parent), service(srv) {
    setWindowTitle("Patient Statistics");
    resize(600, 500);

}

void PatientStatView::paintEvent(QPaintEvent *event) {

    QPainter painter(this);
    QFont font("Arial", 10);
    painter.setFont(font);

    std::map<std::string, int> specCount;
    for (const auto& patient : service.getPatients()) {
        std::string spec = patient.getSpecialization();
        if (spec.empty()) spec = "undiagnosed";
        specCount[spec]++;
    }

    int y = 30;
    for (const auto& [spec, count] : specCount) {
        painter.drawText(20, y, QString::fromStdString(spec));
        int x = 40;
        y += 15;
        for (int i = 0; i < count; ++i) {
            painter.drawRect(x, y, 20, 20);
            x += 30;
        }
        y += 40;
    }
}
