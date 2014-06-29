#-------------------------------------------------
#
# Project created by QtCreator 2013-04-02T13:29:09
#
#-------------------------------------------------

QT       += core gui xml

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
    datatablemodel.cpp \
    serveredit.cpp \
    serveinfordatamodel.cpp \
    serverinfoclass.cpp \
    serverinfoxml.cpp \
    editaddformserver.cpp


HEADERS  += mainwindow.h \
    dcmsend.h \
    dcmfile.h \
    showdicomform.h \
    querytable.h \
    querydata.h \
    datatablemodel.h \
    serveredit.h \
    serveinfordatamodel.h \
    serverinfoclass.h \
    serverinfoxml.h \
    editaddformserver.h


FORMS    += mainwindow.ui \
    showdicomform.ui \
    querytableform.ui \
    servereditform.ui \
    editaddformserver.ui


unix:!macx: LIBS = -ldcmnet -ldcmdata -lofstd -loflog -ldcmimgle -ldcmjpeg -lijg12 -lijg16 -lijg8
#-lIL -lILU -lILUT
win32:LIBS += -ldcmnet -ldcmdata -lofstd -loflog -ldcmimgle -ldcmjpeg -lijg12 -lijg16 -lijg8

RESOURCES += \
    ResourceMainWindowIcons.qrc \
    ServerInfoXml.qrc



