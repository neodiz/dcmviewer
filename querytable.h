#ifndef QUERYTABLE_H
#define QUERYTABLE_H

#include <QWidget>
#include <QModelIndex>
#include <QSortFilterProxyModel>
#include <modelserverinfo.h>
#include <modelpatientinfo.h>
#include <QMessageBox>
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
    void setModelServerInfo(ModelServerInfo *model);
    ~queryTable();

private:
    Ui::queryTable *ui;
    QList <QString> QueryPatientName_;
    QList <QString> QueryPatientID_;
    QList <QString> QueryAccessionNumber_;
    ModelPatientInfo *model_;
    ModelServerInfo *ServerInfoModel_;
    QSortFilterProxyModel *proxyModel_;
    void setComboBoxItems();
    bool queryServer();
private slots:
    void onClicked(QModelIndex index);
    void ClickedFilterQuery();
    void CgetPatient();
};

#endif // QUERYTABLE_H
