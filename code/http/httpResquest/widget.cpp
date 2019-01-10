#include "widget.h"
#include "ui_widget.h"
#include <QNetworkAccessManager>
#include <QDebug>
#include <QNetworkRequest>
#include <QNetworkReply>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //QNetworkAccessManager Class
    //需求：下载网页内容
    init();  //调用函数
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_btn_clicked()
{
    QString url = ui->lineEdit->text();
    manager->get(QNetworkRequest(QUrl(url)));
}

void Widget::init()
{
    manager = new QNetworkAccessManager(this);
    connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(doProcessFinished(QNetworkReply*)));
}
//槽
void Widget::doProcessFinished(QNetworkReply *reply)
{
    QString str = reply->readAll();
    qDebug()<<str;
    ui->textEdit->setText(str);
}
