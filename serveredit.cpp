#include "serveredit.h"
#include "ui_servereditform.h"

ServerEdit::ServerEdit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ServerEdit)
{
    ui->setupUi(this);
}

ServerEdit::~ServerEdit()
{
    delete ui;
}
