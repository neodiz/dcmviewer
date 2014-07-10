#include "dcmfile.h"


DcmFile::DcmFile()
{

}

DcmFile::~DcmFile()
{

}

int DcmFile::returnCountFiles()
{
    return list_.size();
}

void DcmFile::ReadInfoDcmFilePatient(QString &Patient)
{
    OFString PatientOF;
    if (DcmFilename_.getDataset()->findAndGetOFString(DCM_PatientName,PatientOF).good())
    {
        Patient = PatientOF.data();
    } else
        Patient = "NONE";

}

void DcmFile::ReadInfoDcmFilePatientID(QString &PatientID)
{
    OFString PatientIDOF;
    if (DcmFilename_.getDataset()->findAndGetOFString(DCM_PatientID, PatientIDOF).good())
    {
        PatientID = PatientIDOF.data();
    } else
        PatientID="NONE";

}

void DcmFile::ReadInfoDcmFilePatientAccess(QString &AccessionNumber)
{
    OFString AccessionNumberOF;
    if (DcmFilename_.getDataset()->findAndGetOFString(DCM_AccessionNumber,AccessionNumberOF).good())
    {
        AccessionNumber = AccessionNumberOF.data();
    } else
        AccessionNumber="NONE" ;

}

void DcmFile::CreateQimageDcmFile()
{
    DJDecoderRegistration::registerCodecs();
    xfer_ = DcmFilename_.getDataset()->getOriginalXfer();
    m_dicomImage_ = new DicomImage(&DcmFilename_,xfer_,CIF_AcrNemaCompatibility,0,0);
    s= new QSize(m_dicomImage_->getWidth(),m_dicomImage_->getHeight());

}

QImage DcmFile::ReadDicomData()
{


    QImage m_qimage;
    if(m_dicomImage_->isMonochrome()){
        m_qimage = QImage(m_dicomImage_->getWidth(),m_dicomImage_->getHeight(), QImage::Format_Indexed8);

    }
    m_dicomImage_->setMinMaxWindow();
    uchar *pixelData = (uchar *)(m_dicomImage_->getOutputData(8 /* bits */));
    for(unsigned y=0; y < m_dicomImage_->getHeight(); y++)
    {
        uchar* scanLine = m_qimage.scanLine(y);
        for(unsigned x = m_dicomImage_->getWidth(); x != 0; --x)
        {
            *(scanLine++) = *(pixelData++);
        }
    }
    DJDecoderRegistration::cleanup();
    return m_qimage;


}

QSize DcmFile::sizeDCMFile()
{

}

void DcmFile::OpenDcmFile(int i)
{
    result_ = DcmFilename_.loadFile(list_.at(i).absoluteFilePath().toLatin1().data());
    if (result_.bad())
            return;

}


QList<QString> DcmFile::returnFiles()
{
    QList<QString> files;
    for (int i=0;i<list_.size();i++){
        files.append(list_.at(i).absoluteFilePath().toLatin1().data());
    }
    return files;
}


void DcmFile::setURLpath(QString UrlPathDicom)
{
    QDir Directory(UrlPathDicom);
    Directory.setFilter(QDir::Files | QDir::NoDotAndDotDot |QDir::NoSymLinks);
    list_ = Directory.entryInfoList();
}


QString DcmFile::returnTransferSyntax()
{
     DcmXfer filexfer(DcmFilename_.getDataset()->getOriginalXfer());
    return filexfer.getXferID();
}

QString DcmFile::returnSopClass()
{
    OFString SopClass;
    DcmFilename_.getDataset()->findAndGetOFString(DCM_SOPClassUID,SopClass);
    return SopClass.data();
}


bool DcmFile::WriteDataToFile(QString UrlPathDicom,OFString Patient,OFString NumPatient,OFString AccesPatient)
{
    result_ = DcmFilename_.loadFile(UrlPathDicom.toLatin1().data());
    if (result_.bad())
        return false;
    result_ = DcmFilename_.loadAllDataIntoMemory();
    if (result_.bad()) {
        return false;
    }
    result_= DcmFilename_.getDataset()->putAndInsertString(DCM_PatientID,NumPatient.data());
    if (result_.bad())
        return false;
    result_= DcmFilename_.getDataset()->putAndInsertString(DCM_AccessionNumber,AccesPatient.data());
    if (result_.bad())
        return false;
    result_= DcmFilename_.getDataset()->putAndInsertString(DCM_PatientName,Patient.data());
    if (result_.bad())
        return false;
    result_ = DcmFilename_.saveFile(UrlPathDicom.toLatin1().data());
    if (result_.bad())
        return false;
    return true;
}
