#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
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
    void doConnected();

    void on_btn_file_clicked();

private:
    Ui::Widget *ui;
    QTcpSocket* myclient;
    QFile* myfile;
    qint64 totalSize;
    qint64 sendSize;
    qint64 len;

    void init();
};

#endif // WIDGET_H
