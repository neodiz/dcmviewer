#ifndef SHOWDICOMFORM_H
#define SHOWDICOMFORM_H

#include <QWidget>
#include <QPixmap>
#include <QImage>
#include <QSize>
#include "tableshow.h"


namespace Ui {
class showDicomForm;
}

class showDicomForm : public QWidget
{
    Q_OBJECT

public:
    explicit showDicomForm(QWidget *parent = 0);
    ~showDicomForm();
    void setQimage(QImage m_qimage);
    void setSize(QSize sizeDCM);

private:
    Ui::showDicomForm *ui;
    QPixmap pixmap;
    QSize SizeDcmFile;
};

#endif // SHOWDICOMFORM_H
