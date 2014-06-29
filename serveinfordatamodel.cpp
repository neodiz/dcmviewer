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
            return list.at(index.row()).Alias;
        if (index.column() == 1)
            return list.at(index.row()).Address;
        if (index.column() == 2)
            return list.at(index.row()).Aet;
        if (index.column() == 3)
            return list.at(index.row()).port;

    }
    return QVariant();

}

bool ServeInforDataModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.isValid() && role == Qt::EditRole) {
           // записываем данные из каждого столбца
/*           if(index.column()==0){
               list.value(index.row()).Alias = value.toString();
           }
           if(index.column()==1){
               list.value(index.row()).Address = value.toString();
           }
           if(index.column()==2){
               list.value(index.row()).Aet = value.toString();
           }
           if (index.column() == 3) {
               list.value(index.row()).port = value.toInt();
           }*/

        list.replace(index.row(),list.value(index.row()));
        emit dataChanged(index, index);
           return true;
       }
       return false;

}

bool ServeInforDataModel::removeRow(int row, const QModelIndex &parent)
{
    beginRemoveRows(QModelIndex(), row, row);
    list.removeAt(row);
    endRemoveRows();
    return true;

}

bool ServeInforDataModel::insertRow(int row, const QModelIndex &parent,ServerInfoClass newServer)
{
    beginInsertRows(QModelIndex(),row,row);
    list.append(newServer);
    endInsertRows();
    return true;
}

bool ServeInforDataModel::editRow(int row, const QModelIndex &parent, ServerInfoClass newServer)
{
    beginResetModel();
    list[row]= newServer;
    endResetModel();
    return true;

}


int ServeInforDataModel::rowCount(const QModelIndex &parent) const
{
    return list.size();

}

int ServeInforDataModel::columnCount(const QModelIndex &parent) const
{
    return 4;

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
