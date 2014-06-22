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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *UrlDicomImages;
    QPushButton *DirectoryButton;
    QHBoxLayout *horizontalLayout_3;
    QLabel *FIO_label;
    QLineEdit *FioLineEdit;
    QHBoxLayout *horizontalLayout_11;
    QLabel *NumPacIDLabel;
    QLineEdit *NumPacIDLineEdit;
    QHBoxLayout *horizontalLayout_6;
    QLabel *AccessNumLabel;
    QLineEdit *AccessNumLineEdit;
    QHBoxLayout *horizontalLayout_10;
    QLabel *AccessNumLabel_2;
    QLineEdit *ModalityLineEdit;
    QHBoxLayout *horizontalLayout_12;
    QPushButton *ShowPushButton;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *WriteDataDicomButton;
    QProgressBar *progressBar;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_9;
    QLabel *ServerLabel;
    QLineEdit *ServerLE;
    QHBoxLayout *horizontalLayout_8;
    QLabel *PortLabel;
    QLineEdit *PortLE;
    QHBoxLayout *horizontalLayout_7;
    QLabel *RAETLabel;
    QLineEdit *RAETLE;
    QHBoxLayout *horizontalLayout_4;
    QLabel *LAETLabel;
    QLineEdit *LAETLE;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *QueryButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *CheckEchoPushButton;
    QHBoxLayout *horizontalLayout;
    QPushButton *OKPushButton;
    QPushButton *CancelPushButton;
    QPushButton *GetButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(775, 604);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setAutoFillBackground(false);
        verticalLayout_3 = new QVBoxLayout(groupBox_3);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        UrlDicomImages = new QLineEdit(groupBox_3);
        UrlDicomImages->setObjectName(QStringLiteral("UrlDicomImages"));
        UrlDicomImages->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout_2->addWidget(UrlDicomImages);

        DirectoryButton = new QPushButton(groupBox_3);
        DirectoryButton->setObjectName(QStringLiteral("DirectoryButton"));
        DirectoryButton->setMaximumSize(QSize(50, 16777215));
        DirectoryButton->setSizeIncrement(QSize(0, 0));

        horizontalLayout_2->addWidget(DirectoryButton);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        FIO_label = new QLabel(groupBox_3);
        FIO_label->setObjectName(QStringLiteral("FIO_label"));

        horizontalLayout_3->addWidget(FIO_label);

        FioLineEdit = new QLineEdit(groupBox_3);
        FioLineEdit->setObjectName(QStringLiteral("FioLineEdit"));

        horizontalLayout_3->addWidget(FioLineEdit);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        NumPacIDLabel = new QLabel(groupBox_3);
        NumPacIDLabel->setObjectName(QStringLiteral("NumPacIDLabel"));

        horizontalLayout_11->addWidget(NumPacIDLabel);

        NumPacIDLineEdit = new QLineEdit(groupBox_3);
        NumPacIDLineEdit->setObjectName(QStringLiteral("NumPacIDLineEdit"));

        horizontalLayout_11->addWidget(NumPacIDLineEdit);


        verticalLayout_3->addLayout(horizontalLayout_11);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        AccessNumLabel = new QLabel(groupBox_3);
        AccessNumLabel->setObjectName(QStringLiteral("AccessNumLabel"));

        horizontalLayout_6->addWidget(AccessNumLabel);

        AccessNumLineEdit = new QLineEdit(groupBox_3);
        AccessNumLineEdit->setObjectName(QStringLiteral("AccessNumLineEdit"));

        horizontalLayout_6->addWidget(AccessNumLineEdit);


        verticalLayout_3->addLayout(horizontalLayout_6);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        AccessNumLabel_2 = new QLabel(groupBox_3);
        AccessNumLabel_2->setObjectName(QStringLiteral("AccessNumLabel_2"));

        horizontalLayout_10->addWidget(AccessNumLabel_2);

        ModalityLineEdit = new QLineEdit(groupBox_3);
        ModalityLineEdit->setObjectName(QStringLiteral("ModalityLineEdit"));
        ModalityLineEdit->setMouseTracking(false);
        ModalityLineEdit->setReadOnly(true);

        horizontalLayout_10->addWidget(ModalityLineEdit);


        verticalLayout_3->addLayout(horizontalLayout_10);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        ShowPushButton = new QPushButton(groupBox_3);
        ShowPushButton->setObjectName(QStringLiteral("ShowPushButton"));

        horizontalLayout_12->addWidget(ShowPushButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_2);

        WriteDataDicomButton = new QPushButton(groupBox_3);
        WriteDataDicomButton->setObjectName(QStringLiteral("WriteDataDicomButton"));
        WriteDataDicomButton->setEnabled(true);

        horizontalLayout_12->addWidget(WriteDataDicomButton);


        verticalLayout_3->addLayout(horizontalLayout_12);


        gridLayout->addWidget(groupBox_3, 0, 1, 1, 1);

        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(24);

        gridLayout->addWidget(progressBar, 1, 0, 1, 1);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setAutoFillBackground(false);
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        ServerLabel = new QLabel(groupBox);
        ServerLabel->setObjectName(QStringLiteral("ServerLabel"));

        horizontalLayout_9->addWidget(ServerLabel);

        ServerLE = new QLineEdit(groupBox);
        ServerLE->setObjectName(QStringLiteral("ServerLE"));

        horizontalLayout_9->addWidget(ServerLE);


        verticalLayout_2->addLayout(horizontalLayout_9);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        PortLabel = new QLabel(groupBox);
        PortLabel->setObjectName(QStringLiteral("PortLabel"));

        horizontalLayout_8->addWidget(PortLabel);

        PortLE = new QLineEdit(groupBox);
        PortLE->setObjectName(QStringLiteral("PortLE"));

        horizontalLayout_8->addWidget(PortLE);


        verticalLayout_2->addLayout(horizontalLayout_8);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        RAETLabel = new QLabel(groupBox);
        RAETLabel->setObjectName(QStringLiteral("RAETLabel"));

        horizontalLayout_7->addWidget(RAETLabel);

        RAETLE = new QLineEdit(groupBox);
        RAETLE->setObjectName(QStringLiteral("RAETLE"));

        horizontalLayout_7->addWidget(RAETLE);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        LAETLabel = new QLabel(groupBox);
        LAETLabel->setObjectName(QStringLiteral("LAETLabel"));

        horizontalLayout_4->addWidget(LAETLabel);

        LAETLE = new QLineEdit(groupBox);
        LAETLE->setObjectName(QStringLiteral("LAETLE"));

        horizontalLayout_4->addWidget(LAETLE);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        QueryButton = new QPushButton(groupBox);
        QueryButton->setObjectName(QStringLiteral("QueryButton"));

        horizontalLayout_5->addWidget(QueryButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        CheckEchoPushButton = new QPushButton(groupBox);
        CheckEchoPushButton->setObjectName(QStringLiteral("CheckEchoPushButton"));

        horizontalLayout_5->addWidget(CheckEchoPushButton);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        OKPushButton = new QPushButton(groupBox);
        OKPushButton->setObjectName(QStringLiteral("OKPushButton"));

        horizontalLayout->addWidget(OKPushButton);

        CancelPushButton = new QPushButton(groupBox);
        CancelPushButton->setObjectName(QStringLiteral("CancelPushButton"));

        horizontalLayout->addWidget(CancelPushButton);


        verticalLayout_2->addLayout(horizontalLayout);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);

        GetButton = new QPushButton(centralWidget);
        GetButton->setObjectName(QStringLiteral("GetButton"));
        GetButton->setAutoDefault(true);

        gridLayout->addWidget(GetButton, 1, 1, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 775, 19));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        QWidget::setTabOrder(ServerLE, PortLE);
        QWidget::setTabOrder(PortLE, RAETLE);
        QWidget::setTabOrder(RAETLE, LAETLE);
        QWidget::setTabOrder(LAETLE, UrlDicomImages);
        QWidget::setTabOrder(UrlDicomImages, DirectoryButton);
        QWidget::setTabOrder(DirectoryButton, FioLineEdit);
        QWidget::setTabOrder(FioLineEdit, ModalityLineEdit);
        QWidget::setTabOrder(ModalityLineEdit, CheckEchoPushButton);
        QWidget::setTabOrder(CheckEchoPushButton, OKPushButton);
        QWidget::setTabOrder(OKPushButton, CancelPushButton);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Send Images", 0));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "\320\237\321\203\321\202\321\214 \320\264\320\276 Dicom \321\201\320\275\320\270\320\274\320\272\320\276\320\262:", 0));
        DirectoryButton->setText(QApplication::translate("MainWindow", "...", 0));
        FIO_label->setText(QApplication::translate("MainWindow", "\320\244\320\230\320\236:", 0));
        NumPacIDLabel->setText(QApplication::translate("MainWindow", "\320\235\320\276\320\274\320\265\321\200\n"
"\320\237\320\260\321\206\320\270\320\265\320\275\321\202\320\260:", 0));
        AccessNumLabel->setText(QApplication::translate("MainWindow", "\320\235\320\276\320\274\320\265\321\200 \n"
"\320\270\321\201\321\201\320\273\320\265\320\264\320\276\320\262\320\260\320\275\320\270\321\217:", 0));
        AccessNumLabel_2->setText(QApplication::translate("MainWindow", "\320\234\320\276\320\264\320\260\320\273\321\214\320\275\320\276\321\201\321\202\321\214:", 0));
        ShowPushButton->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\276\321\201\320\274\320\276\321\202\321\200\320\265\321\202\321\214", 0));
        WriteDataDicomButton->setText(QApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \320\241\320\265\321\200\320\262\320\265\321\200\320\260:", 0));
        ServerLabel->setText(QApplication::translate("MainWindow", "IP \320\260\320\264\321\200\320\265\321\201 \n"
"\321\201\320\265\321\200\320\262\320\265\321\200\320\260", 0));
        PortLabel->setText(QApplication::translate("MainWindow", "\320\237\320\276\321\200\321\202 \n"
"\321\201\320\265\321\200\320\262\320\265\321\200\320\260", 0));
        RAETLabel->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\265\320\275\320\275\321\213\320\271\n"
" AET", 0));
        LAETLabel->setText(QApplication::translate("MainWindow", "\320\233\320\276\320\272\320\260\320\273\321\214\320\275\321\213\320\271 \n"
"AET", 0));
        QueryButton->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\277\321\200\320\276\321\201\320\270\321\202\321\214", 0));
        CheckEchoPushButton->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\276\320\262\320\265\321\200\320\270\321\202\321\214", 0));
        OKPushButton->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214", 0));
        CancelPushButton->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\274\320\265\320\275\320\260", 0));
        GetButton->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
