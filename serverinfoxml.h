#ifndef SERVERINFOXML_H
#define SERVERINFOXML_H

#include <QDomDocument>

class ServerInfoXML
{
public:
    ServerInfoXML();
    bool writeFile();
private:
    QDomDocument doc;
    QDomElement root;
    QDomElement alias;
    QDomElement address;
    QDomElement aet;
    QDomElement port;
};

#endif // SERVERINFOXML_H
