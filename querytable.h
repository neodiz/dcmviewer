#ifndef QUERYTABLE_H
#define QUERYTABLE_H

#include <QWidget>
#include <QModelIndex>
#include "datatablemodel.h"
#include <QSortFilterProxyModel>

namespace Ui {
class queryTable;
}

class queryTable : public QWidget
{
    Q_OBJECT

public:
    explicit queryTable(QWidget *parent = 0);
    bool SetPatientName(QList <QString> Patient);
    bool setPatientID(QList <QString> PatientID);
    bool setAccessionNumber(QList<QString> AccessionNumber);
    void writeDataTableSpace();
    ~queryTable();

private:
    Ui::queryTable *ui;
    QList <QString> QueryPatientName;
    QList <QString> QueryPatientID;
    QList <QString> QueryAccessionNumber;
    DataTableModel* model= new DataTableModel;
    QSortFilterProxyModel *proxyModel;
private slots:
    void onClicked(QModelIndex index);
    void ClickedFilterQuery();
    void CgetPatient();
};

#endif // QUERYTABLE_H
