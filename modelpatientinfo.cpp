#include "modelpatientinfo.h"

ModelPatientInfo::ModelPatientInfo(QObject *parent) :
    QAbstractTableModel(parent)
{
    header_data << QString::fromUtf8("ФИО пациента") << QString::fromUtf8("Номер пациента") << QString::fromUtf8("Номер Услуги") <<  QString::fromUtf8("Модальность") << QString::fromUtf8("Дата исследования");
}

QVariant ModelPatientInfo::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    if (index.row() >= list.size())
        return QVariant();
    if (role == Qt::DisplayRole || role == Qt::EditRole){
        if (index.column() == 0)
            return list.at(index.row()).PatientName_;
        if (index.column() == 1)
            return list.at(index.row()).PatientID_;
        if (index.column() == 2)
            return list.at(index.row()).AccessionNumber_;
        if (index.column() == 3)
            return list.at(index.row()).Modality_;
        if (index.column() == 4)
            return list.at(index.row()).StudyDate_;

    }
    return QVariant();
}

int ModelPatientInfo::rowCount(const QModelIndex &parent) const
{
    return list.size();
}

int ModelPatientInfo::columnCount(const QModelIndex &parent) const
{
    return 5;
}

QVariant ModelPatientInfo::headerData(int section, Qt::Orientation orientation, int role) const
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

Qt::ItemFlags ModelPatientInfo::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::ItemIsEnabled;
    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}
