#include "querytable.h"
#include "ui_querytableform.h"

queryTable::queryTable(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::queryTable)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(4);
    QStringList tableshow;
    tableshow << "ФИО пациента" << "Номер Пациента" << "Номер Услуги" << "Получить";
    ui->tableWidget->setHorizontalHeaderLabels(tableshow);
}

bool queryTable::SetPatientName(QList<QString> Patient)
{
   QueryPatientName= Patient;
   if (QueryPatientName.isEmpty())
       return false ;
   return true;

}

bool queryTable::setPatientID(QList<QString> PatientID)
{
    QueryPatientID = PatientID;
    if (QueryPatientID.isEmpty())
        return false;
    return true;
}

bool queryTable::setAccessionNumber(QList<QString> AccessionNumber)
{
    QueryAccessionNumber= AccessionNumber;
    if (QueryAccessionNumber.isEmpty())
        return false;
    return true;
}

void queryTable::writeDataTableSpace()
{
 ui->tableWidget->setRowCount(QueryPatientName.size());
 for (int i=0;i<QueryPatientName.size();i++){
     ui->tableWidget->setItem(i,0,new QTableWidgetItem(QueryPatientName.at(i)));
     ui->tableWidget->setItem(i,1,new QTableWidgetItem(QueryPatientID.at(i)));
     ui->tableWidget->setItem(i,2,new QTableWidgetItem(QueryAccessionNumber.at(i)));
     ui->tableWidget->setCellWidget(i,3,new QPushButton("Запросить"));
 }
}

queryTable::~queryTable()
{
    delete ui;
}

