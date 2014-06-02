#include "querytable.h"
#include "ui_querytableform.h"
#include "querydata.h"
#include <QDebug>

queryTable::queryTable(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::queryTable)
{
    ui->setupUi(this);
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

    for(int i=0;i<QueryPatientName.size();i++){
        QueryData *data = new QueryData();
        data->PatientName= QueryPatientName.at(i);
        data->PatientID= QueryPatientID.at(i);
        data->AccessionNumber= QueryAccessionNumber.at(i);
        model->list.append(data);
    }
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    connect (ui->tableView,SIGNAL(clicked(QModelIndex)),this,SLOT(onClicked(QModelIndex)));
    ui->tableView->setModel(model);
}

queryTable::~queryTable()
{
    delete ui;
}

void queryTable::onClicked(QModelIndex index)
{
    qDebug() << model->list.at(index.row())->PatientName;

}

