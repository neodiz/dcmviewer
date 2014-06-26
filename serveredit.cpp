#include "serveredit.h"
#include "ui_servereditform.h"
#include "serverinfoxml.h"
#include <QDebug>

ServerEdit::ServerEdit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ServerEdit)
{
    ui->setupUi(this);
    connect(ui->pushButtonCloseWindow,SIGNAL(clicked()),this,SLOT(SaveXMLServerInfo()));
    ServerInfoXML *readServerInfo = new ServerInfoXML();
    readServerInfo->readFileXML();
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
