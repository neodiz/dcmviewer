#include "querydata.h"

QueryData::QueryData(QString PatientNameInput, QString PatientIDInput, QString AccessionNumberInput)
{
    PatientName = PatientNameInput;
    PatientID= PatientIDInput;
    AccessionNumber= AccessionNumberInput;

}

QueryData::QueryData()
{
    this->AccessionNumber="";
    this->PatientID="";
    this->PatientName="";

}
