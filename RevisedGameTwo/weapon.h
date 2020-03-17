#ifndef WEAPON_H
#define WEAPON_H

#include "item.h"

class Weapon
{
public:
    Weapon();


    //ACCESSORS
    virtual inline const QString& getName() const{return this->name;};
    virtual inline const int& getLevel() const {return this->level;};
    virtual inline const int& getBuyValue() const {return this->buyValue;};
    virtual inline const int& getSellValue() const {return this->sellValue;};
    virtual inline const int& getDamageMin() const {return this->damageMin;};
    virtual inline const int& getDamageMax() const {return this->damageMax;};


    //FUNCTIONS
    virtual void forTesting();
    virtual void initWeap(int damageMin, int damageMax, QString name, int level, int buyValue, int sellValue);


private:
    QString name;
    int level;
    int buyValue;
    int sellValue;
    int damageMin;
    int damageMax;
};

class FlameSword :
        public Weapon
{
public:
    FlameSword();

    //ACCESSORS
    inline const QString& getName() const {return this->name;};
    inline const int& getLevel() const {return this->level;};
    inline const int& getBuyValue() const {return this->buyValue;};
    inline const int& getSellValue() const {return this->sellValue;};
    inline const int& getDamageMin() const {return this->damageMin;};
    inline const int& getDamageMax() const {return this->damageMax;};

    //FUNCTIONS
    void forTesting();
    void initWeap(int damageMin, int damageMax, QString name, int level, int buyValue, int sellValue);
    int level;

private:
    QString name;
    int buyValue;
    int sellValue;
    int damageMin;
    int damageMax;
};

#endif // WEAPON_H
