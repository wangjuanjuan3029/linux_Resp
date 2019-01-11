#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpServer>


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
    void on_btn_send_clicked();

    void doNewConnection();
    void doError(QAbstractSocket::SocketError socketError);
    void doDisconnected();
    void doReadyRead();
    void doConnected();



private:
    Ui::Widget *ui;
    QTcpServer* myserver;
    QList<QTcpSocket *> arrayClient;
    QTcpSocket *client;
    void init();
};

#endif // WIDGET_H
