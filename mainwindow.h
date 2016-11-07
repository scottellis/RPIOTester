#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSerialPort/QtSerialPort>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_i2tcheck_clicked();
    void showIMUData();

private:
    Ui::MainWindow *ui;
    QSerialPort* IMU;
    bool IMUButton;
    QString d;
    int count;
};

#endif // MAINWINDOW_H
