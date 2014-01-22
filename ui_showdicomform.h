/********************************************************************************
** Form generated from reading UI file 'showdicomform.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWDICOMFORM_H
#define UI_SHOWDICOMFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_showDicomForm
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QLabel *label_4;
    QLineEdit *lineEdit_3;
    QLabel *label_5;
    QComboBox *comboBox;
    QLabel *label_6;
    QComboBox *comboBox_2;
    QSpacerItem *verticalSpacer_2;
    QPushButton *CloseButton;

    void setupUi(QWidget *showDicomForm)
    {
        if (showDicomForm->objectName().isEmpty())
            showDicomForm->setObjectName(QString::fromUtf8("showDicomForm"));
        showDicomForm->resize(718, 604);
        horizontalLayout = new QHBoxLayout(showDicomForm);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(showDicomForm);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(500, 200));

        horizontalLayout->addWidget(label);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_2 = new QLabel(showDicomForm);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        lineEdit = new QLineEdit(showDicomForm);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        verticalLayout_2->addWidget(lineEdit);

        label_3 = new QLabel(showDicomForm);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_2->addWidget(label_3);

        lineEdit_2 = new QLineEdit(showDicomForm);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        verticalLayout_2->addWidget(lineEdit_2);

        label_4 = new QLabel(showDicomForm);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_2->addWidget(label_4);

        lineEdit_3 = new QLineEdit(showDicomForm);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        verticalLayout_2->addWidget(lineEdit_3);

        label_5 = new QLabel(showDicomForm);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_2->addWidget(label_5);

        comboBox = new QComboBox(showDicomForm);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        verticalLayout_2->addWidget(comboBox);

        label_6 = new QLabel(showDicomForm);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_2->addWidget(label_6);

        comboBox_2 = new QComboBox(showDicomForm);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));

        verticalLayout_2->addWidget(comboBox_2);


        verticalLayout->addLayout(verticalLayout_2);

        verticalSpacer_2 = new QSpacerItem(100, 100, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        CloseButton = new QPushButton(showDicomForm);
        CloseButton->setObjectName(QString::fromUtf8("CloseButton"));

        verticalLayout->addWidget(CloseButton);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(showDicomForm);

        QMetaObject::connectSlotsByName(showDicomForm);
    } // setupUi

    void retranslateUi(QWidget *showDicomForm)
    {
        showDicomForm->setWindowTitle(QApplication::translate("showDicomForm", "\320\237\321\200\320\276\321\201\320\274\320\276\321\202 \320\230\320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\321\217", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        label_2->setText(QApplication::translate("showDicomForm", "\320\244\320\230\320\236", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("showDicomForm", "\320\235\320\276\320\274\320\265\321\200 \321\203\321\201\320\273\321\203\320\263\320\270", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("showDicomForm", "\320\235\320\276\320\274\320\265\321\200 \320\270\321\201\321\201\320\273\320\265\320\264\320\276\320\262\320\260\320\275\320\270\321\217", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("showDicomForm", "\320\242\320\270\320\277 \320\270\321\201\321\201\320\273\320\265\320\264\320\276\320\262\320\260\320\275\320\270\321\217", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("showDicomForm", "\320\242\320\270\320\277 \321\201\320\266\320\260\321\202\320\270\321\217", 0, QApplication::UnicodeUTF8));
        CloseButton->setText(QApplication::translate("showDicomForm", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class showDicomForm: public Ui_showDicomForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWDICOMFORM_H
