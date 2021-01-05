#include "MyGrows.h"
#include "ui_MyGrows.h"

MyGrows::MyGrows(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyGrows)
{
    ui->setupUi(this);
}

MyGrows::~MyGrows()
{
    delete ui;
}
