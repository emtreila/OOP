#include "ChartWindow.h"
#include <QPainter>
#include <QPaintEvent>
#include <QFont>
#include <algorithm>

ChartWindow::ChartWindow(Service& service, QWidget* parent)
    : QWidget(parent) {
    const auto& coats = service.getAllService();
    for (const auto& coat : coats) {
        QString size = QString::fromStdString(coat.getSize());
        sizeData[size] += coat.getQuantity(); // sum by size
    }

    setWindowTitle("Trench Coats per Size");
    resize(600, 400);
}

void ChartWindow::paintEvent(QPaintEvent*) {
    QPainter painter(this);

    int margin = 50;
    int width = this->width() - 2 * margin;
    int height = this->height() - 2 * margin;
    // by dividing the available width by the number of unique sizes
    int barWidth = width / std::max(1, static_cast<int>(sizeData.size())); // calculates the width of each bar in the chart

    int maxValue = 0;
    // find the maximum value for scaling the bar heights
    for (auto count : sizeData.values()) {
        maxValue = std::max(maxValue, count);
    }

    int i = 0;
    for (auto it = sizeData.begin(); it != sizeData.end(); ++it, ++i) {
        // it = iterator pointing to the current (size, quantity) pair
        // i = index of the current bar

        int x = margin + i * barWidth; // x = position where the current bar will be drawn
        int barHeight = 0;

        if (maxValue > 0) {
            // calculate the fraction of the max value that the current value represents
            double valueFraction = static_cast<double>(it.value()) / maxValue;
            // scale the fraction by the maximum drawable height to get the bar height in pixels
            barHeight = static_cast<int>(valueFraction * height);
        }
        int y = this->height() - margin - barHeight; // y = position where the current bar will be drawn

        painter.setBrush(Qt::blue);
        painter.drawRect(x, y, barWidth - 10, barHeight);

        painter.setPen(Qt::black);
        painter.drawText(x + 5, this->height() - margin + 15, it.key());

        painter.drawText(x + 5, y - 5, QString::number(it.value()));
    }

    painter.drawLine(margin, margin, margin, this->height() - margin); // Y
    painter.drawLine(margin, this->height() - margin, this->width() - margin, this->height() - margin); // X
}
