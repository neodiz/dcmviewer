#include "dcmsend.h"
#include "mainwindow.h"
#include <QTableWidget>




DcmSend::DcmSend(QString ipAddress, QString portAddress, QString aeAddress, QString aeLocal)
{

    Sender.setAETitle(aeLocal.toLatin1().data());
    Sender.setPeerAETitle(aeAddress.toLatin1().data());
    Sender.setPeerHostName(ipAddress.toLatin1().data());
    Sender.setPeerPort(portAddress.toUInt());
    presID = 0;
}

bool DcmSend::echoSend()
{
    result =Sender.sendECHORequest(0);
    if (result.bad())
        return false;
    return true;
}


bool DcmSend::senFile(QString UrlPathDicom)
{
    result = Sender.sendSTORERequest(presID,UrlPathDicom.toLatin1().data(),NULL,msg,statusDetail,statusCode);
    if (result.good())
        return true;
    else
        return false;

}


bool DcmSend::queryDcm(QList <QString>  &QueryPatientName, QList <QString> &QueryPatientID, QList <QString> &QueryAccessionNumber)
{

    OFVector<QRResponse*> findResponses;
    DcmDataset req;
    req.insertEmptyElement(DCM_PatientName);
    req.insertEmptyElement(DCM_PatientID);
    req.insertEmptyElement(DCM_AccessionNumber);
    req.putAndInsertOFStringArray(DCM_QueryRetrieveLevel, "STUDY");
    req.putAndInsertOFStringArray(DCM_StudyInstanceUID, "");
    T_ASC_PresentationContextID presID = findUncompressedPC(UID_FINDStudyRootQueryRetrieveInformationModel, Sender);
    if (presID == 0)
    {
        DCMNET_ERROR("There is no uncompressed presentation context for Study Root FIND");
        return 1;
    }
    result = Sender.sendFINDRequest(presID, &req,&findResponses);


    if (result.bad())
       return false;


    OFString NamePatient;
    OFString PatientID;
    OFString AccessionNumber;
    for (int i=0;i<findResponses.size();i++){
        if (findResponses.at(i)->m_dataset != NULL){

            result= findResponses.at(i)->m_dataset->findAndGetOFString(DCM_PatientName,NamePatient);
            result= findResponses.at(i)->m_dataset->findAndGetOFString(DCM_AccessionNumber,AccessionNumber);
            result= findResponses.at(i)->m_dataset->findAndGetOFString(DCM_PatientID,PatientID);
            QueryPatientName << NamePatient.data();
            QueryPatientID << PatientID.data();
            QueryAccessionNumber << AccessionNumber.data();
        }
    }
    return true;

}

bool DcmSend::cgetDcm()
{
    OFVector<RetrieveResponse*> findResponses;
    DcmDataset req;
//    req.putAndInsertString(DCM_PatientName,"Nurmukhametov");
//    req.putAndInsertString(DCM_SOPInstanceUID,"1.2.840.113619.2.30.1.1762533908.1851.1361025148.88");
//    req.putAndInsertString(DCM_SOPClassUID,"1.2.840.10008.5.1.4.1.1.4");
    req.putAndInsertString(DCM_StudyInstanceUID,"1.2.840.113745.101000.1008000.38446.6272.7138759");

    Sender.setStorageMode(DCMSCU_STORAGE_DISK);
    Sender.setStorageDir("/tmp/dcmstorage");
//    req.putAndInsertOFStringArray(DCM_QueryRetrieveLevel, "STUDY");
//    req.putAndInsertOFStringArray(DCM_StudyInstanceUID, "");
    T_ASC_PresentationContextID presID = findUncompressedPC(UID_GETStudyRootQueryRetrieveInformationModel, Sender);
    if (presID == 0)
    {
        DCMNET_ERROR("There is no uncompressed presentation context for Study Root FIND");
        return false;
    }
    result=Sender.sendCGETRequest(presID,&req,&findResponses);
    if (result.bad())
        return false;
    return true;


}

void DcmSend::setTransferSyntaxPresentationContext(QString transferSintax,QString SopClass)
{
   ts.push_back(transferSintax.toLatin1().data());
   Sender.addPresentationContext(SopClass.toLatin1().data(),ts);

}
void DcmSend::setTransferSyntaxPresentationContext(QString taskDicom)
{
    if (taskDicom == "echo"){
      ts.push_back(UID_LittleEndianImplicitTransferSyntax);
      Sender.addPresentationContext(UID_VerificationSOPClass,ts);

    }
    else if (taskDicom == "query" ){
      ts.push_back(UID_LittleEndianImplicitTransferSyntax);
      Sender.addPresentationContext(UID_FINDStudyRootQueryRetrieveInformationModel,ts);
    }
    else if (taskDicom == "cget") {

        ts.push_back(UID_JPEGLSLosslessTransferSyntax);
        ts.push_back(UID_JPEGLSLossyTransferSyntax);
//        ts.push_back(UID_LittleEndianImplicitTransferSyntax);
        Sender.addPresentationContext(UID_GETStudyRootQueryRetrieveInformationModel,ts);
        Sender.addPresentationContext(UID_GETPatientRootQueryRetrieveInformationModel,ts);
        Sender.addPresentationContext(UID_RETIRED_GETPatientStudyOnlyQueryRetrieveInformationModel,ts);
    }
}


bool DcmSend::initNetwork()
{
    result =Sender.initNetwork();
    if (result.bad()){
        return false;
    }
    return true;
}

bool DcmSend::createAssociation()
{
    result = Sender.negotiateAssociation();
    if (result.bad())
        return false;
    return true;

}

DcmSend::~DcmSend()
{
    Sender.closeAssociation(DCMSCU_RELEASE_ASSOCIATION);
}
Uint8 DcmSend::findUncompressedPC (const OFString& sopClass,DcmSCU& Sender)
{
    Uint8 pc;
    pc = Sender.findPresentationContextID(sopClass, UID_LittleEndianExplicitTransferSyntax);
    if (pc == 0)
        pc = Sender.findPresentationContextID(sopClass, UID_BigEndianExplicitTransferSyntax);
    if (pc == 0)
        pc = Sender.findPresentationContextID(sopClass, UID_LittleEndianImplicitTransferSyntax);
    return pc;
}


