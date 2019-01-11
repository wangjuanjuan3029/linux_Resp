#include "widget.h"
#include "ui_widget.h"
#include <QNetworkAccessManager>
#include <QFileDialog>
#include <QFile>

#define MSG_LEN 1024*2

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    init();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::init()
{
    totalSize = 0;
    sendSize = 0;

    myclient = new QTcpSocket(this);
    myfile = new QFile(this);

    ui->linedit_serv_addr->setText("10.7.3.78");
    ui->linedit_server_port->setText("8888");
}
void Widget::on_btn_bind_clicked()
{
    QString serverPort = ui->linedit_server_port->text();
    myclient->connectToHost("mytest",serverPort.toUInt());
    connect(myclient,SIGNAL(connected()),this,SLOT(doConnected()));
}
void Widget::doConnected()
{
    QString msg = "connected sercer sucess!";
    ui->textEdit->append(msg);
    ui->btn_bind->setEnabled(false);
}

void Widget::on_btn_file_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,"uploading file","E:/");
    if(filename.isEmpty())
        return;
    QString msg = QString("准备发送%1文件").arg(filename);
    ui->textEdit->append(msg);

    myfile->setFileName(filename);
    bool ret = myfile->open(QIODevice::ReadOnly | QIODevice::Truncate);
    if(!ret)
    {
        return;
    }
    ui->progressBar->setValue(0);
    this->totalSize = 0;
    this->sendSize = 0;

    //获取文件大小
    this->totalSize = myfile->size();
    ui->progressBar->setRange(0,this->totalSize);
    msg = QString("文件总大小为：%1").arg(totalSize);
    //发送头给服务器  filaname#totalsize
    QFileInfo info(filename);
    msg = QString("%1#%2").arg(info.fileName()).arg(this->totalSize);
    myclient->write(msg.toUtf8());

    //准备便读文件边发送数据
    while(!myfile->atEnd())
    {
        QByteArray ba = myfile->read(MSG_LEN);
        len = myclient->write(ba);
        //this->sendSize += len; //这个地方报错
        this->sendSize += len;
        //this->sendSize += (qint64)len;
        ui->progressBar->setValue(this->sendSize);
    }

    myfile->close();

    if(this->totalSize == this->sendSize)
    {
        msg = QString("上传文件成功！");
    }
    else
    {
        msg = QString("上传文件失败！totalsize:%d,sendsize:%d...").arg(this->totalSize).arg(this->sendSize);
    }
    ui->textEdit->append(msg);
}
















