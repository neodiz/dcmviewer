#include "datatablemodel.h"

DataTableModel::DataTableModel(QObject *parent) :
    QAbstractTableModel(parent)
{
    header_data << QString::fromUtf8("ФИО пациента") << QString::fromUtf8("Номер пациента") << QString::fromUtf8("Номер Услуги");

}

QVariant DataTableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    if (index.row() >= list.size())
        return QVariant();
    if (role == Qt::DisplayRole || role == Qt::EditRole){
        if (index.column() == 0)
            return list.at(index.row())->PatientName;
        if (index.column() == 1)
            return list.at(index.row())->PatientID;
        if (index.column() == 2)
            return list.at(index.row())->AccessionNumber;

    }
    return QVariant();
}

bool DataTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.isValid() && role == Qt::EditRole) {
           // записываем данные из каждого столбца
           if(index.column()==0){
               list.at(index.row())->PatientName = value.toString();
           }
           if(index.column()==1){
               list.at(index.row())->PatientID = value.toString();
           }
           if(index.column()==2){
               list.at(index.row())->AccessionNumber = value.toString();
           }
           return true;
       }
       return false;
}

int DataTableModel::rowCount(const QModelIndex &parent) const
{
    return list.size();
}

int DataTableModel::columnCount(const QModelIndex &parent) const
{
    return 3;
}

QVariant DataTableModel::headerData(int section, Qt::Orientation orientation, int role) const
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

Qt::ItemFlags DataTableModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::ItemIsEnabled;
    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;

}
