#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    char ret[1024*2023] = {0};
}

MainWindow::~MainWindow()
{
    delete ui;
}
