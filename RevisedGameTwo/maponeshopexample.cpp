#include "maponeshopexample.h"
#include "ui_maponeshopexample.h"

mapOneShopExample::mapOneShopExample(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mapOneShopExample)
{
    ui->setupUi(this);
}

mapOneShopExample::~mapOneShopExample()
{
    delete ui;
}
