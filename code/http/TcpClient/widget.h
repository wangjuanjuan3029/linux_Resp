#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpSocket>

//客户端
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
    void on_btn_bind_2_clicked();

    void doConnected();
    void doReadyRead();
    void doDisconnected();
    void doError(QAbstractSocket::SocketError);

    void on_btn_send_clicked();

private:
    Ui::Widget *ui;
    QTcpSocket* myClient;//定义客户端

    void init();

};

#endif // WIDGET_H
