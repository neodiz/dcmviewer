#include "showdicomform.h"
#include "ui_showdicomform.h"

showDicomForm::showDicomForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::showDicomForm)
{
    ui->setupUi(this);
}

showDicomForm::~showDicomForm()
{
    delete ui;
}

void showDicomForm::setQimage(QImage m_qimage)
{
    QPixmap pixmap= QPixmap::fromImage(m_qimage).scaled(SizeDcmFile);
    ui->label->setMinimumSize(SizeDcmFile);
    ui->label->setPixmap(pixmap);

}

void showDicomForm::setSize(QSize sizeDCM)
{
     SizeDcmFile=sizeDCM;

}
