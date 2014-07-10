#ifndef QUERYDATA_H
#define QUERYDATA_H
#include <QString>
class QueryData
{
public:
    QueryData(QString PatientNameInput,QString PatientIDInput,QString AccessionNumberInput,QString ModalityUIDInput,QString StudyDateInput,QString StudyInstanceUIDInput);
    QueryData();
    QString PatientName_;
    QString PatientID_;
    QString AccessionNumber_;
    QString StudyInstanceUID_;
    QString Modality_;
    QString StudyDate_;

};

#endif // QUERYDATA_H
