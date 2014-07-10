#include "dcmserver.h"


DcmServer::DcmServer(QString ipAddress, int portAddress, QString aeAddress, QString aeLocal)
{
    Sender_.setAETitle(aeLocal.toLatin1().data());
    Sender_.setPeerAETitle(aeAddress.toLatin1().data());
    Sender_.setPeerHostName(ipAddress.toLatin1().data());
    Sender_.setPeerPort(portAddress);
    presID_ = 0;
    msg_ = NULL;
    statusDetail_ = NULL;

}

bool DcmServer::echoSend()
{
    result_ =Sender_.sendECHORequest(0);
    if (result_.bad())
        return false;
    return true;

}

bool DcmServer::initNetwork()
{
    result_ =Sender_.initNetwork();
    if (result_.bad()){
        return false;
    }
    return true;

}

bool DcmServer::createAssociation()
{
    result_ = Sender_.negotiateAssociation();
    if (result_.bad())
        return false;
    return true;

}

bool DcmServer::senFile(QString UrlPathDicom)
{
    result_ = Sender_.sendSTORERequest(presID_,UrlPathDicom.toLatin1().data(),NULL,msg_,statusDetail_,statusCode_);
    if (result_.good())
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
    T_ASC_PresentationContextID presID_ = findUncompressedPC(UID_FINDStudyRootQueryRetrieveInformationModel, Sender_);
    if (presID_ == 0)
    {
        DCMNET_ERROR("There is no uncompressed presentation context for Study Root FIND");
        return false;
    }
    result_ = Sender_.sendFINDRequest(presID_, &req,&findResponses);


    if (result_.bad())
       return false;


    OFString NamePatient,PatientID,AccessionNumber,StudyInstanceUID,Modality,StudyDate;
    for (unsigned int i=0;i<findResponses.size();i++){
        if (findResponses.at(i)->m_dataset != NULL){
            result_= findResponses.at(i)->m_dataset->findAndGetOFString(DCM_ModalitiesInStudy,Modality);
            result_= findResponses.at(i)->m_dataset->findAndGetOFString(DCM_PatientName,NamePatient);
            result_= findResponses.at(i)->m_dataset->findAndGetOFString(DCM_AccessionNumber,AccessionNumber);
            result_= findResponses.at(i)->m_dataset->findAndGetOFString(DCM_PatientID,PatientID);
            result_= findResponses.at(i)->m_dataset->findAndGetOFString(DCM_StudyInstanceUID,StudyInstanceUID);
            result_= findResponses.at(i)->m_dataset->findAndGetOFString(DCM_StudyDate,StudyDate);


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

    Sender_.setStorageMode(DCMSCU_STORAGE_DISK);
    Sender_.setStorageDir("/tmp/dcmstorage");
//    req.putAndInsertOFStringArray(DCM_QueryRetrieveLevel, "STUDY");
//    req.putAndInsertOFStringArray(DCM_StudyInstanceUID, "");
    T_ASC_PresentationContextID presID_ = findUncompressedPC(UID_GETStudyRootQueryRetrieveInformationModel, Sender_);
    if (presID_ == 0)
    {
        DCMNET_ERROR("There is no uncompressed presentation context for Study Root FIND");
        return false;
    }
    result_=Sender_.sendCGETRequest(presID_,&req,&findResponses);
    if (result_.bad())
        return false;
    return true;


}

void DcmServer::setTransferSyntaxPresentationContext(QString transferSintax, QString SopClass)
{
    ts_.push_back(transferSintax.toLatin1().data());
    Sender_.addPresentationContext(SopClass.toLatin1().data(),ts_);
}

void DcmServer::setTransferSyntaxPresentationContext(QString taskDicom)
{
    if (taskDicom == "echo"){
      ts_.push_back(UID_LittleEndianImplicitTransferSyntax);
      Sender_.addPresentationContext(UID_VerificationSOPClass,ts_);

    }
    else if (taskDicom == "query" ){
      ts_.push_back(UID_LittleEndianImplicitTransferSyntax);
      Sender_.addPresentationContext(UID_FINDStudyRootQueryRetrieveInformationModel,ts_);
    }
    else if (taskDicom == "cget") {

        ts_.push_back(UID_JPEGLSLosslessTransferSyntax);
        ts_.push_back(UID_JPEGLSLossyTransferSyntax);
        ts_.push_back(UID_LittleEndianImplicitTransferSyntax);
        ts_.push_back(UID_MRImageStorage);
        ts_.push_back(UID_XRayAngiographicImageStorage);
        Sender_.addPresentationContext(UID_GETStudyRootQueryRetrieveInformationModel,ts_);
        Sender_.addPresentationContext(UID_GETPatientRootQueryRetrieveInformationModel,ts_);
        Sender_.addPresentationContext(UID_RETIRED_GETPatientStudyOnlyQueryRetrieveInformationModel,ts_);
        Sender_.addPresentationContext(UID_MRImageStorage,ts_);
    }
}

DcmServer::~DcmServer()
{
    Sender_.closeAssociation(DCMSCU_RELEASE_ASSOCIATION);

}

Uint8 DcmServer::findUncompressedPC(const OFString &sopClass, DcmSCU &Sender_)
{
    Uint8 pc;
    pc = Sender_.findPresentationContextID(sopClass, UID_LittleEndianExplicitTransferSyntax);
    if (pc == 0)
        pc = Sender_.findPresentationContextID(sopClass, UID_BigEndianExplicitTransferSyntax);
    if (pc == 0)
        pc = Sender_.findPresentationContextID(sopClass, UID_LittleEndianImplicitTransferSyntax);
    return pc;

}
