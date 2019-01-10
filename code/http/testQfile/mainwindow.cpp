#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QFile>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    QStringList list = url.split('/');    //QStringList list1 = str.split(',');   list1: [ "a", "", "b", "c" ]
//    QString filename = list.at(list.length()-1);
        qDebug()<<"22";
    myFile->setFileName("main.cpp");

    bool ret = myFile->open(QIODevice::WriteOnly | QIODevice::Truncate);
    if(!ret)  //打开失败
    {
         QMessageBox::warning(this,"warning","not open file!") ;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
