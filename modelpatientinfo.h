#ifndef MODELPATIENTINFO_H
#define MODELPATIENTINFO_H

#include <QAbstractTableModel>
#include <querydata.h>

class ModelPatientInfo : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit ModelPatientInfo(QObject *parent = 0);
    QList<QueryData> list;
    QStringList header_data;
    QVariant data(const QModelIndex &index, int role) const;
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;

signals:

public slots:

};

#endif // MODELPATIENTINFO_H
