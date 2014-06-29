#include "querytable.h"
#include "ui_querytableform.h"
#include "querydata.h"
#include <QDebug>
#include "dcmserver.h"
#include <modelpatientinfo.h>


queryTable::queryTable(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::queryTable)
{
    ui->setupUi(this);
    model = new ModelPatientInfo;
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

}

void queryTable::setModelServerInfo(ModelServerInfo *model)
{
    ServerInfoModel = model;
    setComboBoxItems();


}

queryTable::~queryTable()
{
    delete ui;
}

void queryTable::setComboBoxItems()
{
    for (unsigned int i=0;i<ServerInfoModel->list.size();i++)
        ui->ComboBoxServerInfo->addItem(ServerInfoModel->list.at(i).Alias);
}

bool queryTable::queryServer()
{
    DcmServer *QueryDcm = new DcmServer(ServerInfoModel->list.at(ui->ComboBoxServerInfo->currentIndex()).Address,
                                        ServerInfoModel->list.at(ui->ComboBoxServerInfo->currentIndex()).port,
                                        ServerInfoModel->list.at(ui->ComboBoxServerInfo->currentIndex()).Aet,
                                        QString("Sender"));
    QueryDcm->setTransferSyntaxPresentationContext(QString("query"));
    QList<QueryData> *Patients = new QList<QueryData>;
    if (QueryDcm->initNetwork()){
        if (QueryDcm->createAssociation())
            if(QueryDcm->queryDcm(Patients)){
                for (int i=0;i<Patients->size();i++)
                    model->list.append(Patients->at(i));
                return true;

            }
    }
    else {
        return false;
    }

}

void queryTable::onClicked(QModelIndex index)
{
    qDebug() << model->list.at(index.row()).PatientName;

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
        if (!model->list.empty())
            proxyModel->setFilterRegExp("");
        else{

        if(queryServer()){
            //               proxyModel = new QSortFilterProxyModel(this);
            //               proxyModel->setSourceModel(model);
            proxyModel = new QSortFilterProxyModel(this);
            proxyModel->setSourceModel(model);
            ui->tableView->setModel(proxyModel);


        }
        else
            QMessageBox::critical(0,"Error", "Нет возможности установить соединение с PACS сервер");

        //
    }

}

void queryTable::CgetPatient()
{


}

