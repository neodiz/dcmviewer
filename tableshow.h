#ifndef TABLESHOW_H
#define TABLESHOW_H

#include <QTableWidget>

class TableShow : public QTableWidget
{
public:
    TableShow();
private:
    static QSize myGetQTableWidgetSize();

};

#endif // TABLESHOW_H
