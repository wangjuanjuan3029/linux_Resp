#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QFile>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_btn_bind_clicked();
    void doNewConnection();
    void doReadyRead();

private:
    Ui::Widget *ui;
    QTcpServer* myserver;
    QTcpSocket* client;
    qint64 recvTotal;  //接收的大小
    qint64 total;      //总共的大小
    QFile* myfile;


    const int MAXNUM = 100;
    void init();

};

#endif // WIDGET_H
