#ifndef SERVEREDIT_H
#define SERVEREDIT_H

#include <QWidget>

namespace Ui {
class ServerEdit;
}

class ServerEdit : public QWidget
{
    Q_OBJECT

public:
    explicit ServerEdit(QWidget *parent = 0);
    ~ServerEdit();

private:
    Ui::ServerEdit *ui;
};

#endif // SERVEREDIT_H
