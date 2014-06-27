#include "serveredit.h"
#include "ui_servereditform.h"
#include "serverinfoxml.h"
#include <QDebug>
#include "serveinfordatamodel.h"

ServerEdit::ServerEdit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ServerEdit)
{
    ui->setupUi(this);
    connect(ui->pushButtonCloseWindow,SIGNAL(clicked()),this,SLOT(SaveXMLServerInfo()));
    QList<ServerInfoClass >  ServerData ;
    ServeInforDataModel *ServerInfoDataModel = new ServeInforDataModel;
    ServerInfoXML *readServerInfo = new ServerInfoXML();
    readServerInfo->readFileXML();
    ServerData = readServerInfo->returnServerInfo();
    for (int i =0;i<ServerData.size();i++)
        ServerInfoDataModel->list= (ServerData);
    ui->listView->setModel(ServerInfoDataModel);
}

ServerEdit::~ServerEdit()
{
    delete ui;
}

void ServerEdit::SaveXMLServerInfo()
{
//    ServerInfoXML *writeServerInfo = new ServerInfoXML();
//    writeServerInfo->writeFileXML();
 //       qDebug() << "Cannot write file";
    this->close();

}
