/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QTextEdit *textEdit;
    QLineEdit *linedit_client_port;
    QLabel *label_3;
    QLineEdit *lindit_client_addr;
    QLabel *label_4;
    QPushButton *btn_send;
    QTextEdit *textEdit_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lindit_serv_addr;
    QLabel *label_2;
    QLineEdit *linedit_server_port;
    QPushButton *btn_bind;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(500, 371);
        textEdit = new QTextEdit(Widget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(10, 60, 471, 101));
        linedit_client_port = new QLineEdit(Widget);
        linedit_client_port->setObjectName(QStringLiteral("linedit_client_port"));
        linedit_client_port->setGeometry(QRect(280, 182, 133, 20));
        label_3 = new QLabel(Widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(21, 181, 48, 23));
        lindit_client_addr = new QLineEdit(Widget);
        lindit_client_addr->setObjectName(QStringLiteral("lindit_client_addr"));
        lindit_client_addr->setGeometry(QRect(75, 182, 133, 20));
        label_4 = new QLabel(Widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(214, 181, 60, 23));
        btn_send = new QPushButton(Widget);
        btn_send->setObjectName(QStringLiteral("btn_send"));
        btn_send->setGeometry(QRect(419, 181, 75, 23));
        textEdit_2 = new QTextEdit(Widget);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));
        textEdit_2->setGeometry(QRect(20, 240, 471, 101));
        widget = new QWidget(Widget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 20, 475, 25));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lindit_serv_addr = new QLineEdit(widget);
        lindit_serv_addr->setObjectName(QStringLiteral("lindit_serv_addr"));

        horizontalLayout->addWidget(lindit_serv_addr);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        linedit_server_port = new QLineEdit(widget);
        linedit_server_port->setObjectName(QStringLiteral("linedit_server_port"));

        horizontalLayout->addWidget(linedit_server_port);

        btn_bind = new QPushButton(widget);
        btn_bind->setObjectName(QStringLiteral("btn_bind"));

        horizontalLayout->addWidget(btn_bind);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0));
        label_3->setText(QApplication::translate("Widget", "\345\256\242\346\210\267\347\253\257IP", 0));
        label_4->setText(QApplication::translate("Widget", "\345\256\242\346\210\267\347\253\257Port", 0));
        btn_send->setText(QApplication::translate("Widget", "\345\217\221\351\200\201", 0));
        label->setText(QApplication::translate("Widget", "\346\234\215\345\212\241\345\231\250IP", 0));
        label_2->setText(QApplication::translate("Widget", "\346\234\215\345\212\241\345\231\250Port", 0));
        btn_bind->setText(QApplication::translate("Widget", "\347\273\221\345\256\232", 0));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
