#ifndef QUERYDATA_H
#define QUERYDATA_H
#include <QString>
class QueryData
{
public:
    QueryData(QString PatientNameInput,QString PatientIDInput,QString AccessionNumberInput,QString StudyInstanceUID,QString Modality);
    QueryData();
    QString PatientName;
    QString PatientID;
    QString AccessionNumber;
    QString StudyInstanceUID;
    QString Modality;

};

#endif // QUERYDATA_H
