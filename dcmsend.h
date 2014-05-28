#ifndef DCMSEND_H
#define DCMSEND_H
#include "dcmtk/ofstd/ofstd.h"
#include "dcmtk/ofstd/ofconapp.h"
#include "dcmtk/ofstd/ofstring.h"
#include "dcmtk/ofstd/ofstream.h"
#include "dcmtk/dcmnet/dicom.h"      /* for DICOM_APPLICATION_REQUESTOR */
#include "dcmtk/dcmnet/dimse.h"
#include "dcmtk/dcmnet/diutil.h"
#include "dcmtk/dcmnet/dcasccfg.h"   /* for class DcmAssociationConfiguration */
#include "dcmtk/dcmnet/dcasccff.h"   /* for class DcmAssociationConfigurationFile */
#include "dcmtk/dcmdata/dcdatset.h"
#include "dcmtk/dcmdata/dcmetinf.h"
#include "dcmtk/dcmdata/dcfilefo.h"
#include "dcmtk/dcmdata/dcuid.h"
#include "dcmtk/dcmdata/dcdict.h"
#include "dcmtk/dcmdata/dcdeftag.h"
#include "dcmtk/dcmdata/cmdlnarg.h"
#include "dcmtk/dcmnet/scu.h"
#include "dcmtk/dcmdata/dcistrmf.h"
#include <dcmtk/dcmnet/scu.h>
#include <QString>
#include <QDir>
#include <QDebug>
#include <QSize>

struct Patient {
    QString NamePatient;
    QString AccessionNumber;
    QString PatientID;
};

class DcmSend
{
public:
    DcmSend(QString ipAddress,QString portAddress,QString aeAddress,QString aeLocal);
    DcmSCU  Sender;
    bool echoSend();
    bool initNetwork();
    bool createAssociation();
    bool senFile(QString UrlPathDicom);
    bool queryDcm(QList<QString> &QueryPatientName,QList<QString> &QueryPatientID,QList<QString> &QueryAccessionNumber);
    bool cgetDcm();
    void setTransferSyntaxPresentationContext(QString transferSintax,QString SopClass);
    void setTransferSyntaxPresentationContext(QString taskDicom);
    ~DcmSend();
    QSize s;
private:
    T_ASC_PresentationContextID presID ;
    DcmDataset *statusDetail = NULL;
    OFCondition result;
    OFList<OFString> ts;
    OFString soapClass ;
    DcmDataset *msg = NULL;
    Uint16 statusCode;
    Uint8 findUncompressedPC(const OFString& sopClass,DcmSCU& Sender);



};

#endif // DCMSEND_H
