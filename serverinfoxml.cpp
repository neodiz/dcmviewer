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

void ServerInfoXML::readfile()
{
    listView;

    QString errorStr;
    int errorLine;
    int errorColumn;
    QDomDocument doc;
    if (!doc.setContent(device, true, &errorStr, &errorLine,
                        &errorColumn)) {
      qWarning("Line %d, column %d: %s", errorLine, errorColumn);
      return;
    }

    QDomElement root = doc.documentElement();
    if (root.tagName() != "bookindex") {
      qWarning("The file is not a bookindex file");
      return;
    }

    QDomNode node = root.firstChild();
    while (!node.isNull()) {
      if (node.toElement().tagName() == "entry")
        parseEntry(node.toElement(), 0);
      node = node.nextSibling();
    }
}

void ServerInfoXML::parseEntry(const QDomElement &element, QListView *parent)
{
    QListView *item;
    if (parent) {
      item = new QListView(parent);
    } else {
      item = new QListView(listView);
    }
    item->setOpen(true);
    item->setText(0, element.attribute("term"));

    QDomNode node = element.firstChild();
    while (!node.isNull()) {
      if (node.toElement().tagName() == "entry") {
        parseEntry(node.toElement(), item);
      } else if (node.toElement().tagName() == "page") {
        QDomNode childNode = node.firstChild();
        while (!childNode.isNull()) {
          if (childNode.nodeType() == QDomNode::TextNode) {
            QString page = childNode.toText().data();
            QString allPages = item->text(1);
            if (!allPages.isEmpty())
              allPages += ", ";
            allPages += page;
            item->setText(1, allPages);
            break;
          }
          childNode = childNode.nextSibling();
        }
      }
      node = node.nextSibling();
    }

}
