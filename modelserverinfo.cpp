#include "modelserverinfo.h"

ModelServerInfo::ModelServerInfo(QObject *parent) :
    QAbstractTableModel(parent)
{
}

QVariant ModelServerInfo::data(const QModelIndex &index, int role) const
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

bool ModelServerInfo::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.isValid() && role == Qt::EditRole) {
           // записываем данные из каждого столбца
        list.replace(index.row(),list.value(index.row()));
        emit dataChanged(index, index);
           return true;
       }
       return false;

}

bool ModelServerInfo::removeRow(int row, const QModelIndex &parent)
{
    beginRemoveRows(QModelIndex(), row, row);
    list.removeAt(row);
    endRemoveRows();
    return true;

}

bool ModelServerInfo::insertRow(int row, const QModelIndex &parent, ServerInfoClass newServer)
{
    beginInsertRows(QModelIndex(),row,row);
    list.append(newServer);
    endInsertRows();
    return true;
}

bool ModelServerInfo::editRow(int row, const QModelIndex &parent, ServerInfoClass newServer)
{
    beginResetModel();
    list[row]= newServer;
    endResetModel();
    return true;

}

int ModelServerInfo::rowCount(const QModelIndex &parent) const
{
    return list.size();
}

int ModelServerInfo::columnCount(const QModelIndex &parent) const
{
    return 4;
}

QVariant ModelServerInfo::headerData(int section, Qt::Orientation orientation, int role) const
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
Qt::ItemFlags ModelServerInfo::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::ItemIsEnabled;
    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}
