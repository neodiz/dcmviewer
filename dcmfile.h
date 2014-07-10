#ifndef DCMFILE_H
#define DCMFILE_H
#include <QString>
#include <QDir>
#include <QFileInfoList>
#include <dcmtk/dcmdata/dcfilefo.h>
#include <dcmtk/dcmimgle/diutils.h>
#include <dcmtk/dcmdata/dcdeftag.h>
#include <dcmtk/config/osconfig.h>
#include <dcmtk/ofstd/ofcond.h>
#include <dcmtk/dcmjpeg/djdecode.h>
#include <dcmtk/dcmimgle/dcmimage.h>

#include <QSize>
#include <QDebug>
#include <QList>
#include <QImage>


class DcmFile
{
public:
    DcmFile();
    ~DcmFile();
    QString returnSopClass();
    QString returnTransferSyntax();
    QList<QString> returnFiles();
    int returnCountFiles();
    void ReadInfoDcmFilePatient(QString &Patient);
    void ReadInfoDcmFilePatientID(QString &PatientID);
    void ReadInfoDcmFilePatientAccess(QString &AccessionNumber);
    void CreateQimageDcmFile();
    QImage ReadDicomData();
    QSize sizeDCMFile();
    QSize* s;
    void OpenDcmFile(int i);
    void setURLpath(QString UrlPathDicom);
    bool WriteDataToFile(QString UrlPathDicom,OFString Patient,OFString NumPatient,OFString AccesPatient);

private:
    DcmFileFormat DcmFilename_;
    OFCondition result_;
    QFileInfoList list_;
    DicomImage* m_dicomImage_;
    E_TransferSyntax xfer_;
};

#endif // DCMFILE_H
