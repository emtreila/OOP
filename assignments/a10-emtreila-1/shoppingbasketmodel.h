#ifndef SHOPPINGBASKETMODEL_H
#define SHOPPINGBASKETMODEL_H

#include <QAbstractTableModel>

#include "domain/TrenchCoat.h"
#include "service/Service.h"


QT_BEGIN_NAMESPACE

namespace Ui {
    class ShoppingBasketModel;
}

QT_END_NAMESPACE

class ShoppingBasketModel : public QAbstractTableModel {
    Q_OBJECT

public:
explicit ShoppingBasketModel(Service& service, QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

private:
    std::vector<TrenchCoat> basket;
    Service &service;
};


#endif //SHOPPINGBASKETMODEL_H
