
#include "widget.h"
#include "ui_widget.h"

#include <QNetworkAccessManager>
#include <QHostAddress>

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
    myClient = new QTcpSocket(this);
    ui->lindit_serv_addr_2->setText("10.7.3.78");
    ui->linedit_server_port_2->setText("8888");
}
void Widget::on_btn_bind_2_clicked()   //点击绑定按钮事件
{
    QString serverIp = ui->lindit_serv_addr_2->text();
    QString serverPort = ui->linedit_server_port_2->text();
    myClient->connectToHost(serverIp,serverPort.toUInt());//尝试连接到给定端口上的主机名

    connect(myClient,SIGNAL(connected()),this,SLOT(doConnected()));
    connect(myClient,SIGNAL(readyRead()),this,SLOT(doReadyRead()));
    connect(myClient,SIGNAL(disconnected()),this,SLOT(doDisconnected()));
    connect(myClient,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(doError(QAbstractSocket::SocketError)));




}
void Widget ::doConnected()
{
    QString msg = "connected sucess";
    ui->textEdit->append(msg);
    ui->btn_bind_2->setEnabled(false);
}

void Widget::doReadyRead()
{
    QString msg,str1,str2;
    str1 = QString("server%1:%2speak:").arg(myClient->peerAddress().toString()).arg(myClient->peerPort());
    while(!myClient->atEnd())
    {
        str2.append(QString(myClient->readAll()));
    }
    msg = QString("%1%2").arg(str1).arg(str2);
    ui->textEdit->append(msg);
}

void Widget::doDisconnected()
{
    QString msg = "server quit";
    ui->textEdit->append(msg);
    ui->btn_bind_2->setEnabled(true);
}

void Widget::doError(QAbstractSocket::SocketError error)
{
    qDebug()<<error;
}

void Widget::on_btn_send_clicked()
{
    QString msg = ui->textEdit_2->toPlainText();
    myClient->write(msg.toUtf8());
}
