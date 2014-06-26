#ifndef SERVEINFORDATAMODEL_H
#define SERVEINFORDATAMODEL_H

#include <QAbstractTableModel>
#include "serverinfoclass.h"
class ServeInforDataModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit ServeInforDataModel(QObject *parent = 0);
    QList<ServerInfoClass *> list;
    QStringList header_data;
    QVariant data(const QModelIndex &index, int role) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;

signals:

public slots:

};

#endif // SERVEINFORDATAMODEL_H
