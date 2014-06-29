#ifndef MODELSERVERINFO_H
#define MODELSERVERINFO_H

#include <QAbstractTableModel>
#include "serverinfoclass.h"

class ModelServerInfo : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit ModelServerInfo(QObject *parent = 0);
    QList<ServerInfoClass> list;
    QStringList header_data;
    QVariant data(const QModelIndex &index, int role) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    bool removeRow(int row, const QModelIndex &parent);
    bool insertRow(int row, const QModelIndex &parent,ServerInfoClass newServer);
    bool editRow(int row,const QModelIndex &parent,ServerInfoClass newServer);
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;


signals:

public slots:

};

#endif // MODELSERVERINFO_H
