#ifndef EDITADDFORMSERVER_H
#define EDITADDFORMSERVER_H
#include "serveinfordatamodel.h"
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
    void setModelServerInfo(ServeInforDataModel *FromInsideModel);
    void setIndexModel(QModelIndex IndexModel);
    int addEdit;
private:
    Ui::EditAddFormServer *ui;
    ServeInforDataModel *model;
    QModelIndex index;
    void addServer();
    void editServer();
    ServerInfoClass server;


private slots:
    void pushButtonOk();
};

#endif // EDITADDFORMSERVER_H
