#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    serial = new QSerialPort();
    arduino_available = false;

    foreach (const QSerialPortInfo &serial_Info, QSerialPortInfo::availablePorts()) {
        qDebug()<<"Port: "<<serial_Info.portName();
        portname = serial_Info.portName();
        qDebug()<<"Vendor Id: "<<serial_Info.vendorIdentifier();
        vendorId = serial_Info.vendorIdentifier();
        qDebug()<<"Product Id: "<<serial_Info.productIdentifier();
        productId = serial_Info.productIdentifier();
        arduino_available = true;
    }
    if(arduino_available){
        arduino_init();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::arduino_init()
{
    serial->setPortName(portname);
    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);
    serial->open(QIODevice::ReadWrite);
    connect(serial, SIGNAL(readyRead()),this,SLOT(serial_read()));
}


void MainWindow::on_pushButton_ON_clicked()
{
    if (serial->isWritable()) {
        serial->write("2");
    }
}


void MainWindow::on_pushButton_OFF_clicked()
{
    if (serial->isWritable()) {
        serial->write("3");
    }
}

void MainWindow::serial_read()
{
    if(serial->isWritable()&&arduino_available) {
        QByteArray data = serial->readAll();
        qDebug()<<"Veri okuma"<<data.toInt();
        ui->lcdNumber->display(data.toInt());
    }
     if(ui->lcdNumber->value()>0) {
       QMessageBox::information(this,"Buton durumu","Butona basıldı");
    }

}
