#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>
#include <QFileDialog>
#include "serverinfoxml.h"
#include <showdicomform.h>
#include <querytable.h>
#include "serveredit.h"
#include <QDir>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    //    connect(ui->OKPushButton,SIGNAL(clicked()),this,SLOT(SenButton_clicked()));
    //    connect(ui->DirectoryButton,SIGNAL(clicked()),this,SLOT(DIRPushButton_clicked()));
    //    connect(ui->CancelPushButton,SIGNAL(clicked()),this,SLOT(close()));
    //    connect(ui->CheckEchoPushButton,SIGNAL(clicked()),this,SLOT(SetEchoButton_clicked()));
    //    connect(ui->WriteDataDicomButton,SIGNAL(clicked()),this,SLOT(SetWriteDatatoDicom()));
    //    connect(ui->ShowPushButton,SIGNAL(clicked()),this,SLOT(ShowClassButton()));
    //    connect(ui->QueryButton,SIGNAL(clicked()),this,SLOT(QueryButton()));
    //    connect(ui->LAETLE,SIGNAL(editingFinished()),this,SLOT(LAetSet()));
    //    connect(ui->GetButton,SIGNAL(clicked()),this,SLOT(GetTestSLOT()));
    //    ui->progressBar->setVisible(false);
    //    ui->WriteDataDicomButton->setVisible(false);
    //    ui->ShowPushButton->setVisible(false);
    //    LaetEdit = false;
    QString path = qgetenv("HOME") + "/.config/DcmViewer";
    QDir dir(path);
    if (!dir.exists()){
        dir.mkdir(path);
    }


    QList<ServerInfoClass >  ServerData ;
    ServerInfoDataModel = new ModelServerInfo;
    ServerInfoXML *readServerInfo = new ServerInfoXML();
    readServerInfo->readFileXML();
    ServerData = readServerInfo->returnServerInfo();
    // Заполняем модель данными
    for (int i =0;i<ServerData.size();i++)
        ServerInfoDataModel->list= (ServerData);
    // читаем файлы из каталога

    vtkSmartPointer<vtkDICOMImageReader> reader =
            vtkSmartPointer<vtkDICOMImageReader>::New();
    reader->SetFileName(QString("/tmp/dcmstorage/MR.1.3.12.2.1107.5.2.13.20561.30000005042216091690600002705").toLocal8Bit());
    reader->Update();
    // рисуем
    vtkSmartPointer<vtkImageViewer2> imageViewer =
            vtkSmartPointer<vtkImageViewer2>::New();
    imageViewer->SetInputConnection(reader->GetOutputPort());


    vtkSmartPointer<vtkActor> sphereActor =
          vtkSmartPointer<vtkActor>::New();
    sphereActor->SetMapper(imageViewer);

    vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor =
        vtkSmartPointer<vtkRenderWindowInteractor>::New();
    imageViewer->SetupInteractor(renderWindowInteractor);

    // VTK Renderer
    vtkSmartPointer<vtkRenderer> render =
            vtkSmartPointer<vtkRenderer>::New();
    render->AddActor(sphereActor);




    ui->qvtkWidgetShowImage->GetRenderWindow()->AddRenderer(render);

    //


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SenButton_clicked()
{
    //    if (!(ui->ServerLE->isModified()
    //          ||ui->PortLE->isModified()
    //          || ui->RAETLE->isModified()))
    {
        QMessageBox::critical(0,"Error", "Parameters not set");
        return;
    }
    //    if (!LaetEdit)
    //        ui->LAETLE->setText("SENDER");
    //    DcmSend sendDicom(ui->ServerLE->text(),ui->PortLE->text(),ui->RAETLE->text(),ui->LAETLE->text());
    //    ui->progressBar->setVisible(true);
    //    ui->progressBar->setMinimum(0);
    //    ui->progressBar->setMaximum(filename.returnCountFiles()-1);
    //    sendDicom.setTransferSyntaxPresentationContext(filename.returnTransferSyntax(),filename.returnSopClass());
    //    if (!sendDicom.initNetwork())
    //        QMessageBox::critical(0,"Error", "Нет возможности установить соединение с PACS сервер");
    //    if (!sendDicom.createAssociation())
    /*        QMessageBox::critical(0,"Error", "Нет возможности установить ассоциацию с PACS сервер");

    QList<QString> files=filename.returnFiles();
    for(int i=0;i<filename.returnCountFiles();i++){
        if (sendDicom.senFile(files.at(i)))
            ui->progressBar->setValue(i);
        else
            QMessageBox::critical(0,"Error", "Critical Error.Network config Error");

    }
    QMessageBox::information(0,"Information","OK");
    ui->progressBar->setVisible(false);
*/
}

void MainWindow::DIRPushButton_clicked()
{
    /*    ui->UrlDicomImages->setText(QFileDialog::getExistingDirectory(0,"Directory Dialog",QDir::homePath()));
    filename.setURLpath(ui->UrlDicomImages->text());
// Read Information of File
    QString Patient,PatientID,AccessionNumber;
   filename.OpenDcmFile(0);
    filename.ReadInfoDcmFilePatient(Patient);
    filename.ReadInfoDcmFilePatientID(PatientID);
    filename.ReadInfoDcmFilePatientAccess(AccessionNumber);
   ui->FioLineEdit->setText(Patient);
    ui->NumPacIDLineEdit->setText(PatientID);
    ui->AccessNumLineEdit->setText(AccessionNumber);
    ui->ModalityLineEdit->setText(dcmSOPClassUIDToModality(filename.returnSopClass().toLatin1().data()));
    ui->WriteDataDicomButton->setVisible(true);
    ui->ShowPushButton->setVisible(true);
*/
}

void MainWindow::SetEchoButton_clicked()
{
    /*    if (!(ui->ServerLE->isModified()
          ||ui->PortLE->isModified()
          || ui->RAETLE->isModified()))
    {
        QMessageBox::critical(0,"Error", "Параметры не заданы");
        return;
    }
    if (!LaetEdit)
        ui->LAETLE->setText("SENDER");
    DcmSend echoSend(ui->ServerLE->text(),ui->PortLE->text(),ui->RAETLE->text(),ui->LAETLE->text());
    echoSend.setTransferSyntaxPresentationContext(QString("echo"));
    if (!echoSend.initNetwork())
        QMessageBox::critical(0,"Error", "Нет возможности установить соединение с PACS сервер");
    if (!echoSend.createAssociation())
        QMessageBox::critical(0,"Error", "Нет возможности установить ассоциацию с PACS сервер");
    if (!echoSend.echoSend()){
        QMessageBox::critical(0,"Error","Critical Error.Network config Error");

    }
    else {
        QMessageBox::information(0,"Information","OK");
        qDebug() << "OK";
    }
    */
}


void MainWindow::SetWriteDatatoDicom()
{
    /*   QList<QString> files=filename.returnFiles();
    for(int i=0;i<filename.returnCountFiles();i++)
        if (filename.WriteDataToFile(files.at(i),ui->FioLineEdit->text().toLatin1().data(),ui->NumPacIDLineEdit->text().toLatin1().data(),ui->AccessNumLineEdit->text().toLatin1().data()))
            ui->progressBar->setValue(i);

*/
}

void MainWindow::ShowClassButton()
{
    showDicomForm *ShowForm= new showDicomForm();
    filename.CreateQimageDcmFile();
    ShowForm->setSize(*filename.s);
    ShowForm->setQimage(filename.ReadDicomData());
    qDebug() << *filename.s;
    ShowForm->show();
}

void MainWindow::QueryButton()
{
    /*    QList <QString> QueryPatientName,QueryPatientID,QueryAccessionNumber;
    queryTable *table= new queryTable();
    if (!(ui->ServerLE->isModified()
          ||ui->PortLE->isModified()
          || ui->RAETLE->isModified()))
    {
        QMessageBox::critical(0,"Error", "Parameters not set");
        return;
    }
    if (!LaetEdit)
        ui->LAETLE->setText("SENDER");
    DcmSend QueryDcm(ui->ServerLE->text(),ui->PortLE->text(),ui->RAETLE->text(),ui->LAETLE->text());
    QueryDcm.setTransferSyntaxPresentationContext(QString("query"));
    if (!QueryDcm.initNetwork())
        QMessageBox::critical(0,"Error", "Нет возможности установить соединение с PACS сервер");
    if (!QueryDcm.createAssociation())
        QMessageBox::critical(0,"Error", "Нет возможности установить ассоциацию с PACS сервер");
    if (!QueryDcm.queryDcm(QueryPatientName,QueryPatientID,QueryAccessionNumber))
        QMessageBox::critical(0,"Error", "Нет возможности установить соединение с PACS сервер");
    if (!table->SetPatientName(QueryPatientName) ||
        !table->setPatientID(QueryPatientID) ||
        !table->setAccessionNumber(QueryAccessionNumber)){
        QMessageBox::critical(0,"Error", "Нет возможности получить данные с PACS");
    }
    else {
    table->writeDataTableSpace();
    table->show();
    }
*/
}

void MainWindow::LAetSet()
{
    LaetEdit = true;
}

void MainWindow::GetTestSLOT()
{
    /*    if (!(ui->ServerLE->isModified()
          ||ui->PortLE->isModified()
          || ui->RAETLE->isModified()))
    {
        QMessageBox::critical(0,"Error", "Parameters not set");
        return;
    }
    if (!LaetEdit)
        ui->LAETLE->setText("SENDER");
    DcmSend QueryDcm(ui->ServerLE->text(),ui->PortLE->text(),ui->RAETLE->text(),ui->LAETLE->text());
    QueryDcm.setTransferSyntaxPresentationContext(QString("cget"));
    if (!QueryDcm.initNetwork())
        QMessageBox::critical(0,"Error", "Нет возможности установить соединение с PACS сервер");
    if (!QueryDcm.createAssociation())
        QMessageBox::critical(0,"Error", "Нет возможности установить ассоциацию с PACS сервер");
    if (!QueryDcm.cgetDcm())
        QMessageBox::critical(0,"Error", "Нет возможности установить соединение с PACS сервер");
*/
}



void MainWindow::on_actionSearchPatient_triggered()
{
    queryTable *table= new queryTable();
    table->setModelServerInfo(ServerInfoDataModel);
    table->show();

}

void MainWindow::on_actionServerList_triggered()
{
    ServerEdit *ServerEditWidget= new ServerEdit();
    ServerEditWidget->setModelServerInfo(ServerInfoDataModel);
    ServerEditWidget->show();

}

void MainWindow::on_actionOpenImageFromDir_triggered()
{
    QFileDialog::getExistingDirectory(0,"Directory Dialog",QDir::homePath());

}

void MainWindow::on_actionEditPatientSettings_triggered()
{

}
