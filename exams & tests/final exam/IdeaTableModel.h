#ifndef IDEATABLEMODEL_H
#define IDEATABLEMODEL_H
#include <QAbstractTableModel>

#include "Idea.h"
#include "Service.h"


class IdeaTableModel : public QAbstractTableModel {
    Q_OBJECT

private:
    std::vector<Idea> ideas;
    Service &service;
    std::string researcherName;

public:
    explicit IdeaTableModel(Service &service, QObject *parent = nullptr,
                            const std::string &researcherName = ""
    );

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

    void refresh();
};


#endif //IDEATABLEMODEL_H
