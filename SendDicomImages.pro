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
    dcmfile.cpp \
    showdicomform.cpp \
    querytable.cpp \
    querydata.cpp \
    serveredit.cpp \
    serverinfoclass.cpp \
    serverinfoxml.cpp \
    editaddformserver.cpp \
    dcmserver.cpp \
    modelserverinfo.cpp \
    modelpatientinfo.cpp


HEADERS  += mainwindow.h \
    dcmfile.h \
    showdicomform.h \
    querytable.h \
    querydata.h \
    serveredit.h \
    serverinfoclass.h \
    serverinfoxml.h \
    editaddformserver.h \
    dcmserver.h \
    modelserverinfo.h \
    modelpatientinfo.h


FORMS    += mainwindow.ui \
    showdicomform.ui \
    querytableform.ui \
    servereditform.ui \
    editaddformserver.ui


unix:!macx: LIBS = -ldcmnet -ldcmdata -lofstd -loflog -ldcmimgle -ldcmjpeg -lijg12 -lijg16 -lijg8 \
                -lvtkRenderingOpenGL \
                -lvtkGUISupportQt \
                -lvtkCommonCore \
                -lvtkInteractionStyle \
                -lvtkRenderingCore \
                -lvtkRenderingFreeType \
                -lvtkRenderingFreeTypeOpenGL


#-lIL -lILU -lILUT
win32:LIBS += -ldcmnet -ldcmdata -lofstd -loflog -ldcmimgle -ldcmjpeg -lijg12 -lijg16 -lijg8

RESOURCES += \
    ResourceMainWindowIcons.qrc \
    ServerInfoXml.qrc
INCLUDEPATH += /usr/include/vtk-6.0
LIBS += -L/usr/lib64/vtk/

