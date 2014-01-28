#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QString>
#include <QtGui>

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
    p.start("xsetwacom  --get \"Wacom Bamboo 2FG 6x8 Pen stylus\" mode");
    p.waitForFinished(-1);
    results = QString(p.readAll());
    qDebug() << results[0];
    if (results[0] == 'A') {
        ui->modeComboBox->setCurrentIndex(0);
    } else if (results[0] == 'R') {
        ui->modeComboBox->setCurrentIndex(0);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_eraserSensSlider_valueChanged(int position)
{
    ui->eraserSensLineEdit->setText(QString(QString::number(ui->eraserSensSlider->value())) + " %");
}

void MainWindow::on_tipSensSlider_valueChanged(int value)
{
    ui->tipSensLineEdit->setText(QString(QString::number(ui->tipSensSlider->value())) + " %");
}

void MainWindow::on_checkBox_released()
{
    QProcess p;

    // If touch is selected.
    if (ui->checkBox->isChecked()) {
        p.start("xsetwacom --set \"Wacom Bamboo 2FG 6x8 Finger touch\" touch on");
        p.waitForFinished(-1);
    // else, touch is not selected.
    } else {
        p.start("xsetwacom --set \"Wacom Bamboo 2FG 6x8 Finger touch\" touch off");
        p.waitForFinished(-1);
    }
}
