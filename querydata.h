#ifndef QUERYDATA_H
#define QUERYDATA_H
#include <QString>
class QueryData
{
public:
    QueryData(QString PatientNameInput,QString PatientIDInput,QString AccessionNumberInput);
    QueryData();
    QString PatientName;
    QString PatientID;
    QString AccessionNumber;

};

#endif // QUERYDATA_H
