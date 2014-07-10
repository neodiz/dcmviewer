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
    ui->lineEditAlias->setText(model_->list.at(index_.row()).Alias);
    ui->lineEditAddress->setText(model_->list.at(index_.row()).Address);
    ui->lineEditAet->setText(model_->list.at(index_.row()).Aet);
    ui->lineEditPort->setText(QString::number(model_->list.at(index_.row()).port));
}

void EditAddFormServer::setModelServerInfo(ModelServerInfo *FromInsideModel)
{
    model_ = FromInsideModel;
}

void EditAddFormServer::setIndexModel(QModelIndex IndexModel)
{
    index_ = IndexModel;
    setQLinesForEditUser();
}

void EditAddFormServer::addServer()
{
    model_->insertRow(model_->list.size()+1,QModelIndex(),server_);

}

void EditAddFormServer::editServer()
{
    int button = QMessageBox::question(this,
                                       QString::fromLocal8Bit("Подтверждение изменение записи"),
                                       QString::fromLocal8Bit("Вы уверены что хотите изменить запись \"%1\" ?").arg(model_->list.at(index_.row()).Alias),
                                       QMessageBox::Yes | QMessageBox::No);
    if (button == QMessageBox::Yes) {
        model_->editRow(index_.row(),QModelIndex(),server_);
    }


}

void EditAddFormServer::pushButtonOk()
{


    server_.Address= ui->lineEditAddress->text();
    server_.Aet=ui->lineEditAet->text();
    server_.Alias=ui->lineEditAlias->text();
    server_.port=ui->lineEditPort->text().toInt();
    if (addEdit == 0)
        addServer();
    else if (addEdit == 1)
        editServer();

    emit this->close();

}
