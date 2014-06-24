#-------------------------------------------------
#
# Project created by QtCreator 2013-04-02T13:29:09
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SendDicomImages
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dcmsend.cpp \
    dcmfile.cpp \
    showdicomform.cpp \
    querytable.cpp \
    querydata.cpp \
    datatablemodel.cpp


HEADERS  += mainwindow.h \
    dcmsend.h \
    dcmfile.h \
    showdicomform.h \
    querytable.h \
    querydata.h \
    datatablemodel.h


FORMS    += mainwindow.ui \
    showdicomform.ui \
    querytableform.ui


unix:!macx: LIBS = -ldcmnet -ldcmdata -lofstd -loflog -ldcmimgle -ldcmjpeg -lijg12 -lijg16 -lijg8
#-lIL -lILU -lILUT
win32:LIBS += -ldcmnet -ldcmdata -lofstd -loflog -ldcmimgle -ldcmjpeg -lijg12 -lijg16 -lijg8



