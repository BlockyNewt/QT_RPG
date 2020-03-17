#include "enemy.h"

Enemy::Enemy()
{
    name = nullptr;
    hpMax = 0;
    hp = hpMax;
    damage = 0;

    exp = 0;

    //MEDIA PLAYER
    this->enemySound = new QMediaPlayer();
    this->boarSound = new QMediaPlayer();
    this->dogSound = new QMediaPlayer();

    //PIXMAP
    this->enemyPic = new QPixmap;

}

Enemy::~Enemy()
{

}

Boar::Boar()
{
    name = "Boar";
    hpMax = 3;
    hp = hpMax;
    damage = 2;

    exp = 3;

    enemySound = boarSound;

    enemyPic = new QPixmap("C:/Users/Tommy/Desktop/QtGameLayout/boar.png");

}

Dog::Dog()
{
    name = "Dog";
    hpMax = 5;
    hp = hpMax;
    damage = 3;

    exp = 5;

    enemySound = dogSound;

    enemyPic = new QPixmap("C:/Users/Tommy/Desktop/QtGameLayout/wolf.png");


}

