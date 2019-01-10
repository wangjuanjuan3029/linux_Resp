#include "widget.h"
#include "ui_widget.h"
#include <QNetworkRequest>  //加载发送请求头文件
#include <QDebug>

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

void Widget::on_pushButton_clicked()
{
    QNetworkRequest request;
    QString url_str = ui->lineEdit->text();
    QUrl url;
    url.setUrl(url_str);
    request.setUrl(url);
    request.setRawHeader("User-Agent", "MyOwnBrowser 1.0");

    reply =  manager->get(request);
    connect(reply,SIGNAL(readyRead()),this,SLOT(doProcessReadyRead()));
    connect(reply, SIGNAL(error(QNetworkReply::NetworkError)),this, SLOT(doProcessError(QNetworkReply::NetworkError)));
    connect(reply, SIGNAL(finished()),this, SLOT(doProcessFinshed()));
}

void Widget::doProcessReadyRead()
{
    QString str = reply->readAll();
    ui->textEdit->setText(str);
}

void Widget::doProcessError(QNetworkReply::NetworkError error)
{
    switch ((int)error) {
    case QNetworkReply::ConnectionRefusedError:
        qDebug()<<"ConnectionRefusedError";
        break;
    default:
        break;
    }
}

void Widget::doProcessFinshed()
{
    qDebug()<<"finished..";
}

void Widget::init()
{
    manager =  new QNetworkAccessManager(this);

}
