#ifndef SERVERINFOXML_H
#define SERVERINFOXML_H
#include <QFile>
#include <serverinfoclass.h>
#include "serveinfordatamodel.h"
class ServerInfoXML
{
public:
    ServerInfoXML();
    bool  readFileXML();
    void writeFileXML();
private:
    QFile* file;
    QList <ServerInfoClass> *ServerInfo;
    ServeInforDataModel Model;
    void setData(QList<QString> Alias,QList<QString> Address,QList<QString> Aet,QList<int> Port);

};

#endif // SERVERINFOXML_H
