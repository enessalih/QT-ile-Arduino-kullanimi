#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_ON_clicked();

    void on_pushButton_OFF_clicked();

    void serial_read();

private:
    Ui::MainWindow *ui;
    QSerialPort *serial;
    QString portname;
    quint16 vendorId;
    quint16 productId;
    bool arduino_available;
    void arduino_init();
};
#endif // MAINWINDOW_H
