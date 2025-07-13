#include "VisualView.h"
#include <QPainter>
#include <map>

VisualView::VisualView(const Biologist& bio, Service& srv, QWidget* parent)
    : QWidget(parent), service(srv), biologist(bio) {
}

void VisualView::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    QFont font("Arial", 10);
    painter.setFont(font);

    std::map<std::string, std::vector<std::string>> grouped;
    for (const auto &b : service.getBacteriaByBiologistSpecies(biologist.getName())) {
        grouped[b.getSpecies()].push_back(b.getName());
    }

    int y = 30;
    for (const auto &[species, bacterias] : grouped) {
        painter.drawText(20, y, QString::fromStdString(species));
        y += 20;

        int x = 40;
        for (const auto &name : bacterias) {
            painter.drawEllipse(x, y, 20, 20);
            x += 30;
        }

        y += 40;
    }
}