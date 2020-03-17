#include "shops.h"

#include <QDebug>

Shops::Shops()
{
    allItems.push_back(*itemBread);
    allItems.push_back(*itemChicken);
    allItems.push_back(*itemSausage);
}

void Shops::initShop()
{

}

void Shops::passMoneyToShop(int &gold, int &silver, int &copper)
{
    this->gold = gold;
    this->silver = silver;
    this->copper = copper;
}

void Shops::passSoundsToShop(QMediaPlayer *sound)
{
    this->sound = sound;
}




/*
 *
 *
 *  MAP ONE SHOP BEGIN
 *
 */

MapOneShop::MapOneShop(QWidget *parent):
    QDialog(parent),
    ui(new Ui::MapOneShop)
{
    ui->setupUi(this);

    //WINDOW SETTINGS
    setWindowTitle("Shop");
    resize(500,500);

    //PUSH BUTTONS
    this->buyB = ui->buyB;
    buyB->setText("Buy");

    //LABELS
    this->goldLabel = ui->goldLabel;

    //tree widget
    ui->treeWidget->setColumnCount(4);
}

MapOneShop::~MapOneShop()
{
    delete ui;
}

void MapOneShop::initShop()
{
    //INIT ITEMS IN THIS FUNCTION
    initItems();
}

void MapOneShop::initItems()
{
    //THROW ALL THE ITEMS INTO DESIGNATED VECTORS
    //BREAD
    itemName.push_back(itemBread->getName());
    itemType.push_back(itemBread->getType());
    itemPrice.push_back(itemBread->getBuyValue());
    itemEffectDescription.push_back(itemBread->getEffectDescription());
    //CHICKEN
    itemName.push_back(itemChicken->getName());
    itemType.push_back(itemChicken->getType());
    itemPrice.push_back(itemChicken->getBuyValue());
    itemEffectDescription.push_back(itemChicken->getEffectDescription());
    //SAUSAGE
    itemName.push_back(itemSausage->getName());
    itemType.push_back(itemSausage->getType());
    itemPrice.push_back(itemSausage->getBuyValue());
    itemEffectDescription.push_back(itemSausage->getEffectDescription());

    //INIT SHOP LIST
    initShopList();
}

void MapOneShop::passMoneyToShop(int &gold, int &silver, int &copper)
{
    this->gold = gold;
    this->goldCheck = gold;
    goldLabel->setText(QString::number(gold));
    this->silver = silver;
    this->copper = copper;
}

void MapOneShop::passSoundsToShop(QMediaPlayer *purchaseSound)
{
    this->purchaseSound = purchaseSound;
}

void MapOneShop::passInformationVToMapOneShop(QVector<QString> &informationV)
{
    //SWAP SHOPS INFORMATIONV WITH GAMESCREEN INFORMATION V
    this->informationV.swap(informationV);
    //this->informationV = informationV;
}

void MapOneShop::updateInformationVAndMoneyAfterBuy()
{
    //UPDATE INFORMATIONV FIRST TO CHECK MONEY CHANGES

    if(goldCheck != gold)
    {
        //dont need money recipt
        moneyRecipt =  itemPrice[ui->treeWidget->indexOfTopLevelItem(ui->treeWidget->currentItem())];
        recipt = "You have lost " + QString::number(moneyRecipt) + " gold";
        this->informationV.push_back(recipt);

        //EMIT BACK
        emit getUpdatedInformationVFromMapOneShop(this->informationV);
        emit getUpdatedMoneyFromShop(gold, silver, copper);
        emit getItemFromMapOneShop(this->itemName[ui->treeWidget->indexOfTopLevelItem(ui->treeWidget->currentItem())], this->itemEffectDescription[ui->treeWidget->indexOfTopLevelItem(ui->treeWidget->currentItem())]);
    }
    if(silverCheck < this->silver)
    {
        moneyRecipt =  itemPrice[ui->treeWidget->indexOfTopLevelItem(ui->treeWidget->currentItem())];
        recipt = "You have lost " + QString::number(moneyRecipt) + " silver";
        this->informationV.push_back(recipt);
        emit getUpdatedInformationVFromMapOneShop(this->informationV);
    }
    if(copperCheck < this->copper)
    {
        moneyRecipt =  itemPrice[ui->treeWidget->indexOfTopLevelItem(ui->treeWidget->currentItem())];
        recipt = "You have lost " + QString::number(moneyRecipt) + " copper";
        this->informationV.push_back(recipt);
        emit getUpdatedInformationVFromMapOneShop(this->informationV);
    }

    //PASS BACK INFORMATIONV TO GAMESCREEN
    //emit getUpdatedInformationVFromMapOneShop(this->informationV);

    //UPDATE MONEY LABEL
    goldLabel->setText(QString::number(gold));

    //LET INVENTORY TAKE BACK MONEY
    //AND ADD ITEM DETAILS - (TESTING)

}

void MapOneShop::initShopList()
{
    QString Twi = "itm";
    for(int i = 0; i < itemName.size(); i++)
    {
        //RESET NAME
        Twi = "itm-";
        Twi+=QString::number(i);

        //SET TREEWIDGETITEM NAME TO TWI TO AUTOMATICALLY CREATE NAMES
        QTreeWidgetItem *Twi = new QTreeWidgetItem(ui->treeWidget);
        Twi->setText(0,itemName[i]);
        Twi->setText(1,QString::number(itemPrice[i]));
        Twi->setText(2,itemType[i]);
        Twi->setText(3,itemEffectDescription[i]);
    }
}

void MapOneShop::on_buyB_clicked()
{
    //ONLY WORKS IF I HIT THE ITEM NAME COLUMN THEN HIT BUY
    gold -= itemPrice[ui->treeWidget->indexOfTopLevelItem(ui->treeWidget->currentItem())];

    purchaseSound->stop();
    purchaseSound->play();

    //UPDATE INFORMATION
    updateInformationVAndMoneyAfterBuy();

}

