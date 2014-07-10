#ifndef DCMSERVER_H
#define DCMSERVER_H
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
#include <modelpatientinfo.h>

class DcmServer
{
public:
    DcmServer(QString ipAddress,int portAddress,QString aeAddress,QString aeLocal);
    bool echoSend();
    bool initNetwork();
    bool createAssociation();
    bool senFile(QString UrlPathDicom);
    bool queryDcm(QList<QueryData> *Patients);
    bool cgetDcm();
    void setTransferSyntaxPresentationContext(QString transferSintax,QString SopClass);
    void setTransferSyntaxPresentationContext(QString taskDicom);
    QSize s;
    ~DcmServer();
private:
    T_ASC_PresentationContextID presID_ ;
    DcmDataset *statusDetail_;
    OFCondition result_;
    OFList<OFString> ts_;
    OFString soapClass_ ;
    DcmDataset *msg_ ;
    Uint16 statusCode_;
    DcmSCU  Sender_;
    Uint8 findUncompressedPC(const OFString& sopClass,DcmSCU& Sender);
};

#endif // DCMSERVER_H
