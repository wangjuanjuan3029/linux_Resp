#include "widget.h"
#include "ui_widget.h"
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QFile>
#include <QDebug>
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
   QNetworkRequest request;
   QString url = ui->lineEdit->text();
   request.setUrl(QUrl(url));

   reply = manager->get(request);  //这里错误 没有改对

   connect(reply,SIGNAL(readyRead()),this,SLOT(doProcessReadyRead()));//绑定
   connect(reply,SIGNAL(finished),this,SLOT(doProcessFinished()));
   connect(reply,SIGNAL(downloadProgress(qint64 bytesReceived, qint64 bytesTotal)),this,SLOT(doProcessDownLoad()));
   connect(reply,SIGNAL(error(QNetworkReply::NetworkError code)),this,SLOT(doProcessError()));
   /** get()
    发布一个请求以获取目标请求的内容，
    并返回一个打开以供读取的新QNetworkReply对象，
    该对象在新数据到达时发出readyRead()信号。
    内容以及相关的标题将被下载。
     */\
   QStringList list = url.split('/');    //QStringList list1 = str.split(',');   list1: [ "a", "", "b", "c" ]
   QString filename = list.at(list.length()-1);

   qDebug()<<list;
   qDebug()<<filename;
   myFile->setFileName(filename);

   bool ret = myFile->open(QIODevice::WriteOnly | QIODevice::Truncate);
   if(!ret)  //打开失败
   {
        QMessageBox::warning(this,"warning","not open file!") ;
        return;
   }
    ui->progressBar->setMinimum(0);
    ui->progressBar->setValue(0);
}

void Widget::doProcessReadyRead()
{
    while(! reply->atEnd())
    {
        QByteArray ba = reply->readAll();
        myFile->write(ba);
    }

}

void Widget::doProcessFinished()
{
    myFile->close();
}

void Widget::doProcessDownLoad(qint64 bytesReceived, qint64 bytesTotal)
{
    //bytesReceived参数表示接收的字节数，而bytesTotal表示期望下载的总字节数。
   ui->progressBar->setMaximum(bytesReceived);
   ui->progressBar->setValue((int)bytesTotal);
}

void Widget::doProcessError(QNetworkReply::NetworkError code)
{
    qDebug()<<code;
}

void Widget::init()
{
    manager = new QNetworkAccessManager(this);
    myFile = new QFile(this); //分配空间
}
