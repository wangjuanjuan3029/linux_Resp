#include "widget.h"
#include "ui_widget.h"
#include <QTcpSocket>
#include <QMessageBox>

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

void Widget::on_btn_bind_clicked()
{
    QString myAddr = ui->linedit_serv_addr->text();
    QString myPort = ui->linedit_server_port->text();


    QString msg ;
    bool ret = myserver->listen(QHostAddress(myAddr),myPort.toUInt());

    //listen 告诉服务器侦听地址、地址和端口端口上的传入连接
    qDebug()<<"hahha";
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

    connect(myserver,SIGNAL(newConnection()),this,SLOT(doNewConnection()));

    connect(myserver,SIGNAL(acceptError(QAbstractSocket::SocketError socketError)),this,SLOT(doError(QAbstractSocket::SocketError socketError)));

}
void Widget::init()
{
    recvTotal = 0;

    total = 0;
    myfile = new QFile(this);
    ui->linedit_serv_addr->setText("10.7.3.78");
    ui->linedit_server_port->setText("8888");
}

void Widget::doNewConnection()
{
    client = myserver->nextPendingConnection();//将下一个挂起的连接作为已连接的QTcpSocket对象返回。

    QString msg = QString("client:%1:%2 coming:").arg(client->peerAddress().toString()).arg(client->peerPort());
    ui->textEdit->append(msg);

    //读取内容
    connect(client,SIGNAL(readyRead()),this,SLOT(doReadyRead()));

}

void Widget::doReadyRead()
{
    QByteArray ba = client->readAll();
    //第一次接收数据
    if(this->recvTotal == 0)
    {
        this->total = 0;
        //获取客户端发送过来的文件名及需要上传的文件大小
        //eg :filename#totaosize
        QStringList list = QString(ba).split("#");
        QString filename = list.at(0);
        this->total = QString(list.at(1)).toLongLong();
        this->total = total + ba.length();
        this->recvTotal += ba.length();
        //打开文件
        myfile->setFileName(filename);
        int ret = myfile->open(QIODevice::ReadOnly | QIODevice::Truncate);
        if(!ret)
        {
            this->recvTotal = 0;
            QMessageBox::warning(this,"warning","creat file false!");
            return;
        }
        QString msg = QString("recving file...").arg(filename);
        ui->textEdit->append(msg);
        ui->progressBar->setRange(0,total);
    }
    else
    {
        //真正接收数据
        qint64 len = myfile->write(ba);
        this->recvTotal = len;
    }
    //更新进度条
    ui->progressBar->setValue(this->recvTotal);

    //判断是否接收完毕
   if(this->recvTotal == this->total)
   {
       myfile->close();
       this->recvTotal = 0;
       this->total = 0;
       QString msg = "recv file sucess!";
       ui->textEdit->append(msg);
   }


}
















