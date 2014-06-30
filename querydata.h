#ifndef QUERYDATA_H
#define QUERYDATA_H
#include <QString>
class QueryData
{
public:
    QueryData(QString PatientNameInput,QString PatientIDInput,QString AccessionNumberInput,QString ModalityUIDInput,QString StudyDateInput,QString StudyInstanceUIDInput);
    QueryData();
    QString PatientName;
    QString PatientID;
    QString AccessionNumber;
    QString StudyInstanceUID;
    QString Modality;
    QString StudyDate;

};

#endif // QUERYDATA_H
