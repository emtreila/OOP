#include "personwindow.h"
#include "personwindow.h"
#include "ui_personwindow.h"
#include<QMessageBox>

personwindow::personwindow(Service &service, const Person &person, const std::vector<Event> &events,
                           QWidget *parent) : QWidget(parent), ui(new Ui::personwindow), service(service) {
    ui->setupUi(this);
    this->person = person;
    this->setWindowTitle(QString::fromStdString(person.getName()));
    ui->personLocationLine->setText(
        QString::fromStdString(person.getLocation(person.getLatitude(), person.getLongitude())));
    loadEventsData();
    service.addObserver(this);

    connect(ui->nearbyCheckBox, &QCheckBox::toggled, this, &personwindow::loadEventsData);
    if (!person.getStatus()) {
        ui->addButton->setDisabled(true);
        ui->nameLine->setDisabled(true);
        ui->dateLine->setDisabled(true);
        ui->latLine->setDisabled(true);
        ui->longLine->setDisabled(true);
        ui->descriptionLine->setDisabled(true);
    } else {
        connect(ui->addButton, &QPushButton::clicked, this, &personwindow::addEventGUI);
    }

    connect(ui->eventsList, &QListWidget::itemSelectionChanged, this, &personwindow::onEventSelected);
    connect(ui->goingButton, &QPushButton::clicked, this, &personwindow::onGoingClicked);
}

personwindow::~personwindow() {
    service.removeObserver(this);
    delete ui;
}

void personwindow::update() {
    loadEventsData();
}


void personwindow::loadEventsData() {
    ui->eventsList->clear();
    auto events = service.getAllEventsService();

    for (const auto &event: events) {
        double dx = event.getLatitude() - this->person.getLatitude();
        double dy = event.getLongitude() - this->person.getLongitude();
        double dist = std::sqrt(dx * dx + dy * dy);

        if (ui->nearbyCheckBox->isChecked() && dist > 5.0)
            continue;

        QListWidgetItem *item = new QListWidgetItem(QString::fromStdString(event.toString()));
        if (event.getOrganizer() == this->person.getName())
            item->setBackground(Qt::green);
        ui->eventsList->addItem(item);
    }
}

void personwindow::addEventGUI() {
    Event newEvent;
    newEvent.setOrganizer(this->person.getName());
    newEvent.setName(ui->nameLine->text().toStdString());
    newEvent.setDescription(ui->descriptionLine->text().toStdString());
    newEvent.setLatitude(ui->latLine->text().toDouble());
    newEvent.setLongitude(ui->longLine->text().toDouble());
    newEvent.setDate(ui->dateLine->text().toStdString());
    try {
        service.addEventService(newEvent);
        loadEventsData();
    } catch (const std::exception &e) {
        QMessageBox::warning(this, "Error", QString::fromStdString(e.what()));
    }
}

void personwindow::onEventSelected() const {
    int index = ui->eventsList->currentRow();
    if (index < 0) {
        return;
    }
    Event selected = service.getAllEventsService()[index];
    if (!person.getStatus()) {
        ui->textEdit->setText(QString::fromStdString(selected.getDescription()));
    }
}

void personwindow::onGoingClicked() const {
    int index = ui->eventsList->currentRow();
    if (index < 0) {
        return;
    }
    Event selected = service.getAllEventsService()[index];
    this->service.attendEventService(index, this->person.getName());
}
