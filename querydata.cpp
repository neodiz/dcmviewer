#include "querydata.h"


QueryData::QueryData(QString PatientNameInput, QString PatientIDInput, QString AccessionNumberInput, QString ModalityUIDInput, QString StudyDateInput, QString StudyInstanceUIDInput)
{
    PatientName_ = PatientNameInput;
    PatientID_= PatientIDInput;
    AccessionNumber_= AccessionNumberInput;
    StudyInstanceUID_= StudyInstanceUIDInput;
    Modality_ = ModalityUIDInput;
    StudyDate_= StudyDateInput;
}

QueryData::QueryData()
{
    this->AccessionNumber_="";
    this->PatientID_="";
    this->PatientName_="";
    this->StudyInstanceUID_="";
    this->Modality_="";
    this->StudyDate_="";

}
