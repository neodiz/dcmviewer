#include "querydata.h"


QueryData::QueryData(QString PatientNameInput, QString PatientIDInput, QString AccessionNumberInput, QString ModalityUIDInput, QString StudyDateInput, QString StudyInstanceUIDInput)
{
    PatientName = PatientNameInput;
    PatientID= PatientIDInput;
    AccessionNumber= AccessionNumberInput;
    StudyInstanceUID= StudyInstanceUIDInput;
    Modality = ModalityUIDInput;
    StudyDate= StudyDateInput;
}

QueryData::QueryData()
{
    this->AccessionNumber="";
    this->PatientID="";
    this->PatientName="";
    this->StudyInstanceUID="";
    this->Modality="";
    this->StudyDate="";

}
