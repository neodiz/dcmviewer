#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProgressDialog>
#include <QApplication>
#include "dcmfile.h"
#include <QImage>
#include <QPainter>
#include "modelserverinfo.h"

#include <vtkDICOMImageReader.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
#include <vtkImageViewer2.h>
#include <vtkSmartPointer.h>


#include <vtkPolyDataMapper.h>
#include <vtkSphereSource.h>

#define vtkRenderingCore_AUTOINIT 4(vtkInteractionStyle,vtkRenderingFreeType,vtkRenderingFreeTypeOpenGL,vtkRenderingOpenGL)
#define vtkRenderingVolume_AUTOINIT 1(vtkRenderingVolumeOpenGL)


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
