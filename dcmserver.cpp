#include "dcmserver.h"


DcmServer::DcmServer(QString ipAddress, int portAddress, QString aeAddress, QString aeLocal)
{
    Sender.setAETitle(aeLocal.toLatin1().data());
    Sender.setPeerAETitle(aeAddress.toLatin1().data());
    Sender.setPeerHostName(ipAddress.toLatin1().data());
    Sender.setPeerPort(portAddress);
    presID = 0;
    msg = NULL;
    statusDetail = NULL;

}

bool DcmServer::echoSend()
{
    result =Sender.sendECHORequest(0);
    if (result.bad())
        return false;
    return true;

}

bool DcmServer::initNetwork()
{
    result =Sender.initNetwork();
    if (result.bad()){
        return false;
    }
    return true;

}

bool DcmServer::createAssociation()
{
    result = Sender.negotiateAssociation();
    if (result.bad())
        return false;
    return true;

}

bool DcmServer::senFile(QString UrlPathDicom)
{
    result = Sender.sendSTORERequest(presID,UrlPathDicom.toLatin1().data(),NULL,msg,statusDetail,statusCode);
    if (result.good())
        return true;
    else
        return false;

}

bool DcmServer::queryDcm(QList<QueryData> *Patients)
{
    OFVector<QRResponse*> findResponses;
    DcmDataset req;
    req.insertEmptyElement(DCM_PatientName);
    req.insertEmptyElement(DCM_PatientID);
    req.insertEmptyElement(DCM_AccessionNumber);
    req.insertEmptyElement(DCM_StudyInstanceUID);
    req.insertEmptyElement(DCM_ModalitiesInStudy);
    req.insertEmptyElement(DCM_StudyDate);
    req.putAndInsertOFStringArray(DCM_QueryRetrieveLevel, "STUDY");
    req.putAndInsertOFStringArray(DCM_StudyInstanceUID, "");
    T_ASC_PresentationContextID presID = findUncompressedPC(UID_FINDStudyRootQueryRetrieveInformationModel, Sender);
    if (presID == 0)
    {
        DCMNET_ERROR("There is no uncompressed presentation context for Study Root FIND");
        return false;
    }
    result = Sender.sendFINDRequest(presID, &req,&findResponses);


    if (result.bad())
       return false;


    OFString NamePatient,PatientID,AccessionNumber,StudyInstanceUID,Modality,StudyDate;
    for (unsigned int i=0;i<findResponses.size();i++){
        if (findResponses.at(i)->m_dataset != NULL){
            result= findResponses.at(i)->m_dataset->findAndGetOFString(DCM_ModalitiesInStudy,Modality);
            result= findResponses.at(i)->m_dataset->findAndGetOFString(DCM_PatientName,NamePatient);
            result= findResponses.at(i)->m_dataset->findAndGetOFString(DCM_AccessionNumber,AccessionNumber);
            result= findResponses.at(i)->m_dataset->findAndGetOFString(DCM_PatientID,PatientID);
            result= findResponses.at(i)->m_dataset->findAndGetOFString(DCM_StudyInstanceUID,StudyInstanceUID);
            result= findResponses.at(i)->m_dataset->findAndGetOFString(DCM_StudyDate,StudyDate);


            Patients->append(QueryData(NamePatient.data(),
                                       PatientID.data(),
                                       AccessionNumber.data(),
                                       Modality.data(),
                                       StudyDate.data(),
                                       StudyInstanceUID.data()));
        }
    }
    return true;


}

bool DcmServer::cgetDcm()
{
    OFVector<RetrieveResponse*> findResponses;
    DcmDataset req;
//    req.putAndInsertString(DCM_PatientName,"Nurmukhametov");
//    req.putAndInsertString(DCM_SOPInstanceUID,"1.3.12.2.1107.5.4.5.55301.30000013021404234482800000106.512");
    req.putAndInsertString(DCM_SeriesInstanceUID,"1.3.12.2.1107.5.2.13.20561.30000005042216091690600002608");
    req.putAndInsertString(DCM_QueryRetrieveLevel,"SERIES");
//    req.putAndInsertString(DCM_SOPClassUID,"1.2.840.10008.5.1.4.1.1.4");
//    req.putAndInsertString(DCM_StudyInstanceUID,"1.2.840.113745.101000.1008000.38446.6272.7138759");

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

void DcmServer::setTransferSyntaxPresentationContext(QString transferSintax, QString SopClass)
{
    ts.push_back(transferSintax.toLatin1().data());
    Sender.addPresentationContext(SopClass.toLatin1().data(),ts);
}

void DcmServer::setTransferSyntaxPresentationContext(QString taskDicom)
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
        ts.push_back(UID_LittleEndianImplicitTransferSyntax);
        ts.push_back(UID_MRImageStorage);
        ts.push_back(UID_XRayAngiographicImageStorage);
        Sender.addPresentationContext(UID_GETStudyRootQueryRetrieveInformationModel,ts);
        Sender.addPresentationContext(UID_GETPatientRootQueryRetrieveInformationModel,ts);
        Sender.addPresentationContext(UID_RETIRED_GETPatientStudyOnlyQueryRetrieveInformationModel,ts);
        Sender.addPresentationContext(UID_MRImageStorage,ts);
    }
}

DcmServer::~DcmServer()
{
    Sender.closeAssociation(DCMSCU_RELEASE_ASSOCIATION);

}

Uint8 DcmServer::findUncompressedPC(const OFString &sopClass, DcmSCU &Sender)
{
    Uint8 pc;
    pc = Sender.findPresentationContextID(sopClass, UID_LittleEndianExplicitTransferSyntax);
    if (pc == 0)
        pc = Sender.findPresentationContextID(sopClass, UID_BigEndianExplicitTransferSyntax);
    if (pc == 0)
        pc = Sender.findPresentationContextID(sopClass, UID_LittleEndianImplicitTransferSyntax);
    return pc;

}
