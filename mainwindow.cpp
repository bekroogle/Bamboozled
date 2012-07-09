#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QProcess p;

    p.start("xsetwacom --get \"Wacom Bamboo 2FG 6x8 Finger touch\" Touch");
    p.waitForFinished(-1);

    QString results = QString(p.readAll());
    if (results[1] == 'f') {
        ui->checkBox->setChecked(false);
    } else if (results[1] == 'n') {
        ui->checkBox->setChecked(true);
    }
    qDebug() << results[1];

}

MainWindow::~MainWindow()
{
    delete ui;
}