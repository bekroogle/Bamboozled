#include <QtGui/QApplication>
#include "mainwindow.h"
#include <QProcess>
#include <QDebug>
#include <QString>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("BAMBOOzled");
    w.show();
    
    return a.exec();
}
