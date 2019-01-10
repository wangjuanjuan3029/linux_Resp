#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QNetworkAccessManager>

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
    void on_btn_clicked();
    void doProcessFinished(QNetworkReply*);

private:
    Ui::Widget *ui;
    QNetworkAccessManager* manager;

    void init();
};

#endif // WIDGET_H
