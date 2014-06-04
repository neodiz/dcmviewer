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
    connect(ui->pushButtonSearch,SIGNAL(clicked()),this,SLOT(ClickedFilterQuery()));
     proxyModel = new QSortFilterProxyModel(this);
    proxyModel->setSourceModel(model);
    ui->tableView->setModel(proxyModel);
}

queryTable::~queryTable()
{
    delete ui;
}

void queryTable::onClicked(QModelIndex index)
{
    qDebug() << model->list.at(index.row())->PatientName;

}

void queryTable::ClickedFilterQuery()
{
    bool setFilter=false;
    if (!ui->searchLinePatientName->text().isEmpty()){
        QString UrlSearch("^");
        UrlSearch.append(ui->searchLinePatientName->text());
        QRegExp Regex(UrlSearch);
        proxyModel->setFilterRegExp(Regex);
        proxyModel->setFilterKeyColumn(0);
        setFilter = true;
    }
    if (!ui->searchLinePatientID->text().isEmpty()){
        QString UrlSearch("^");
        UrlSearch.append(ui->searchLinePatientID->text());
        qDebug() << UrlSearch;
        QRegExp Regex(UrlSearch);
        proxyModel->setFilterRegExp(Regex);
        proxyModel->setFilterKeyColumn(1);
        setFilter = true;
    }
    if (!ui->searchLineAccessionNumber->text().isEmpty()){
        QString UrlSearch("^");
        UrlSearch.append(ui->searchLineAccessionNumber->text());
        QRegExp Regex(UrlSearch);
        proxyModel->setFilterRegExp(Regex);
        proxyModel->setFilterKeyColumn(2);
        setFilter = true;
    }
    if (!setFilter)
        proxyModel->setFilterRegExp("");


}

