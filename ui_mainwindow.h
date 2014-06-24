/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSearchPatient;
    QAction *actionServerList;
    QAction *actionOpenImageFromDir;
    QAction *actionEditPatientSettings;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(775, 604);
        actionSearchPatient = new QAction(MainWindow);
        actionSearchPatient->setObjectName(QStringLiteral("actionSearchPatient"));
        QIcon icon;
        icon.addFile(QStringLiteral("find.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSearchPatient->setIcon(icon);
        actionServerList = new QAction(MainWindow);
        actionServerList->setObjectName(QStringLiteral("actionServerList"));
        QIcon icon1;
        icon1.addFile(QStringLiteral("Servers.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionServerList->setIcon(icon1);
        actionOpenImageFromDir = new QAction(MainWindow);
        actionOpenImageFromDir->setObjectName(QStringLiteral("actionOpenImageFromDir"));
        QIcon icon2;
        icon2.addFile(QStringLiteral("folder.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpenImageFromDir->setIcon(icon2);
        actionEditPatientSettings = new QAction(MainWindow);
        actionEditPatientSettings->setObjectName(QStringLiteral("actionEditPatientSettings"));
        QIcon icon3;
        icon3.addFile(QStringLiteral("edit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionEditPatientSettings->setIcon(icon3);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 775, 19));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(actionServerList);
        toolBar->addAction(actionSearchPatient);
        toolBar->addAction(actionOpenImageFromDir);
        toolBar->addAction(actionEditPatientSettings);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Send Images", 0));
        actionSearchPatient->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\270\321\201\320\272 \320\277\320\260\321\206\320\270\320\265\320\275\321\202\320\260 \320\275\320\260 \321\201\320\265\321\200\320\262\320\265\321\200\320\265 PACS", 0));
        actionServerList->setText(QApplication::translate("MainWindow", "\320\241\320\277\320\270\321\201\320\276\320\272 \320\241\320\265\321\200\320\262\320\265\321\200\320\276\320\262 PACS", 0));
        actionOpenImageFromDir->setText(QApplication::translate("MainWindow", "OpenImageFromDir", 0));
        actionEditPatientSettings->setText(QApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \320\230\321\201\321\201\320\273\320\265\320\264\320\276\320\262\320\260\320\275\320\270\320\265", 0));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
