#include "AstronomerTableModel.h"

AstronomerTableModel::AstronomerTableModel(Service &service, QObject *parent, int starFlag,
                                           const std::string &astronomerName, const std::string &constellationName)
    : QAbstractTableModel(parent), service(service), starFlag(starFlag), astronomerName(astronomerName),
      constellationName(constellationName) {
    if (starFlag == 1 && !astronomerName.empty()) {
        this->stars = service.getAllStudiedStars(this->constellationName);
    } else {
        this->stars = service.getAllStars();
    }
}

int AstronomerTableModel::rowCount(const QModelIndex &) const {
    return static_cast<int>(this->stars.size());
}

int AstronomerTableModel::columnCount(const QModelIndex &) const {
    return 5;
}

QVariant AstronomerTableModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid() || role != Qt::DisplayRole)
        return {};

    const Star &star = this->stars.at(index.row());
    switch (index.column()) {
        case 0: return QString::fromStdString(star.getName());
        case 1: return QString::fromStdString(star.getConstellation());
        case 2: return star.getRA();
        case 3: return star.getDec();
        case 4: return star.getDiameter();
        default: return {};
    }
}

QVariant AstronomerTableModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role != Qt::DisplayRole || orientation != Qt::Horizontal)
        return {};

    switch (section) {
        case 0: return "Name";
        case 1: return "Constellation";
        case 2: return "RA";
        case 3: return "Dec";
        case 4: return "Diameter";
        default: return {};
    }
}

void AstronomerTableModel::refresh() {
    beginResetModel();
    endResetModel();
}
