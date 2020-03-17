#ifndef ENEMY_H
#define ENEMY_H

#include <QString>
#include <QMediaPlayer>
#include <QPixmap>

class Enemy
{
public:
    Enemy();
    ~Enemy();

    //STATS
    QString name;
    int hpMax, hp;
    int damage;
    //MEDIA PLAYER
    QMediaPlayer *enemySound;
    QMediaPlayer *boarSound, *dogSound;
    //PIX MAP
    QPixmap *enemyPic;

    inline const int& getHpMax() const {return this->hpMax;};
    inline const int& getHp() const {return this->hp;};
    inline const int& getDamage() const {return this->damage;};

    virtual void setEnemySound(QMediaPlayer *enemySound) {this->enemySound = enemySound;};

    //REWARDS
    int exp;
};

class Boar : public Enemy
{
public:
    Boar();

    void setEnemySound(QMediaPlayer *boarSound) override {enemySound = boarSound;};

};

class Dog : public Enemy
{
public:
    Dog();

    void setEnemySound(QMediaPlayer *wolfSound) override {enemySound = wolfSound;};

};

#endif // ENEMY_H
