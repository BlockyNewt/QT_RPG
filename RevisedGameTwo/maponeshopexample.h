#ifndef MAPONESHOPEXAMPLE_H
#define MAPONESHOPEXAMPLE_H

#include <QDialog>

namespace Ui {
class mapOneShopExample;
}

class mapOneShopExample : public QDialog
{
    Q_OBJECT

public:
    explicit mapOneShopExample(QWidget *parent = nullptr);
    ~mapOneShopExample();

private:
    Ui::mapOneShopExample *ui;
};

#endif // MAPONESHOPEXAMPLE_H
