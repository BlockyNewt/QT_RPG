#ifndef BATTLE_H
#define BATTLE_H

#include <enemy.h>

#include <QDialog>
#include <QLabel>
#include <QVector>
#include <QString>
#include <QPushButton>
#include <QProgressBar>
#include <QMediaPlayer>
#include <QListWidget>
#include <QLabel>

namespace Ui {
class Battle;
}

class Battle : public QDialog
{
    Q_OBJECT

public:
    explicit Battle(QWidget *parent = nullptr);
    ~Battle();

    //ENEMIES
    Boar boar;
    Dog dog;
    Enemy *enemyBoar = &boar;
    Enemy *enemyDog = &dog;

    //VECTORS FOR PICKING ENEMY WITH RANDOM NUMBER
    QVector<QString>mapOneRandomPick;

    //SET PASSED VALUES FROM INVENTORY TO THESE THEN SEND
    //BACK THROUGH EMIT
    QString name;
    int exp;
    int hpMax, hp;
    int mpMax, mp;
    int str, intel, dex;
    int gold, silver, copper;
    QString skillOneName, skillTwoName, skillThreeName;
    int skillOneDamage, skillTwoDamage, skillThreeDamage;
    int skillOneMp, skillTwoMp, skillThreeMp;
    int bagSize;
    QString *items;

    //FOR ENEMY VALUES
    QString enemyName;
    int enemyHpMax, enemyHp, enemyDamage, enemyExp;

    //PUSH BUTTONS
    QPushButton *abilityOneB, *abilityTwoB, *abilityThreeB, *itemsB, *fleeB, *closeB, *useB;
    //LABELS
    QLabel *nameLabel, *enemyNameLabel;
    //PROGRESS BARS
    QProgressBar *hpPB, *mpPB, *enemyHpPB;
    //MEDIA PLAYER
    QMediaPlayer *skillOneSound, *skillTwoSound, *skillThreeSound;
    QMediaPlayer *enemySound;
    //LIST WIDGET
    QListWidget *bagLW;
    //PIX MAP
    QPixmap *professionLink;
    QPixmap *enemyPic;
    //LABELS
    QLabel *professionLabel;
    QLabel *enemyLabel;


    //FUNCTIONS
    void initEnemies();
    void passCharacterInformation(const QString& name, const int& exp, const int& hpMax, const int& hp, const int& mpMax, const int& mp, const int& str, const int& intel, const int& dex);
    void passMoney(const int &gold, const int &silver, const int &copper);
    void passSkillsInformation(const QString& skillOneName, const QString& skillTwoName, const QString& skillThreeName, const int& skillOneDamage, const int& skillTwoDamage, const int& skillThreeDamage, const int& skillOneMp, const int& skillTwoMp, const int& skillThreeMp);
    void passSounds(QMediaPlayer *skillOneSound, QMediaPlayer *skillTwoSound, QMediaPlayer *skillThreeSound);
    void passEnemySounds(QMediaPlayer *boarSound, QMediaPlayer *dogSound);
    void passItems(QString* items, const int& bagSize);
    void updateBagLW();
    void passProfessionPic(QPixmap *professionLink);

    //MAYBE
    //void passBag();
    void setEnemyStats();
    void setStats(const Enemy *enemy);
    void setLabels();
    void initBattle(const int& number);
    //ENEMY VECTORS FOR EACH MAP
    void initMapOneRandomPick();

signals:
    void getStatsBackFromBattle(const int& hp, const int& mp, const int& exp);

    void getUsedItemNumberFromBattle(QString* items, int& hp, int& mp, const int& itemNumber);

    void passEndOfBattleDetailsToInformationV(const QString& battleDetails);

private slots:
    void on_abilityOneB_clicked();
    void on_abilityTwoB_clicked();
    void on_abilityThreeB_clicked();
    void on_itemsB_clicked();
    void on_useB_clicked();
    void on_fleeB_clicked();

    void on_closeB_clicked();

private:
    Ui::Battle *ui;
};

#endif // BATTLE_H
