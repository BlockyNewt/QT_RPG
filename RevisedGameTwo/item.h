#ifndef ITEM_H
#define ITEM_H

#include <QString>


class Item
{
public:
    Item(QString name = "NONE", int level = 0, int buyValue = 0, int sellValue = 0, QString type = "NONE");
    ~Item();

    //ITEM VALUES
    QString name;
    QString type;
    QString effectDescription;
    int level;
    int buyValue, sellValue;
    int hpRestore, mpRestore;

    //ACCESSORS
    virtual inline const QString& getName() const {return this->name;};
    virtual inline const QString& getType() const {return this->type;};
    virtual inline const QString& getEffectDescription() const {return this->effectDescription;};
    virtual inline const int& getLevel() const {return this->level;};
    virtual inline const int& getBuyValue() const {return this->buyValue;};
    virtual inline const int& getSellValue() const {return this->sellValue;};

    //MODIFIERS
    virtual void itemUse(int& hp, int& mp);

private:

};



/*
 *
 *
 * FOOD
 *
 *
 */

class Bread : public Item
{
public:
    Bread();
    ~Bread();


    //ACCESSORS
    inline const QString& getName() const override {return this->name;};
    inline const QString& getType() const override {return this->type;};
    inline const QString& getEffectDescription() const override {return this->effectDescription;};
    inline const int& getLevel() const override {return this->level;};
    inline const int& getBuyValue() const override {return this->buyValue;};
    inline const int& getSellValue() const override {return this->sellValue;};


    //MODIFIERS
    void itemUse(int& hp, int& mp) override;
};

class Chicken : public Item
{
public:
    Chicken();
    ~Chicken();


    //ACCESSORS
    inline const QString& getName() const override {return this->name;};
    inline const QString& getType() const override {return this->type;};
    inline const QString& getEffectDescription() const override {return this->effectDescription;};
    inline const int& getLevel() const override {return this->level;};
    inline const int& getBuyValue() const override {return this->buyValue;};
    inline const int& getSellValue() const override {return this->sellValue;};

    //MODIFIERS
    void itemUse(int& hp, int& mp) override;
};

class Sausage : public Item
{
public:
    Sausage();
    ~Sausage();


    //ACCESSORS
    inline const QString& getName() const override {return this->name;};
    inline const QString& getType() const override {return this->type;};
    inline const QString& getEffectDescription() const override {return this->effectDescription;};
    inline const int& getLevel() const override {return this->level;};
    inline const int& getBuyValue() const override {return this->buyValue;};
    inline const int& getSellValue() const override {return this->sellValue;};

    //MODIFIERS
    void itemUse(int& hp, int& mp) override;
};

/*
 *
 *
 * FOOD END
 *
 *
 */

/*
 *
 *
 * DRINK
 *
 *
 */


#endif // ITEM_H
