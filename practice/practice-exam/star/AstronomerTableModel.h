#ifndef ASTRONOMERTABLEMODEL_H
#define ASTRONOMERTABLEMODEL_H
#include <qtmetamacros.h>

#include "Astronomer.h"
#include "Service.h"
#include <QAbstractTableModel>

class AstronomerTableModel : public QAbstractTableModel {
    Q_OBJECT

private:
    std::vector<Star> stars;
    Service &service;
    int starFlag;
    std::string astronomerName;
    std::string constellationName;

public:
    explicit AstronomerTableModel(Service &service, QObject *parent = nullptr, int starFlag = 0,
                                  const std::string &astronomerName = "", const std::string &constellationName = ""
    );

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

    void refresh();
};


#endif //ASTRONOMERTABLEMODEL_H
