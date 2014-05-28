#include "mainwindow.h"
#include <QApplication>
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QTextCodec *RusCodec = QTextCodec::codecForName( "UTF-8" );
//    QTextCodec::setCodecForCStrings( RusCodec );
//    QTextCodec::setCodecForTr( RusCodec );
    QApplication a(argc, argv);
    MainWindow w;
    w.show();  
    return a.exec();
}
