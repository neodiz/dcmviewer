#include "serverinfoxml.h"
#include <QFile>
#include <QTextStream>

ServerInfoXML::ServerInfoXML()
{
}

bool ServerInfoXML::writeFile()
{
    QFile data("servers.xml");
    if (data.open(QFile::WriteOnly | QFile::Truncate)){

        const int Indent = 4;
        root = doc.createElement("server");
        alias = doc.createElement("alias");
        address = doc.createElement("address");
        aet = doc.createElement("aet");
        port = doc.createElement("port");

        QDomText quoteText = doc.createTextNode("Errare humanum est");
        QDomText translationText = doc.createTextNode("To err is human");

        doc.appendChild(root);
        root.appendChild(alias);
        root.appendChild(address);
        root.appendChild(aet);
        root.appendChild(port);
        alias.appendChild(quoteText);
        address.appendChild(translationText);

        QTextStream out(&data);
        doc.save(out, Indent);
        return true;
    }
    else
        return false;
}
