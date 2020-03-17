#include "weapon.h"

#include <QDebug>

Weapon::Weapon()
{
}

void Weapon::forTesting()
{

}

void Weapon::initWeap(int damageMin, int damageMax, QString name, int level, int buyValue, int sellValue)
{
    this->damageMin = damageMin;
    this->damageMax = damageMax;
    this->name = name;
    this->level = level;
    this->buyValue = buyValue;
    this->sellValue = sellValue;
}


FlameSword::FlameSword()
{
    this->damageMin = 0;
    this->damageMax = 0;
    this->name = "";
    this->level = 0;
    this->buyValue = 0;
    this->sellValue = 0;
}

void FlameSword::forTesting()
{
    //qDebug()<<this->name;
}

void FlameSword::initWeap(int damageMin, int damageMax, QString name, int level, int buyValue, int sellValue)
{
    this->damageMin = damageMin;
    this->damageMax = damageMax;
    this->name = name;
    this->level = level;
    this->buyValue = buyValue;
    this->sellValue = sellValue;
    //qDebug()<<this->name;
}
