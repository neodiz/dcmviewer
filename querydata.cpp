#include "querydata.h"

QueryData::QueryData(QString PatientNameInput, QString PatientIDInput, QString AccessionNumberInput,QString StudyInstanceUIDInput,QString ModalityInput)
{
    PatientName = PatientNameInput;
    PatientID= PatientIDInput;
    AccessionNumber= AccessionNumberInput;
    StudyInstanceUID= StudyInstanceUIDInput;
    Modality = ModalityInput;

}

QueryData::QueryData()
{
    this->AccessionNumber="";
    this->PatientID="";
    this->PatientName="";
    this->StudyInstanceUID="";
    this->Modality="";

}
