#include "widget.h"
#include "ui_widget.h"
#include <QToolTip>
#include <QTextEdit>
#include <QHelpEvent>

Widget::Widget(QWidget *parent) :
    QTextEdit(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
//    TextEdit(QWidget *parent = 0) : QTextEdit(parent)

    setFrameStyle(QFrame::NoFrame);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setText("hello Qt!");

}

Widget::~Widget()
{
    delete ui;
}

bool Widget::event(QEvent *event)
{
    if(event->type() == QEvent::ToolTip)
    {
        //QHelpEvent *helpEvent = static_cast (event);
        QHelpEvent *helpEvent = static_cast<QHelpEvent *>(event);
        QTextCursor cursor = cursorForPosition(helpEvent->pos());
        cursor.select(QTextCursor::WordUnderCursor);
        QToolTip::showText(helpEvent->globalPos(), cursor.selectedText());


        return true;
    }

    return QTextEdit::event(event);
}
