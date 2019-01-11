#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();

    //功能：鼠标移动至某单词之上，先进行取词，然后进行翻译！
    return a.exec();
}
