#include "serveredit.h"
#include "ui_servereditform.h"
#include "serverinfoxml.h"
#include <QDebug>
#include <QMessageBox>
#include <QProcess>
#include <dcmserver.h>

ServerEdit::ServerEdit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ServerEdit)
{
    ui->setupUi(this);
    connect(ui->pushButtonCloseWindow,SIGNAL(clicked()),this,SLOT(SaveXMLServerInfo()));
    connect(ui->listView,SIGNAL(clicked(QModelIndex)),this,SLOT(SlotClicketServer(QModelIndex)));
    connect(ui->pushButtonRemoveServer,SIGNAL(clicked()),this,SLOT(remoteServerInfo()));
    connect(ui->pushButtonAddServer,SIGNAL(clicked()),this,SLOT(addServerInfo()));
    connect(ui->pushButtonChangeServer,SIGNAL(clicked()),this,SLOT(editServerInfo()));
    connect(ui->pushButtonCheckServer,SIGNAL(clicked()),this,SLOT(checkServerConnection()));

    ui->listView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->listView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->listView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

ServerEdit::~ServerEdit()
{
    delete ui;
}

void ServerEdit::setModelServerInfo(ModelServerInfo *model)
{
    ServerInfoDataModel=model;
    ui->listView->setModel(ServerInfoDataModel);
}

void ServerEdit::checkEchoServer()
{
    DcmServer *ServerCheck = new DcmServer(ServerInfoDataModel->list.at(indexModel.row()).Address,
                                           ServerInfoDataModel->list.at(indexModel.row()).port,
                                           ServerInfoDataModel->list.at(indexModel.row()).Aet,
                                           QString("Sender"));
    ServerCheck->setTransferSyntaxPresentationContext(QString("echo"));
    if (ServerCheck->initNetwork()){
        if (ServerCheck->createAssociation())
            if(ServerCheck->echoSend())
                ui->labelStatusEcho->setStyleSheet("QLabel {  color : green; }");
    }
    else
        ui->labelStatusEcho->setStyleSheet("QLabel {  color : red; }");

}

void ServerEdit::SaveXMLServerInfo()
{
    ServerInfoXML *writeServerInfo = new ServerInfoXML();
    writeServerInfo->writeFileXML(ServerInfoDataModel);
    this->close();

}

void ServerEdit::SlotClicketServer(QModelIndex index)
{

    indexModel = index;

}

void ServerEdit::remoteServerInfo()
{
    int button = QMessageBox::question(this,
                                       QString::fromLocal8Bit("Подтверждение удаления"),
                                       QString::fromLocal8Bit("Вы уверены что хотите удалить  \"%1\"?").arg(ServerInfoDataModel->list.at(indexModel.row()).Alias),
                                       QMessageBox::Yes | QMessageBox::No);
    if (button == QMessageBox::Yes) {
        ServerInfoDataModel->removeRow(indexModel.row(),indexModel);
    }

}

void ServerEdit::addServerInfo()
{
    EditAddFormServer *addServer = new EditAddFormServer();
    addServer->editLabelStartInfo("Введите параметры нового сервера PACS");
    addServer->setModelServerInfo(ServerInfoDataModel);
    addServer->addEdit = 0;
    addServer->show();

}



void ServerEdit::editServerInfo()
{
    EditAddFormServer *editServer = new EditAddFormServer();
    editServer->editLabelStartInfo("Измените параметры сервера PACS");
    editServer->addEdit = 1;
    editServer->setModelServerInfo(ServerInfoDataModel);
    editServer->setIndexModel(indexModel);
    editServer->show();


}

void ServerEdit::checkServerConnection()
{
    QStringList pingParams;
    QProcess pingExec;
    pingParams.append("-c");
    pingParams.append("1");
    pingParams.append(ServerInfoDataModel->list.at(indexModel.row()).Address);
    int exitCode = pingExec.execute("ping",pingParams);
    pingExec.waitForFinished(-1);

    if (0 == exitCode) {
        ui->labelStatusPing->setStyleSheet("QLabel {  color : green; }");
        checkEchoServer();
    } else {
        ui->labelStatusPing->setStyleSheet("QLabel {  color : red; }");
    }
}
