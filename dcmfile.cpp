#include "dcmfile.h"


DcmFile::DcmFile()
{

}

DcmFile::~DcmFile()
{

}

int DcmFile::returnCountFiles()
{
    return list.size();
}

void DcmFile::ReadInfoDcmFilePatient(QString &Patient)
{
    OFString PatientOF;
    if (DcmFilename.getDataset()->findAndGetOFString(DCM_PatientName,PatientOF).good())
    {
        Patient = PatientOF.data();
    } else
        Patient = "NONE";

}

void DcmFile::ReadInfoDcmFilePatientID(QString &PatientID)
{
    OFString PatientIDOF;
    if (DcmFilename.getDataset()->findAndGetOFString(DCM_PatientID, PatientIDOF).good())
    {
        PatientID = PatientIDOF.data();
    } else
        PatientID="NONE";

}

void DcmFile::ReadInfoDcmFilePatientAccess(QString &AccessionNumber)
{
    OFString AccessionNumberOF;
    if (DcmFilename.getDataset()->findAndGetOFString(DCM_AccessionNumber,AccessionNumberOF).good())
    {
        AccessionNumber = AccessionNumberOF.data();
    } else
        AccessionNumber="NONE" ;

}

void DcmFile::CreateQimageDcmFile()
{
    DJDecoderRegistration::registerCodecs();
    xfer = DcmFilename.getDataset()->getOriginalXfer();
    m_dicomImage = new DicomImage(&DcmFilename,xfer,CIF_AcrNemaCompatibility,0,0);
    s= new QSize(m_dicomImage->getWidth(),m_dicomImage->getHeight());

}

QImage DcmFile::ReadDicomData()
{


    QImage m_qimage;
    if(m_dicomImage->isMonochrome()){
        m_qimage = QImage(m_dicomImage->getWidth(),m_dicomImage->getHeight(), QImage::Format_Indexed8);

    }
    m_dicomImage->setMinMaxWindow();
    uchar *pixelData = (uchar *)(m_dicomImage->getOutputData(8 /* bits */));
    for(unsigned y=0; y < m_dicomImage->getHeight(); y++)
    {
        uchar* scanLine = m_qimage.scanLine(y);
        for(unsigned x = m_dicomImage->getWidth(); x != 0; --x)
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
    result = DcmFilename.loadFile(list.at(i).absoluteFilePath().toLatin1().data());
    if (result.bad())
            return;

}


QList<QString> DcmFile::returnFiles()
{
    QList<QString> files;
    for (int i=0;i<list.size();i++){
        files.append(list.at(i).absoluteFilePath().toLatin1().data());
    }
    return files;
}


void DcmFile::setURLpath(QString UrlPathDicom)
{
    QDir Directory(UrlPathDicom);
    Directory.setFilter(QDir::Files | QDir::NoDotAndDotDot |QDir::NoSymLinks);
    list = Directory.entryInfoList();
}


QString DcmFile::returnTransferSyntax()
{
     DcmXfer filexfer(DcmFilename.getDataset()->getOriginalXfer());
    return filexfer.getXferID();
}

QString DcmFile::returnSopClass()
{
    OFString SopClass;
    DcmFilename.getDataset()->findAndGetOFString(DCM_SOPClassUID,SopClass);
    return SopClass.data();
}


bool DcmFile::WriteDataToFile(QString UrlPathDicom,OFString Patient,OFString NumPatient,OFString AccesPatient)
{
    result = DcmFilename.loadFile(UrlPathDicom.toLatin1().data());
    if (result.bad())
        return false;
    result = DcmFilename.loadAllDataIntoMemory();
    if (result.bad()) {
        return false;
    }
    result= DcmFilename.getDataset()->putAndInsertString(DCM_PatientID,NumPatient.data());
    if (result.bad())
        return false;
    result= DcmFilename.getDataset()->putAndInsertString(DCM_AccessionNumber,AccesPatient.data());
    if (result.bad())
        return false;
    result= DcmFilename.getDataset()->putAndInsertString(DCM_PatientName,Patient.data());
    if (result.bad())
        return false;
    result = DcmFilename.saveFile(UrlPathDicom.toLatin1().data());
    if (result.bad())
        return false;
    return true;
}
