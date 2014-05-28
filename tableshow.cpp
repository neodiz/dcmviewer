#include "tableshow.h"

TableShow::TableShow()
{
    this->setColumnCount(4);
    QStringList tableshow;
    tableshow << "ФИО пациента" << "Номер Пациента" << "Номер Услуги" << "Получить";
    this->setHorizontalHeaderLabels(tableshow);
}
