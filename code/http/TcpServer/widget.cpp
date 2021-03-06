#include "widget.h"
#include "ui_widget.h"
#include <QNetworkInterface>
#include <QDebug>
#include <QTcpSocket>

#define MAXNUM 100

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
    myserver = new QTcpServer(this);

    ui->lindit_serv_addr->setText("10.7.3.78");
    ui->linedit_server_port->setText("8888");
}
void Widget::on_btn_bind_clicked()
{
   //方法1，通过程序遍历ip
    QString myAddr;
//    QList<QHostAddress> addrs = QNetworkInterface::allAddresses();
//    for(int  i = 0;i<addrs.length();i++)
//    {
//        //qDebug()<<addrs[1];
//        QHostAddress addr =addrs.at(i);
//        qDebug()<<addr.toString();
//        if(addr.toString().contains("10."))
//        {
//            myAddr = addr.toString();
//            break;
//        }
//    }
    //方法2.手动设置ip
    myAddr = ui->lindit_serv_addr->text();
    QString myPort = ui->linedit_server_port->text();
    bool ret = myserver->listen(QHostAddress(myAddr),myPort.toUInt());
    //listen 告诉服务器侦听地址、地址和端口端口上的传入连接
    QString msg;
    if(!ret)
    {
        msg = "bind false";
    }
    else
    {
        msg = "bind sucess";
        ui->btn_bind->setEnabled(false);
    }
    ui->textEdit->append(msg);
    myserver->setMaxPendingConnections(MAXNUM);//将挂起的已接受连接的最大数量设置
    /**
将挂起的已接受连接的最大数量设置为numConnections。
在调用nextPendingConnection()之前，
QTcpServer接受的传入连接不会超过numConnections。
默认情况下，限制是30个挂起的连接。
在服务器达到最大挂起连接数(即挂起连接数)之后，
客户机仍然可以连接。， QTcpSocket仍然可以发出connected()信号。
QTcpServer将停止接受新连接，但操作系统仍可能将它们保留在队列中。
     */
    connect(myserver,SIGNAL(newConnection()),this,SLOT(doNewConnection()));

    connect(myserver,SIGNAL(acceptError(QAbstractSocket::SocketError socketError)),this,SLOT(doError(QAbstractSocket::SocketError socketError)));

}

void Widget::doNewConnection()
{

}

void Widget::doError(QAbstractSocket::SocketError socketError)
{
    qDebug()<<socketError;
}

void Widget::doDisconnected()
{
    QTcpSocket *client = (QTcpSocket*)this->sender();//强制转换
    QString msg = "disconnect";
    ui->textEdit->append(msg);

    //删除对应客户端
    for(int i=0;i<arrayClient.length();i++)
    {
        if(arrayClient.at(i)->peerAddress() == client->peerAddress())
        {
            if(arrayClient.at(i)->peerPort() == client->peerPort())
            {
                arrayClient.removeAt(i);
                break;
            }
        }
    }

}

void Widget::doReadyRead()
{
     QTcpSocket *client = (QTcpSocket*)this->sender();
     QString str1 = QString("client speak");
     QString msg;
     QString str2;
     while(!client->atEnd())
     {
        msg.append(QString(client->readAll()));
     }
     str2 = QString("%1").arg(str1);
     ui->textEdit->append(msg);
}

void Widget::doConnected()
{
    QTcpSocket *client = (QTcpSocket*)this->sender();
    QString msg = QString("client connected").arg(client->peerAddress().toString()).arg(client->peerPort());
    ui->textEdit->append(msg);
}

void Widget::on_btn_send_clicked()
{
    QString ip = ui->lindit_client_addr->text();
    QString port = ui->linedit_client_port->text();
    qDebug()<<ip;
    qDebug()<<port;
    //查找对应的客户
    QString msg = ui->textEdit_2->toPlainText();
    client->write(msg.toUtf8());

//    for(int i=0;i<arrayClient.length();i++)
//    {
//        if(arrayClient.at(i)->peerAddress().toString() == ip)
//        {
//            if(arrayClient.at(i)->peerPort() == port.toUInt())
//            {
//                QString msg = ui->textEdit_2->toPlainText();
//                arrayClient.at(i)->write(msg.toUtf8());
//                break;
//            }
//        }
//    }
}
