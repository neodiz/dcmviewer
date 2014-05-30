#ifndef DATATABLEMODEL_H
#define DATATABLEMODEL_H
#include <QList>
#include <querydata.h>
#include <QStringList>
#include <QAbstractTableModel>

class DataTableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit DataTableModel(QObject *parent = 0);
    QList<QueryData *> list;
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

#endif // DATATABLEMODEL_H
