#include "doctorwindow.h"
#include "ui_doctorWindow.h"
#include <QMessageBox>

#include "PatientStatView.h"

doctorWindow::doctorWindow(const Doctor &doctor, Service &service, QWidget *parent) : QWidget(parent),
                                                                                      ui(new Ui::doctorWindow), service(service) {
    ui->setupUi(this);
    this->doctor = doctor;
    this->setWindowTitle(QString::fromStdString(doctor.getName()));
    loadData();

    connect(ui->patientsCheckBox, &QCheckBox::toggled, this, &doctorWindow::loadData);
    connect(ui->addPatientButton, &QPushButton::clicked, this, &doctorWindow::addPatient);
    connect(ui->viewButton, &QPushButton::clicked, this, &doctorWindow::openPatientView);
}

doctorWindow::~doctorWindow() {
    this->service.removeObserver(*this);
    delete ui;
}

void doctorWindow::update() {
    loadData();
}

void doctorWindow::loadData() {
    ui->patientList->clear();
    auto patients = this->service.getPatientsBySpecialization(this->doctor.getSpecialization());

    for (const auto &patient: patients) {
        if (ui->patientsCheckBox->isChecked() && patient.getSpecialization() != this->doctor.getSpecialization())
            continue;

        QListWidgetItem *item = new QListWidgetItem(QString::fromStdString(patient.toString()));
        if (patient.getCurrentDoctor() == this->doctor.getName())
            item->setBackground(Qt::green);
        ui->patientList->addItem(item);
    }
}

void doctorWindow::addPatient() {
    if (ui->nameLine->text().isEmpty() || ui->dateLine->text() < "2023-01-01") {
        QMessageBox::warning(this, "Input Error", "Invalid input.");
        return;
    }
    Patient newPatient;
    newPatient.setName(ui->nameLine->text().toStdString());
    newPatient.setDiagnosis(ui->diagnosisLine->text().toStdString());
    newPatient.setSpecialization(ui->specializationLine->text().toStdString());
    newPatient.setCurrentDoctor(ui->currentDoctorLine->text().toStdString());
    newPatient.setDate(ui->dateLine->text().toStdString());
    service.addPatient(newPatient);
}

void doctorWindow::openPatientView() {
    auto *win = new PatientStatView(this->service, nullptr);
    win->show();
}
