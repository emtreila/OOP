#include "shoppingbasketmodel.h"


ShoppingBasketModel::ShoppingBasketModel(Service &service, QObject *parent)
    : service(service), QAbstractTableModel(parent) {
}


int ShoppingBasketModel::rowCount(const QModelIndex &) const {
    return static_cast<int>(service.getAllService().size());
}

int ShoppingBasketModel::columnCount(const QModelIndex &) const {
    return 5;
}

QVariant ShoppingBasketModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid() || role != Qt::DisplayRole)
        return {};

    const TrenchCoat &c = this->basket[index.row()];
    switch (index.column()) {
        case 0:
            return QString::fromStdString(c.getSize());
        case 1:
            return QString::fromStdString(c.getColour());
        case 2:
            return c.getPrice();
        case 3:
            return static_cast<int>(c.getQuantity());
        case 4:
            return QString::fromStdString(c.getPhotograph());
        default:
            return {};
    }
}

QVariant ShoppingBasketModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role != Qt::DisplayRole || orientation != Qt::Horizontal)
        return {};

    switch (section) {
        case 0:
            return "Size";
        case 1:
            return "Colour";
        case 2:
            return "Price";
        case 3:
            return "Quantity";
        case 4:
            return "Photo";
        default:
            return {};
    }
}
