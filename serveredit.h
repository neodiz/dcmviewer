#ifndef SERVEREDIT_H
#define SERVEREDIT_H
#include "serveinfordatamodel.h"
#include "editaddformserver.h"
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
    ServeInforDataModel *ServerInfoDataModel;
    QModelIndex indexModel;
private slots:
    void SaveXMLServerInfo();
    void SlotClicketServer(QModelIndex index);
    void remoteServerInfo();
    void addServerInfo();
    void editServerInfo();
    void checkServerConnection();

};

#endif // SERVEREDIT_H
