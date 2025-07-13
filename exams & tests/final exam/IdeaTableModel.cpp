#include "IdeaTableModel.h"

IdeaTableModel::IdeaTableModel(Service &service, QObject *parent, const std::string &researcherName)
    : QAbstractTableModel(parent), service(service), researcherName(researcherName) {
    this->ideas = service.getAllIdeasService();
}

int IdeaTableModel::rowCount(const QModelIndex &) const {
    return static_cast<int>(this->ideas.size());
}

int IdeaTableModel::columnCount(const QModelIndex &) const {
    return 4;
}

QVariant IdeaTableModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid() || role != Qt::DisplayRole)
        return {};

    const Idea &idea = this->ideas.at(index.row());
    switch (index.column()) {
        case 0: return QString::fromStdString(idea.getTitle());
        case 1: return QString::fromStdString(idea.getStatus());
        case 2: return QString::fromStdString(idea.getCreator());
        case 3: return idea.getDuration();
        default: return {};
    }
}

QVariant IdeaTableModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role != Qt::DisplayRole || orientation != Qt::Horizontal)
        return {};

    switch (section) {
        case 0: return "Title";
        case 1: return "Status";
        case 2: return "Creator";
        case 3: return "Duration";
        default: return {};
    }
}

void IdeaTableModel::refresh() {
    beginResetModel();
    this->ideas = service.getAllIdeasService();
    endResetModel();
}
