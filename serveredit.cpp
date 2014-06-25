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
}

ServerEdit::~ServerEdit()
{
    delete ui;
}

void ServerEdit::SaveXMLServerInfo()
{
    ServerInfoXML *writeServerInfo = new ServerInfoXML();
    if (!writeServerInfo->writeFile())
        qDebug() << "Cannot write file";
    this->close();

}
