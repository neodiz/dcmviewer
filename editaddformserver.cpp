#include "editaddformserver.h"
#include "ui_editaddformserver.h"
#include "serverinfoclass.h"
#include <QMessageBox>

EditAddFormServer::EditAddFormServer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EditAddFormServer)
{
    ui->setupUi(this);
    connect(ui->PushButtonCancel,SIGNAL(clicked()),this,SLOT(close()));
    connect(ui->PushButtonOk,SIGNAL(clicked()),this,SLOT(pushButtonOk()));
}

EditAddFormServer::~EditAddFormServer()
{
    delete ui;
}

void EditAddFormServer::editLabelStartInfo(QString text)
{
    ui->LabelFunction->setText(text);
}

void EditAddFormServer::setQLinesForEditUser()
{
    ui->lineEditAlias->setText(model->list.at(index.row()).Alias);
    ui->lineEditAddress->setText(model->list.at(index.row()).Address);
    ui->lineEditAet->setText(model->list.at(index.row()).Aet);
    ui->lineEditPort->setText(QString::number(model->list.at(index.row()).port));
}

void EditAddFormServer::setModelServerInfo(ModelServerInfo *FromInsideModel)
{
    model = FromInsideModel;
}

void EditAddFormServer::setIndexModel(QModelIndex IndexModel)
{
    index = IndexModel;
    setQLinesForEditUser();
}

void EditAddFormServer::addServer()
{
    model->insertRow(model->list.size()+1,QModelIndex(),server);

}

void EditAddFormServer::editServer()
{
    int button = QMessageBox::question(this,
                                       QString::fromLocal8Bit("Подтверждение изменение записи"),
                                       QString::fromLocal8Bit("Вы уверены что хотите изменить запись \"%1\" ?").arg(model->list.at(index.row()).Alias),
                                       QMessageBox::Yes | QMessageBox::No);
    if (button == QMessageBox::Yes) {
        model->editRow(index.row(),QModelIndex(),server);
    }


}

void EditAddFormServer::pushButtonOk()
{


    server.Address= ui->lineEditAddress->text();
    server.Aet=ui->lineEditAet->text();
    server.Alias=ui->lineEditAlias->text();
    server.port=ui->lineEditPort->text().toInt();
    if (addEdit == 0)
        addServer();
    else if (addEdit == 1)
        editServer();

    emit this->close();

}
