#include "item.h"

Item::Item(QString name, int level, int buyValue, int sellValue, QString type)
{
    this->name = name;
    this->type = type;
    this->effectDescription = "NONE";
    this->level = level;
    this->buyValue = buyValue;
    this->sellValue = sellValue;
    this->hpRestore = 0;
    this->mpRestore = 0;
}

Item::~Item()
{

}

void Item::itemUse(int &hp, int &mp)
{
    hp += hpRestore;
    mp += mpRestore;
}


Bread::Bread()
{
    this->name = "Bread";
    this->type = "Food";
    this->effectDescription = "Restores 2 mana points.";
    this->level = 0;
    this->buyValue = 2;
    this->sellValue = 0;
    this->hpRestore = 0;
    this->mpRestore = 2;
}

Bread::~Bread()
{

}

void Bread::itemUse(int &hp, int &mp)
{
    hp += hpRestore;
    mp += mpRestore;
}

Chicken::Chicken()
{
    this->name = "Chicken";
    this->type = "Food";
    this->effectDescription = "Restores 3 health points.";
    this->level = 0;
    this->buyValue = 4;
    this->sellValue = 0;
    this->hpRestore = 3;
    this->mpRestore = 0;
}

Chicken::~Chicken()
{

}

void Chicken::itemUse(int &hp, int &mp)
{
    hp += hpRestore;
    mp += mpRestore;
}

Sausage::Sausage()
{
    this->name = "Sausage";
    this->type = "Food";
    this->effectDescription = "Restores 3 health points.";
    this->level = 0;
    this->buyValue = 4;
    this->sellValue = 0;
    this->hpRestore = 3;
    this->mpRestore = 0;
}

Sausage::~Sausage()
{

}

void Sausage::itemUse(int &hp, int &mp)
{
    hp += hpRestore;
    mp += mpRestore;
}
