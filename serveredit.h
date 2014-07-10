#ifndef SERVEREDIT_H
#define SERVEREDIT_H
#include "modelserverinfo.h"
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
    void setModelServerInfo(ModelServerInfo *model);

private:
    Ui::ServerEdit *ui;
    ModelServerInfo *ServerInfoDataModel_;
    QModelIndex indexModel_;
    void checkEchoServer();
private slots:
    void SaveXMLServerInfo();
    void SlotClicketServer(QModelIndex index);
    void remoteServerInfo();
    void addServerInfo();
    void editServerInfo();
    void checkServerConnection();

};

#endif // SERVEREDIT_H
