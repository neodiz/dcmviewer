#ifndef SERVERINFOXML_H
#define SERVERINFOXML_H
#include <QFile>
class ServerInfoXML
{
public:
    ServerInfoXML();
    void  readFileXML();
    void writeFileXML();
private:
    QFile* file;
};

#endif // SERVERINFOXML_H
