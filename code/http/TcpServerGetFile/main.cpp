#include "widget.h"
#include <QApplication>
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();

    QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf-8"));
    w.setWindowTitle("TCP Server file");

    return a.exec();
}
