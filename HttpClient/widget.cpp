#include "widget.h"
#include "ui_widget.h"
#include "QHttpClient.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QHttpClient("www.baidu222.com").get();
}

Widget::~Widget()
{
    delete ui;
}

