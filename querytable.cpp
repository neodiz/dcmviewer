#include "querytable.h"
#include "ui_querytableform.h"
#include "querydata.h"
#include <QDebug>
#include "dcmserver.h"
#include <modelpatientinfo.h>
#include <dcmtk/dcmdata/dcuid.h>

queryTable::queryTable(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::queryTable)
{
    ui->setupUi(this);
    model_ = new ModelPatientInfo;
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);


    connect (ui->tableView,SIGNAL(clicked(QModelIndex)),this,SLOT(onClicked(QModelIndex)));
    connect(ui->pushButtonSearch,SIGNAL(clicked()),this,SLOT(ClickedFilterQuery()));
    connect(ui->getPatientfromServer,SIGNAL(clicked()),this,SLOT(CgetPatient()));
    ui->ComboBoxServerInfo->setEditable(true);
    ui->ComboBoxServerInfo->setEditable(false);

}

bool queryTable::SetPatientName(QList<QString> Patient)
{
    QueryPatientName_= Patient;
    if (QueryPatientName_.isEmpty())
        return false ;
    return true;

}

bool queryTable::setPatientID(QList<QString> PatientID)
{
    QueryPatientID_ = PatientID;
    if (QueryPatientID_.isEmpty())
        return false;
    return true;
}

bool queryTable::setAccessionNumber(QList<QString> AccessionNumber)
{
    QueryAccessionNumber_= AccessionNumber;
    if (QueryAccessionNumber_.isEmpty())
        return false;
    return true;
}

void queryTable::writeDataTableSpace()
{

}

void queryTable::setModelServerInfo(ModelServerInfo *model)
{
    ServerInfoModel_ = model;
    setComboBoxItems();


}

queryTable::~queryTable()
{
    delete ui;
}

void queryTable::setComboBoxItems()
{
    for (unsigned int i=0;i<ServerInfoModel_->list.size();i++)
        ui->ComboBoxServerInfo->addItem(ServerInfoModel_->list.at(i).Alias);
}

bool queryTable::queryServer()
{
    DcmServer *QueryDcm = new DcmServer(ServerInfoModel_->list.at(ui->ComboBoxServerInfo->currentIndex()).Address,
                                        ServerInfoModel_->list.at(ui->ComboBoxServerInfo->currentIndex()).port,
                                        ServerInfoModel_->list.at(ui->ComboBoxServerInfo->currentIndex()).Aet,
                                        QString("Sender"));
    QueryDcm->setTransferSyntaxPresentationContext(QString("query"));
    QList<QueryData> *Patients = new QList<QueryData>;
    if (QueryDcm->initNetwork()){
        if (QueryDcm->createAssociation())
            if(QueryDcm->queryDcm(Patients)){
                for (int i=0;i<Patients->size();i++)
                    model_->list.append(Patients->at(i));
                return true;

            }
    }
    else {
        return false;
    }
    return true;

}

void queryTable::onClicked(QModelIndex index)
{
    qDebug() << dcmFindUIDFromName(model_->list.at(index.row()).Modality_.toLatin1());

}

void queryTable::ClickedFilterQuery()
{
    bool setFilter=false;
    if (!ui->searchLinePatientName->text().isEmpty()){
        QString UrlSearch("^");
        UrlSearch.append(ui->searchLinePatientName->text());
        QRegExp Regex(UrlSearch);
        proxyModel_->setFilterRegExp(Regex);
        proxyModel_->setFilterKeyColumn(0);
        setFilter = true;
    }
    if (!ui->searchLinePatientID->text().isEmpty()){
        QString UrlSearch("^");
        UrlSearch.append(ui->searchLinePatientID->text());
        qDebug() << UrlSearch;
        QRegExp Regex(UrlSearch);
        proxyModel_->setFilterRegExp(Regex);
        proxyModel_->setFilterKeyColumn(1);
        setFilter = true;
    }
    if (!ui->searchLineAccessionNumber->text().isEmpty()){
        QString UrlSearch("^");
        UrlSearch.append(ui->searchLineAccessionNumber->text());
        QRegExp Regex(UrlSearch);
        proxyModel_->setFilterRegExp(Regex);
        proxyModel_->setFilterKeyColumn(2);
        setFilter = true;
    }
    if (!setFilter) {
        if (!model_->list.empty()){
            proxyModel_->setFilterRegExp("");
        }
        else {

            if(queryServer()){

                proxyModel_ = new QSortFilterProxyModel(this);
                proxyModel_->setSourceModel(model_);
                ui->tableView->setModel(proxyModel_);


            }
            else
                QMessageBox::critical(0,"Error", "Нет возможности установить соединение с PACS сервер");

            //
        }
    }

}

void queryTable::CgetPatient()
{


}

