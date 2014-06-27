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
    QList <ServerInfoClass > returnServerInfo();
private:
    QFile* file;
    QList <ServerInfoClass > ServerInfoList;

    void setData(QList<QString> Alias,QList<QString> Address,QList<QString> Aet,QList<int> Port);

};

#endif // SERVERINFOXML_H
