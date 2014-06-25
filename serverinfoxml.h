#ifndef SERVERINFOXML_H
#define SERVERINFOXML_H

#include <QDomDocument>
#include <QListView>
class ServerInfoXML
{
public:
    ServerInfoXML();
    bool writeFile();
    void readfile();
    void parseEntry(const QDomElement &element,QListView *parent);
private:
    QDomDocument doc;
    QDomElement root;
    QDomElement alias;
    QDomElement address;
    QDomElement aet;
    QDomElement port;
    QListView *listView;
};

#endif // SERVERINFOXML_H
