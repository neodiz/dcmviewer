#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProgressDialog>
#include <QApplication>
#include "dcmfile.h"
#include <QImage>
#include <qdicomimage.h>
#include <QPainter>
#include "modelserverinfo.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    DcmFile filename;
private:
    Ui::MainWindow *ui;
    bool LaetEdit;
    ModelServerInfo *ServerInfoDataModel;

private slots:
    void SenButton_clicked();
    void DIRPushButton_clicked();
    void SetEchoButton_clicked();
    void SetWriteDatatoDicom();
    void ShowClassButton();
    void QueryButton();
    void LAetSet();
    void GetTestSLOT();

    void on_actionSearchPatient_triggered();
    void on_actionServerList_triggered();
    void on_actionOpenImageFromDir_triggered();
    void on_actionEditPatientSettings_triggered();
};

#endif // MAINWINDOW_H
