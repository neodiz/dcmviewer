#include "serverinfoxml.h"
#include <QFile>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QMessageBox>
#include <QDebug>



ServerInfoXML::ServerInfoXML()
{
    QString path = qgetenv("HOME") + "/.config/DcmViewer/" + "ServerInfo.xml";
    file_ = new QFile(path);
}


bool ServerInfoXML::readFileXML()
{
    if (!file_->open(QIODevice::ReadOnly | QIODevice::Text))
    {
        //         QMessageBox::critical(this, "QXSRExample::ReadXMLFile", "Couldn't open xml file", QMessageBox::Ok);
        return false;
    }
    QList<QString> Alias,Address,Aet;
    QList<int> Port;

    /* QXmlStreamReader takes any QIODevice. */
    QXmlStreamReader xml(file_);
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
                Alias.append(xml.readElementText());
                continue;
            }
            else if (xml.name() == "Address"){
                Address.append(xml.readElementText());
                continue;
            }
            else if (xml.name() == "AET") {
                Aet.append(xml.readElementText());
                continue;
            }
            else if (xml.name() == "Port") {
                Port.append(xml.readElementText().toInt());
                continue;
            }
        }
    }
    if(xml.hasError())
        return false;
    //        QMessageBox::critical(this, "QXSRExample::parseXML", xml.errorString(), QMessageBox::Ok);

    //resets its internal state to the initial state.
    xml.clear();
    setData(Alias,Address,Aet,Port);

    return true;
}

void ServerInfoXML::writeFileXML(ModelServerInfo *FromInsideModel)
{
    if (!file_->open(QIODevice::WriteOnly | QIODevice::Text))
    {
        //        QMessageBox::critical(this, "QXSRExample::WriteXMLFile", "Couldn't open anna.xml", QMessageBox::Ok);
        return;
    }
    QXmlStreamWriter xmlWriter(file_);
    xmlWriter.setAutoFormatting(true);
    xmlWriter.writeStartDocument();
    xmlWriter.writeStartElement("Server");
    //add Elements
    for(int i=0;i<FromInsideModel->list.size();i++){
        xmlWriter.writeStartElement(FromInsideModel->list.at(i).Alias);
        xmlWriter.writeTextElement("Alias",FromInsideModel->list.at(i).Alias);
        xmlWriter.writeTextElement("Address",FromInsideModel->list.at(i).Address);
        xmlWriter.writeTextElement("AET", FromInsideModel->list.at(i).Aet);
        xmlWriter.writeTextElement("Port", QString::number(FromInsideModel->list.at(i).port));
        xmlWriter.writeEndElement();
    }

    xmlWriter.writeEndElement();
    xmlWriter.writeEndDocument();
    file_->close();
    //    if (file.error())
    //        QMessageBox::critical(this, "QXSRExample::parseXML", file.errorString(), QMessageBox::Ok);


}

QList<ServerInfoClass > ServerInfoXML::returnServerInfo()
{
    return ServerInfoList_;

}


void ServerInfoXML::setData(QList<QString> Alias, QList<QString> Address, QList<QString> Aet, QList<int> Port)
{
    for (int i=0;i<Alias.size();i++){
        ServerInfoClass InfoServer ;
        InfoServer.Alias = Alias.at(i);
        InfoServer.Address = Address.at(i);
        InfoServer.Aet = Aet.at(i);
        InfoServer.port = Port.at(i);
        ServerInfoList_.append(InfoServer);
    }
}


