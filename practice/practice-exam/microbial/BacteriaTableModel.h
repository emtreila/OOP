#ifndef BACTERIATABLEMODEL_H
#define BACTERIATABLEMODEL_H

#include <QAbstractTableModel>

#include "Bacterium.h"
#include "Service.h"

class BacteriaTableModel : public QAbstractTableModel {
    Q_OBJECT

private:
    std::vector<Bacterium> bacteria;
    Service &service;
    int bacteriaFlag;
    std::string biologistName;


public:
    explicit BacteriaTableModel(Service &service, QObject *parent = nullptr, int bacteriaFlag = 0,
                            const std::string &biologistName = ""
    );

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

    void refresh();
};


#endif //BACTERIATABLEMODEL_H
