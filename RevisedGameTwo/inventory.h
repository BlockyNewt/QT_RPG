#ifndef INVENTORY_H
#define INVENTORY_H

#include "skills.h"
#include "ui_skills.h"
#include <item.h>

#include <QDialog>
#include <QPushButton>
#include <QString>
#include <QLabel>
#include <QProgressBar>
#include <QMediaPlayer>
#include <QListWidget>
#include <QPixmap>

namespace Ui {
class Inventory;
class Skills;
}

class Inventory : public QDialog
{
    Q_OBJECT

public:
    explicit Inventory(QWidget *parent = nullptr);
    ~Inventory();

    //SKILLS
    Skills sk;
    //ITEMS - (FOR GETTING VECTOR)

    //PUSHBUTTONS
    QPushButton *skillsB, *deleteB, *inspectB, *useB, *organizeBagB;
    //LABELS
    QLabel *nameLabel, *professionLabel, *levelLabel, *skillPointsLabel, *strLabel, *intelLabel, *dexLabel, *professionPicLabel;
    QLabel *goldLabel, *silverLabel, *copperLabel;
    //PROGRESS BARS
    QProgressBar *hpPB, *mpPB;
    //LIST VIEW
    QListWidget *bagLW;
    //MEDIA PLAYER
    QMediaPlayer *openSkills, *discoverySound;
    QMediaPlayer *skillOneSound, *skillTwoSound, *skillThreeSound;
    //PIX MAP
    QPixmap *professionLink;

    //CHARACTER INFORMATION AND STATS
    QString name, profession;
    int level, skillPoints;
    int expMax, exp;
    int hpMax, hp;
    int mpMax, mp;
    int str, intel, dex;
    int gold, silver, copper;
    //BAG
    int bagSize = 5;
    int nrOfEl = 0;
    QString *items = new QString[bagSize];
    QString *itemsDescription = new QString[bagSize];
    //SKILLS
    QString skillOneName, skillTwoName, skillThreeName;
    int skillOneDamage, skillTwoDamage, skillThreeDamage;
    int skillOneMp, skillTwoMp, skillThreeMp;

   //DISCOVERY BOOLS
    bool skillsDiscovered;

    //GAMESCREEN INFORMATION BOX
    QVector<QString>informationV;
    int statTotal;
    QString total;

    //VECTOR FOR USE BUTTON CLICK
    QVector<Item>allItems;

    //FAKEI FOR ORGANIZING
    int fakeI;


    //ACCESSORS
    inline const QString& getName() const {return this->name;};
    inline const QString& getProfession() const {return this->profession;};
    inline const int& getLevel() const {return this->level;};
    inline const int& getSkillPoints() const {return this->skillPoints;};
    inline const int& getExpMax() const {return this->expMax;};
    inline const int& getExp() const {return this->exp;};
    inline const int& gethpMax() const {return this->hpMax;};
    inline const int& getHp() const {return this->hp;};
    inline const int& getMpMax() const {return this->mpMax;};
    inline const int& getMp() const {return this->mp;};
    inline const int& getStr() const {return this->str;};
    inline const int& getIntel() const {return this->intel;};
    inline const int& getDex() const {return this->dex;};
    inline const int& getGold() const {return this->gold;};
    inline const int& getSilver() const {return this->silver;};
    inline const int& getCopper() const {return this->copper;};
    //BAG RELATED
    inline const int& getNrOfEl() const {return this->nrOfEl;};
    inline const int& getBagSize() const {return this->bagSize;};
    //SKILL RELATED
    //SKILL NAME
    inline const QString& getSkillOneName() const {return this->skillOneName;};
    inline const QString& getSkillTwoName() const {return this->skillTwoName;};
    inline const QString& getSkillThreeName() const {return this->skillThreeName;};
    //SKILL DAMAGE
    inline const int& getSkillOneDamage() const {return this->skillOneDamage;};
    inline const int& getSkillTwoDamage() const {return this->skillTwoDamage;};
    inline const int& getSkillThreeDamage() const {return this->skillThreeDamage;};
    //SKILL MP
    inline const int& getSkillOneMp() const {return this->skillOneMp;};
    inline const int& getSkillTwoMp() const {return this->skillTwoMp;};
    inline const int& getSkillThreeMp() const {return this->skillThreeMp;};


    //FUNCTIONS
    //LOADS AND CREATES ALL THE CHARACTER DATA
    void initCharacter(QString &name, QString &profession);
    void getAllItemsFromItem(QVector<Item>&allItems);

    //BAG RELATED STUFF
    void initBag();
    void initBagFromLoad(QString *items, QString* itemsDescription, const int &bagSize, const int& nrOfEl);
    void initSkills();
    void itemsExpand();
    void itemsOrganize();
    QString itemsGetAt(int index);
    void itemsDeleteAt(int index);
    void itemsPrint();

    //BAG DESCRIPTIONS
    //NOT SURE YET
    void bagLWPrint();

    //MONEY RELATED
    void initMoney();
    void moneyUpdate();

    //USE THIS AFTER STAT CHANGE
    void  statUpdate();
    void passSoundsToInventory(QMediaPlayer *skillClick, QMediaPlayer *openSkills, QMediaPlayer *discoverySound,  QMediaPlayer *skillCharge, QMediaPlayer *skillSpearThrust, QMediaPlayer *skillBerserk, QMediaPlayer *strike, QMediaPlayer *shieldBash, QMediaPlayer *holyRay, QMediaPlayer *fireBall, QMediaPlayer *mindCrush, QMediaPlayer *iceBreak,  QMediaPlayer *gazeOfFear, QMediaPlayer *lifeTap, QMediaPlayer *suffering,  QMediaPlayer *pierce, QMediaPlayer *pistolShot, QMediaPlayer *hiddenStrike);
    void passInformationVToInventory(QVector<QString>&informationV);

    //FOR SAVE
    QString getItems();
    void initCharacterFromLoad(const QString& name, const QString& profession, const int& level, const int& skillPoints, const int& expMax, const int& exp, const int& hpMax, const int& hp, const int& mpMax, const int& mp, const int& str, const int& intel, const int& dex, const int& gold, const int& silver, const int& copper);


signals:
    //RETURNING BACK TO GAMESCREEN
    void getUpdatedInformationVFromInventory(QVector<QString>&informationV);

private slots:
    void on_skillsB_clicked();

    //BAG RELATED
    void on_deleteB_clicked();
    void on_inspectB_clicked();
    void on_useB_clicked();
    void on_organizeBagB_clicked();

    //UPDATE STATS AFTER THEY CHANGED IN SKILLS
    void updateInventoryStats(const int& hpMax, const int& mpMax, const int& skillPoints, const int& str, const int& intel, const int& dex);
    //UPDATE STATS AFTER THEY CHANGED ELSEWHERE
    void updateInventoryMoney(const int& gold, const int& silver, const int& copper);

    //TESTING WITH BATTLE - DELETE AND USE THE ONE ABOVE TOMORROW
    void updateAfterBattle(const int& hp, const int& mp, const int& exp);

    void itemsAdd(const QString& itemName, const QString& itemDescription);

    void useItemFromBattle(QString* items, int& hp, int& mp, const int& itemNumber);

private:
    Ui::Inventory *ui;
    Ui::Skills *uiSk;
};

#endif // INVENTORY_H
