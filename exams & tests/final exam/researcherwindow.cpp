#include "researcherwindow.h"
#include "IdeaTableModel.h"

researcherWindow::researcherWindow(const Researcher &researcher, Service &service, QWidget *parent) : QWidget(parent),
    ui(new Ui::researcherWindow),
    service(service) {
    ui->setupUi(this);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);


    this->researcher = researcher;
    this->setWindowTitle(QString::fromStdString(researcher.getName()));
    ui->positionLine->setText(QString::fromStdString(researcher.getPosition()));

    this->model = new IdeaTableModel(service, this);
    ui->tableView->setModel(this->model);
    loadData();
    ui->tableView->resizeColumnsToContents();

    connect(ui->addButton, &QPushButton::clicked, this, &researcherWindow::addIdea);

    if (this->researcher.getPosition() != "senior") {
        ui->saveButton->setEnabled(false);
        ui->approveButton->setEnabled(false);
    } else {
        ui->saveButton->setEnabled(true);
        ui->approveButton->setEnabled(true);
        connect(ui->approveButton, &QPushButton::clicked, this, &researcherWindow::approveIdea);
        connect(ui->saveButton, &QPushButton::clicked, this, &researcherWindow::saveAcceptedIdeas);
    }

    if (this->service.getIdeasWithStatusFoCreator("accepted", this->researcher.getName()).empty()) {
        ui->developButton->setEnabled(false);
    } else {
        ui->developButton->setEnabled(true);
        connect(ui->developButton, &QPushButton::clicked, this, &researcherWindow::developIdea);
    }

    if (ui->developButton->isEnabled()) {
        ui->saveEachIdeaButton->setEnabled(true);
        connect(ui->saveEachIdeaButton, &QPushButton::clicked, this, &researcherWindow::saveEachIdea);
    } else {
        ui->saveEachIdeaButton->setEnabled(false);
    }
}

researcherWindow::~researcherWindow() {
    delete ui;
}

void researcherWindow::loadData() {
    model->refresh();
}

void researcherWindow::addIdea() {
    Idea newIdea;
    if (ui->titleLine->text().isEmpty()) {
        QMessageBox::warning(this, "Error", "Title cannot be empty.");
        return;
    }
    int d = ui->durationLine->text().toInt();
    if (d < 1 || d > 3) {
        QMessageBox::warning(this, "Error", "Invalid duration.");
        return;
    }
    newIdea.setCreator(this->researcher.getName());
    newIdea.setDescription(ui->descrLine->text().toStdString());
    newIdea.setTitle(ui->titleLine->text().toStdString());
    newIdea.setStatus("proposed");
    this->service.addIdea(newIdea);
    emit ideaAdded();
}

void researcherWindow::approveIdea() {
    if (researcher.getPosition() == "senior") {
        auto selected = ui->tableView->selectionModel()->selectedRows();
        int row = selected.first().row();
        const Idea &idea = service.getAllIdeasService().at(row);
        if (idea.getStatus() == "proposed") {
            Idea updatedIdea = idea;
            updatedIdea.setStatus("accepted");
            service.updateIdea(updatedIdea);
            model->refresh();
        }
        emit ideaAdded();
    }
}

void researcherWindow::developIdea() {
    std::vector<Idea> accepted = this->service.getIdeasWithStatusFoCreator("accepted", this->researcher.getName());

    ui->acceptedList->clear();
    for (const auto &ideaAccepted: accepted) {
        QListWidgetItem *item = new QListWidgetItem(QString::fromStdString(ideaAccepted.toDevelopString()));
        ui->acceptedList->addItem(item);
    }
}

void researcherWindow::saveAcceptedIdeas() {
    std::vector<Idea> accepted = this->service.getIdeasWithStatusFoCreator("accepted", this->researcher.getName());

    std::ofstream file("accepted_ideas.txt");
    if (!file.is_open()) {
        throw std::runtime_error("Couldn't open file!");
    }
    for (const auto &idea: accepted) {
        file << idea.getTitle() << ";"
                << "(" << idea.getCreator() << ");"
                << idea.getDuration() <<
                idea.getDescription() << ";" << ";\n";
    }
}

void researcherWindow::saveEachIdea() {
    std::vector<Idea> accepted = this->service.getIdeasWithStatusFoCreator("accepted", this->researcher.getName());

    for (const auto &idea: accepted) {
        std::ofstream file(idea.getTitle());
        if (!file.is_open()) {
            throw std::runtime_error("Couldn't open file!");
        }
        file << idea.getTitle() << ";"
                << "(" << idea.getCreator() << ");"
                << idea.getDuration() << ";" <<
                idea.getDescription() << ";\n";
    }
}
