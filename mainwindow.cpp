#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // setting up IMU
    IMU = new QSerialPort;
    IMU->setPortName("ttyAMA0");
    IMU->setBaudRate(QSerialPort::Baud9600);
    IMU->setParity(QSerialPort::NoParity);
    IMU->setDataBits(QSerialPort::Data8);
    IMU->setStopBits(QSerialPort::OneStop);
    IMU->setFlowControl(QSerialPort::NoFlowControl);
    connect(IMU,SIGNAL(readyRead()),this,SLOT(showIMUData()));
    IMUButton = false;
    count = 0;


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_i2tcheck_clicked()
{
    if (IMUButton == false){
        IMU->open(QIODevice::ReadWrite);
        IMUButton = true;
    }else{

        IMU->close();
        IMUButton = false;
    }

}

void MainWindow::showIMUData()
{
    if (count < 5){
        QString imuData = QString::fromStdString(IMU->readAll().toStdString());
        d.append("\n");
        d.append(imuData);
        ui->IMUOutText->setPlainText(d);
        count +=1;
    }else{
        count = 0;
        d.clear();
        QString imuData = QString::fromStdString(IMU->readAll().toStdString());
        d.append(imuData);
        ui->IMUOutText->setPlainText(d);

    }


}
