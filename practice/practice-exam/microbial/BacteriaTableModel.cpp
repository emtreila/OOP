#include "BacteriaTableModel.h"


BacteriaTableModel::BacteriaTableModel(Service &service, QObject *parent, int bacteriaFlag,
                                       const std::string &biologistName)
    : QAbstractTableModel(parent), service(service), bacteriaFlag(bacteriaFlag), biologistName(biologistName) {
    if (bacteriaFlag == 1 && !biologistName.empty()) {
        this->bacteria = service.getBacteriaByBiologistSpecies(biologistName);
    } else {
        this->bacteria = service.getAllBacteriaService();
    }
}

int BacteriaTableModel::rowCount(const QModelIndex &) const {
    return static_cast<int>(this->bacteria.size());
}

int BacteriaTableModel::columnCount(const QModelIndex &) const {
    return 4;
}

QVariant BacteriaTableModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid() || role != Qt::DisplayRole)
        return {};

    const Bacterium &bacterium = this->bacteria.at(index.row());
    switch (index.column()) {
        case 0: return QString::fromStdString(bacterium.getName());
        case 1: return QString::fromStdString(bacterium.getSpecies());
        case 2: return bacterium.getSize();
        case 3: return QString::fromStdString(bacterium.getDiseases());
        default: return {};
    }
}

QVariant BacteriaTableModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role != Qt::DisplayRole || orientation != Qt::Horizontal)
        return {};

    switch (section) {
        case 0: return "Name";
        case 1: return "Species";
        case 2: return "Size";
        case 3: return "Diseases";
        default: return {};
    }
}

void BacteriaTableModel::refresh() {
    if (bacteriaFlag == 1 && !biologistName.empty()) {
        this->bacteria = service.getBacteriaByBiologistSpecies(biologistName);
    } else {
        this->bacteria = service.getAllBacteriaService();
    }

    beginResetModel();
    endResetModel();
}

