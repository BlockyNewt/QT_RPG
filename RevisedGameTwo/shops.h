#ifndef SHOPS_H
#define SHOPS_H

#include "ui_MapOneShop.h"
#include "item.h"

#include <QDialog>
#include <QVector>
#include <QString>
#include <QMediaPlayer>
#include <QLabel>
#include <QPushButton>

#include <QScrollBar>

namespace Ui
{
class MapOneShop;
}



class Shops
{
public:
    Shops();

    //ITEMS ARRAY - (TESTING)
    QVector<Item>allItems;
    //FOR GETTINGS ITEMS TO PUT INTO ARRAYS
    Bread bread;
    Chicken chicken;
    Sausage sausage;
    Item *itemBread = &bread;
    Item *itemChicken = &chicken;
    Item *itemSausage = &sausage;

    //ACCESSORS
    virtual inline const int& getGold() const {return this->gold;};
    virtual inline const int& getSilver() const {return this->silver;};
    virtual inline const int& getCopper() const {return this->copper;};

    //FUNCTIONS
    virtual void initShop();
    virtual void passMoneyToShop(int& gold, int& silver, int& copper);
    virtual void passSoundsToShop(QMediaPlayer *sound);


private:
    //VECTORS FOR TABLES
    QVector<QString>itemName;
    QVector<int>itemPrice;
    //PASSING MONEY THROUGH
    int gold;
    int silver;
    int copper;
    //PASSING SOUND THROUGH
    QMediaPlayer *sound;
};



class MapOneShop : public QDialog, public Shops
{
    Q_OBJECT

public:
    explicit MapOneShop(QWidget *parent = nullptr);
    ~MapOneShop();


    //PUSH BUTTONS
    QPushButton *buyB;
    //LABELS
    QLabel *goldLabel;

    //SCROLL BAR
    QScrollBar *hs;


    //PASSING INFORMATIONV
    QVector<QString>informationV;
    int moneyRecipt;
    QString recipt;



    //ACCESSORS
    inline const int& getGold() const {return this->gold;};
    inline const int& getSilver() const {return this->silver;};
    inline const int& getCopper() const {return this->copper;};

    //FUNCTIONS
    void initShop();
    void initItems();
    void passMoneyToShop(int& gold, int& silver, int& copper);
    void passSoundsToShop(QMediaPlayer *purchaseSound);
    //PASSING INFORMATIONV
    void passInformationVToMapOneShop(QVector<QString>&informationV);
    void updateInformationVAndMoneyAfterBuy();

    //TREE LIST WIDGET - (JUST FOR TESTING)
    void initShopList();



signals:
    //FOR PASSING REFERENCES THROUGH BUTTONS PRESSES
    void getUpdatedMoneyFromShop(const int& gold, const int& silver, const int& copper);
    void getUpdatedInformationVFromMapOneShop(QVector<QString>&informationV);
    void getItemFromMapOneShop(const QString& itemName, const QString& itemDescription);


private slots:
    void on_buyB_clicked();

private:
    Ui::MapOneShop *ui;

    //VECTORS FOR TABLES
    QVector<QString>itemName;
    QVector<QString>itemType;
    QVector<QString>itemEffectDescription;
    QVector<int>itemPrice;

    //PASSING MONEY THROUGH
    int gold, goldCheck;
    int silver, silverCheck;
    int copper, copperCheck;
    //PASSING SOUND THROUGH
    QMediaPlayer *purchaseSound;
};

#endif // SHOPS_H
