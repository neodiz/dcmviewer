#include "serveinfordatamodel.h"

ServeInforDataModel::ServeInforDataModel(QObject *parent) :
    QAbstractTableModel(parent)
{
}

QVariant ServeInforDataModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    if (index.row() >= list.size())
        return QVariant();
    if (role == Qt::DisplayRole || role == Qt::EditRole){
        if (index.column() == 0)
            return list.at(index.row())->Alias;
        if (index.column() == 1)
            return list.at(index.row())->Address;
        if (index.column() == 2)
            return list.at(index.row())->Aet;
        if (index.column() == 3)
            return list.at(index.row())->port;

    }
    return QVariant();

}

bool ServeInforDataModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.isValid() && role == Qt::EditRole) {
           // записываем данные из каждого столбца
           if(index.column()==0){
               list.at(index.row())->Alias = value.toString();
           }
           if(index.column()==1){
               list.at(index.row())->Address = value.toString();
           }
           if(index.column()==2){
               list.at(index.row())->Aet = value.toString();
           }
           if (index.column() == 3) {
               list.at(index.row())->port = value.toInt();
           }
           return true;
       }
       return false;

}

int ServeInforDataModel::rowCount(const QModelIndex &parent) const
{
    return list.size();

}

int ServeInforDataModel::columnCount(const QModelIndex &parent) const
{
    return 3;

}

QVariant ServeInforDataModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole){
        return header_data.at(section);
    }
    else {
        return QString("%1").arg(section +1);
    }

}

Qt::ItemFlags ServeInforDataModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::ItemIsEnabled;
    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;

}
