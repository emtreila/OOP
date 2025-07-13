#include "biologistwindow.h"
#include "ui_biologistWindow.h"
#include <QMessageBox>

#include "VisualView.h"

biologistWindow::biologistWindow(const Biologist &biologist, Service &service, QWidget *parent) : QWidget(parent),
    ui(new Ui::biologistWindow), service(service) {
    ui->setupUi(this);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);

    this->biologist = biologist;
    this->setWindowTitle(QString::fromStdString(biologist.getName()));

    model = new BacteriaTableModel(service, this, 1, biologist.getName());
    ui->tableView->setModel(model);

    std::vector<std::string> speciesList = service.splitSpecies(biologist.getSpecies());
    for (const auto &spec: speciesList)
        ui->speciesComboBox->addItem(QString::fromStdString(spec));

    connect(ui->speciesComboBox, &QComboBox::currentTextChanged,
            this, &biologistWindow::filterBySpecies);
    this->filterBySpecies();

    connect(ui->addButton, &QPushButton::clicked, this, &biologistWindow::addBacteria);
    connect(ui->tableView, &QTableView::clicked, this, &biologistWindow::showDisease);
    connect(ui->diseaseButton, &QPushButton::clicked, this, &biologistWindow::addDisease);
    connect(ui->viewButton, &QPushButton::clicked, this, &biologistWindow::openVisualView);

    loadData();
    ui->tableView->resizeColumnsToContents();
}

biologistWindow::~biologistWindow() {
    delete ui;
}

void biologistWindow::loadData() {
    model->refresh();
}

void biologistWindow::filterBySpecies() {
    QString selected = ui->speciesComboBox->currentText();
    std::string selectedSpecies = selected.toStdString();

    ui->listWidgetFiltered->clear();

    std::vector<Bacterium> all = service.getBacteriaByBiologistSpecies(biologist.getName());
    for (const auto &b: all) {
        if (b.getSpecies() == selectedSpecies) {
            ui->listWidgetFiltered->addItem(QString::fromStdString(b.getName()));
        }
    }
}

void biologistWindow::addBacteria() {
    Bacterium newBacterium;
    std::string name = ui->nameLine->text().toStdString();
    std::string species = ui->speciesLine->text().toStdString();
    for (const auto &b: service.getAllBacteriaService()) {
        if (b.getName() == name && b.getSpecies() == species) {
            QMessageBox::warning(this, "Input Error", "Bacterium with this name already exists.");
            return;
        }
    }
    newBacterium.setName(ui->nameLine->text().toStdString());
    newBacterium.setSpecies(ui->speciesLine->text().toStdString());
    newBacterium.setSize(ui->sizeLine->text().toInt());
    newBacterium.setDiseases(ui->diseasesLine->text().toStdString());
    this->service.addBacteria(newBacterium);
    emit bacteriaAdded();
}

void biologistWindow::showDisease(const QModelIndex &index) {
    if (!index.isValid())
        return;

    QString diseases = model->data(index.sibling(index.row(), 3), Qt::DisplayRole).toString();
    ui->diseaseList->clear();
    ui->diseaseList->addItems(diseases.split(","));
}

void biologistWindow::addDisease() {
    QString disease = ui->newDiseaseLine->text();
    ui->diseaseList->addItem(disease);
}

void biologistWindow::openVisualView() {
    auto *win = new VisualView(biologist, service);
    win->show();
}
