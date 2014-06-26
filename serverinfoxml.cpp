#include "serverinfoxml.h"
#include <QFile>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QMessageBox>
#include <QDebug>
#include <serverinfoclass.h>
ServerInfoXML::ServerInfoXML()
{
    file = new QFile("ServerInfo.xml");
}

void ServerInfoXML::readFileXML()
{
    if (!file->open(QIODevice::ReadOnly | QIODevice::Text))
    {
//         QMessageBox::critical(this, "QXSRExample::ReadXMLFile", "Couldn't open xml file", QMessageBox::Ok);
         return;
    }
QList<ServerInfoClass> ServerIfo;
int i=0;
    /* QXmlStreamReader takes any QIODevice. */
    QXmlStreamReader xml(file);
    /* We'll parse the XML until we reach end of it.*/
    while(!xml.atEnd() && !xml.hasError())
    {
        /* Read next element.*/
        QXmlStreamReader::TokenType token = xml.readNext();
        /* If token is just StartDocument, we'll go to next.*/
        if(token == QXmlStreamReader::StartDocument)
            continue;

        /* If token is StartElement, we'll see if we can read it.*/
        if(token == QXmlStreamReader::StartElement) {
            if(xml.name() == "Alias") {
                qDebug() << xml.readElementText();
//                ServerIfo.insert(Alias = xml.readElementText();
                continue;
            }
            else if (xml.name() == "Address"){
                qDebug() << xml.readElementText();
//                ServerIfo.at(i).Address =xml.readElementText();
                continue;
            }
            else if (xml.name() == "AET") {
                qDebug() << xml.readElementText();
//                ServerIfo.at(i).Aet=xml.readElementText();
                continue;
            }
            else if (xml.name() == "Port") {
                qDebug() << xml.readElementText();
//                ServerIfo.at(i).port=xml.readElementText().toInt();
                i++;
                continue;
            }

        }
    }
    if(xml.hasError())
//        QMessageBox::critical(this, "QXSRExample::parseXML", xml.errorString(), QMessageBox::Ok);

    //resets its internal state to the initial state.
    xml.clear();
}

void ServerInfoXML::writeFileXML()
{
    if (!file->open(QIODevice::WriteOnly | QIODevice::Text))
    {
 //        QMessageBox::critical(this, "QXSRExample::WriteXMLFile", "Couldn't open anna.xml", QMessageBox::Ok);
         return;
    }
    QXmlStreamWriter xmlWriter(file);
    xmlWriter.setAutoFormatting(true);
    xmlWriter.writeStartDocument();
    xmlWriter.writeStartElement("Server");
    //add Elements
    xmlWriter.writeStartElement("Server1");
    xmlWriter.writeTextElement("Alias", "Server1");
    xmlWriter.writeTextElement("Address", "Server2");
    xmlWriter.writeTextElement("AET", "Server3");
    xmlWriter.writeEndElement();
    xmlWriter.writeStartElement("Server2");
    xmlWriter.writeTextElement("Alias", "Server1");
    xmlWriter.writeTextElement("Address", "Server2");
    xmlWriter.writeTextElement("AET", "Server3");
    xmlWriter.writeEndElement();
    xmlWriter.writeEndElement();

    xmlWriter.writeEndDocument();
    file->close();
//    if (file.error())
//        QMessageBox::critical(this, "QXSRExample::parseXML", file.errorString(), QMessageBox::Ok);


}
