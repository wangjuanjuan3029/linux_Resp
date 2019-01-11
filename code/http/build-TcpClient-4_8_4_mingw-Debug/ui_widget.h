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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout;
    QTextEdit *textEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *lindit_serv_addr_2;
    QLabel *label_5;
    QLineEdit *linedit_server_port_2;
    QPushButton *btn_bind_2;
    QTextEdit *textEdit_2;
    QPushButton *btn_send;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(562, 386);
        gridLayout = new QGridLayout(Widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        textEdit = new QTextEdit(Widget);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        gridLayout->addWidget(textEdit, 1, 0, 1, 2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(Widget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);

        lindit_serv_addr_2 = new QLineEdit(Widget);
        lindit_serv_addr_2->setObjectName(QStringLiteral("lindit_serv_addr_2"));

        horizontalLayout_2->addWidget(lindit_serv_addr_2);

        label_5 = new QLabel(Widget);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_2->addWidget(label_5);

        linedit_server_port_2 = new QLineEdit(Widget);
        linedit_server_port_2->setObjectName(QStringLiteral("linedit_server_port_2"));

        horizontalLayout_2->addWidget(linedit_server_port_2);

        btn_bind_2 = new QPushButton(Widget);
        btn_bind_2->setObjectName(QStringLiteral("btn_bind_2"));

        horizontalLayout_2->addWidget(btn_bind_2);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 2);

        textEdit_2 = new QTextEdit(Widget);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));

        gridLayout->addWidget(textEdit_2, 3, 0, 1, 2);

        btn_send = new QPushButton(Widget);
        btn_send->setObjectName(QStringLiteral("btn_send"));

        gridLayout->addWidget(btn_send, 2, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 0, 1, 1);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0));
        label_3->setText(QApplication::translate("Widget", "\346\234\215\345\212\241\345\231\250IP", 0));
        label_5->setText(QApplication::translate("Widget", "\346\234\215\345\212\241\345\231\250Port", 0));
        btn_bind_2->setText(QApplication::translate("Widget", "\350\277\236\346\216\245", 0));
        btn_send->setText(QApplication::translate("Widget", "\345\217\221\351\200\201", 0));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
