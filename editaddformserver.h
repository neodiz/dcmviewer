#ifndef EDITADDFORMSERVER_H
#define EDITADDFORMSERVER_H
#include "modelserverinfo.h"
#include <QWidget>

namespace Ui {
class EditAddFormServer;
}

class EditAddFormServer : public QWidget
{
    Q_OBJECT

public:
    explicit EditAddFormServer(QWidget *parent = 0);
    ~EditAddFormServer();
    void editLabelStartInfo(QString text);
    void setQLinesForEditUser();
    void setModelServerInfo(ModelServerInfo *FromInsideModel);
    void setIndexModel(QModelIndex IndexModel);
    int addEdit;
private:
    Ui::EditAddFormServer *ui;
    ModelServerInfo *model;
    QModelIndex index;
    void addServer();
    void editServer();
    ServerInfoClass server;


private slots:
    void pushButtonOk();
};

#endif // EDITADDFORMSERVER_H
