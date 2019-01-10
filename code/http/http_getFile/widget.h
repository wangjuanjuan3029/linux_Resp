#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QNetworkAccessManager> //加载网络请求头文件
#include <QNetworkReply>
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
    void on_pushButton_clicked();
    void doProcessReadyRead();
    void doProcessFinished();
    void doProcessDownLoad(qint64 bytesReceived, qint64 bytesTotal);
    void doProcessError(QNetworkReply::NetworkError code);
private:
    Ui::Widget *ui;
    QNetworkAccessManager* manager;
    QNetworkReply* reply;
    QFile* myFile;

    void init();
};

#endif // WIDGET_H
