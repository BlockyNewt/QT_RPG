#include "battle.h"
#include "ui_battle.h"

#include <QDebug>
#include <QMessageBox>

Battle::Battle(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Battle)
{
    ui->setupUi(this);

    //WINDOW SETTINGS
    resize(800,700);
    setWindowTitle("Battle");

    //WINDOW BACKGROUND
    QPixmap background("C:/Users/Tommy/Desktop/QtGameLayout/battle.png");
    QPalette palette;
    palette.setBrush(QPalette::Background, background);
    this->setPalette(palette);

    //PUSH BUTTONS
    this->abilityOneB = ui->abilityOneB;
    abilityOneB->setText("Ability One");
    this->abilityTwoB = ui->abilityTwoB;
    abilityTwoB->setText("Ability Two");
    this->abilityThreeB = ui->abilityThreeB;
    abilityThreeB->setText("Ability Three");
    this->itemsB = ui->itemsB;
    itemsB->setText("Items");
    this->fleeB = ui->fleeB;
    fleeB->setText("Flee");
    this->closeB = ui->closeB;
    closeB->setText("Close");
    closeB->hide();
    this->useB = ui->useB;
    useB->setText("Use");
    useB->hide();

    //LABELS
    this->nameLabel = ui->nameLabel;
    nameLabel->setText(nullptr);
    nameLabel->setStyleSheet("font-size:24px;");
    this->enemyNameLabel = ui->enemyNameLabel;
    enemyNameLabel->setText(nullptr);
    enemyNameLabel->setStyleSheet("font-size:24px;");
    this->professionLabel = ui->professionLabel;
    professionLabel->setText(nullptr);
    this->enemyLabel = ui->enemyLabel;
    enemyLabel->setText(nullptr);

    //PROGRESS BARS
    this->hpPB = ui->hpPB;
    this->mpPB = ui->mpPb;
    this->enemyHpPB = ui->enemyHpPB;

    //LIST WIDGET
    this->bagLW = ui->bagLW;
    bagLW->hide();

    //MEDIA PLAYER
    this->enemySound = new QMediaPlayer(this);

}

Battle::~Battle()
{
    delete ui;
}

void Battle::initEnemies()
{
    //PASSING SOUNDS AS AN ARGUMENT WILL BECOME VERY LONG AFTER
    //MORE ENEMIES ARE IMPLEMENTED - (FOR NOW IT WORKS)
    initMapOneRandomPick();

    //PASS SOUNDS

}

void Battle::passCharacterInformation(const QString &name, const int &exp, const int &hpMax, const int &hp, const int &mpMax, const int &mp, const int &str, const int &intel, const int &dex)
{
    this->name = name;
    this->exp = exp;
    this->hpMax = hpMax;
    this->hp = hp;
    this->mpMax = mpMax;
    this->mp = mp;
    this->str = str;
    this->intel = intel;
    this->dex = dex;
}

void Battle::passMoney(const int &gold, const int &silver, const int &copper)
{
    this->gold = gold;
    this->silver = silver;
    this->copper = copper;
}

void Battle::passSkillsInformation(const QString &skillOneName, const QString &skillTwoName, const QString &skillThreeName, const int &skillOneDamage, const int &skillTwoDamage, const int &skillThreeDamage, const int& skillOneMp, const int& skillTwoMp, const int& skillThreeMp)
{
    //NAMES
    this->skillOneName = skillOneName;
    this->skillTwoName = skillTwoName;
    this->skillThreeName = skillThreeName;
    //DAMAGE
    this->skillOneDamage = skillOneDamage;
    this->skillTwoDamage = skillTwoDamage;
    this->skillThreeDamage = skillThreeDamage;
    //MP
    this->skillOneMp = skillOneMp;
    this->skillTwoMp = skillTwoMp;
    this->skillThreeMp = skillThreeMp;
}

void Battle::passSounds(QMediaPlayer *skillOneSound, QMediaPlayer *skillTwoSound, QMediaPlayer *skillThreeSound)
{
    this->skillOneSound = new QMediaPlayer(this);
    this->skillOneSound = skillOneSound;
    this->skillTwoSound = new QMediaPlayer(this);
    this->skillTwoSound = skillTwoSound;
    this->skillThreeSound = new QMediaPlayer(this);
    this->skillThreeSound = skillThreeSound;
}

void Battle::passEnemySounds(QMediaPlayer *boarSound, QMediaPlayer *dogSound)
{
    enemyBoar->setEnemySound(boarSound);
    enemyDog->setEnemySound(dogSound);
}

void Battle::passItems(QString *items, const int& bagSize)
{
    this->bagSize = bagSize;
    this->items = items;

    updateBagLW();
}

void Battle::updateBagLW()
{
    bagLW->clear();
    for(int i = 0; i < bagSize; i++)
    {
        if(items[i] != nullptr)
        {
            bagLW->addItem(items[i]);
        }
        if(items[i] == nullptr)
        {
            bagLW->addItem(items[i]);
        }
    }
}

void Battle::passProfessionPic(QPixmap *professionLink)
{
    this->professionLink = professionLink;
    professionLabel->setPixmap(*this->professionLink);

}

void Battle::setEnemyStats()
{
    if(enemyName == "Boar")
    {
        //SET SOUND - (WILL NOT WORK IN SET STATS
        enemySound = enemyBoar->enemySound;
        enemyPic = enemyBoar->enemyPic;
        setStats(enemyBoar);
    }
    if(enemyName == "Dog")
    {
        //SET SOUND - (WILL NOT WORK IN SET STATS
        enemySound = enemyDog->enemySound;
        enemyPic = enemyDog->enemyPic;
        setStats(enemyDog);
    }
}

void Battle::setStats(const Enemy *enemy)
{
    //SET STATS
    enemyHpMax = enemy->getHpMax();
    enemyHp = enemyHpMax;
    enemyDamage = enemy->getDamage();
    enemyExp = enemy->exp;


    //SET ENEMYLABEL HERE
    enemyLabel->setPixmap(*enemy->enemyPic);

    //SET LABELS
    setLabels();
}

void Battle::setLabels()
{
    //USERS
    //PUSH BUTTONS
    abilityOneB->setText(this->skillOneName);
    abilityTwoB->setText(this->skillTwoName);
    abilityThreeB->setText(this->skillThreeName);
    //LABELS
    nameLabel->setText(name);
    //PROGRESS BARS
    hpPB->setMaximum(hpMax);
    hpPB->setValue(hp);
    mpPB->setMaximum(mpMax);
    mpPB->setValue(mp);

    //ENEMIES
    //LABELS
    enemyNameLabel->setText(enemyName);
    enemyLabel->setPixmap(*this->enemyPic);

    //PROGRESS BAR
    enemyHpPB->setMaximum(enemyHpMax);
    enemyHpPB->setValue(enemyHp);
}

void Battle::initBattle(const int &number)
{
    //GET ENEMY DETAILS
    enemyName = mapOneRandomPick[number];

    //SET STATS
    setEnemyStats();
}

void Battle::initMapOneRandomPick()
{
    for(int i = 0; i < 5; i++)
    {
        mapOneRandomPick.push_back(boar.name);
        mapOneRandomPick.push_back(dog.name);
    }
}

void Battle::on_abilityOneB_clicked()
{
    //CHECK IF PLAYER HAS ENOUGH MP
    if(mp >= skillOneMp)
    {
        //PLAY SOUNDS
        skillOneSound->stop();
        skillOneSound->play();
        enemySound->stop();
        enemySound->play();


        //DROP HP AND MP
        enemyHp -= skillOneDamage;
        mp -= skillOneMp;
        hp -= enemyDamage;

        //SET LABELS
        setLabels();
    }

    //IF ENEMY DIES REAP REWARDS
    if(enemyHp <= 0)
    {
        //SET PROGRESS BAR EVEN THOUGH ITS 0
        enemyHpPB->setValue(0);
        //PRINT MESSAGE ABOUT REWARDS AND THAT YOU WON
        QMessageBox::information(this,"Battle","You won.");

        //GET EXP
        exp += enemyExp;

        QString battleDetails = "You have gained " + QString::number(exp) + " exp.";
        emit passEndOfBattleDetailsToInformationV(battleDetails);

        emit getStatsBackFromBattle(hp, mp, exp);

        close();
    }
}

void Battle::on_abilityTwoB_clicked()
{
    //CHECK IF PLAYER HAS ENOUGH MP
    if(mp >= skillTwoMp)
    {
        //PLAY SOUNDS
        skillTwoSound->stop();
        skillTwoSound->play();
        enemySound->stop();
        enemySound->play();


        //DROP HP AND MP
        enemyHp -= skillTwoDamage;
        mp -= skillTwoMp;
        hp -= enemyDamage;

        //SET LABELS
        setLabels();
    }

    //IF ENEMY DIES REAP REWARDS
    if(enemyHp <= 0)
    {
        //SET PROGRESS BAR EVEN THOUGH ITS 0
        enemyHpPB->setValue(0);
        //PRINT MESSAGE ABOUT REWARDS AND THAT YOU WON
        QMessageBox::information(this,"Battle","You won.");

        //GET EXP
        exp += enemyExp;

        QString battleDetails = "You have gained " + QString::number(exp) + " exp.";
        emit passEndOfBattleDetailsToInformationV(battleDetails);

        emit getStatsBackFromBattle(hp, mp, exp);

        close();
    }
}

void Battle::on_abilityThreeB_clicked()
{
    //CHECK IF PLAYER HAS ENOUGH MP
    if(mp >= skillThreeMp)
    {
        //PLAY SOUNDS
        skillThreeSound->stop();
        skillThreeSound->play();
        enemySound->stop();
        enemySound->play();


        //DROP HP AND MP
        enemyHp -= skillThreeDamage;
        mp -= skillThreeMp;
        hp -= enemyDamage;

        //SET LABELS
        setLabels();
    }

    //IF ENEMY DIES REAP REWARDS
    if(enemyHp <= 0)
    {
        //SET PROGRESS BAR EVEN THOUGH ITS 0
        enemyHpPB->setValue(0);
        //PRINT MESSAGE ABOUT REWARDS AND THAT YOU WON
        QMessageBox::information(this,"Battle","You won.");

        //GET EXP
        exp += enemyExp;

        QString battleDetails = "You have gained " + QString::number(exp) + " exp.";
        emit passEndOfBattleDetailsToInformationV(battleDetails);

        emit getStatsBackFromBattle(hp, mp, exp);

        close();
    }
}

void Battle::on_itemsB_clicked()
{
    //HIDE BUTTONS
    abilityOneB->hide();
    abilityTwoB->hide();
    abilityThreeB->hide();

    //SHOW CLOSE BUTTONS TO CLOSE LIST
    useB->show();
    closeB->show();
    bagLW->show();
}

void Battle::on_useB_clicked()
{
    //GET BAGLW CURRENT ROW TO DELETE IT
    int usedItemNumber = bagLW->currentRow();

    //SEND VALUES BACK TO INVENTORY
    emit getUsedItemNumberFromBattle(items, hp, mp, usedItemNumber);

    //SET LABELS
    setLabels();
    updateBagLW();
}

void Battle::on_fleeB_clicked()
{
    //ROLL RANDOM NUMBER FOR CHANCE TO FLEE
    srand(time(nullptr));
    int result = 0;
    result = rand() % 9 + 1;

    if(result <= 1)
    {
        QString battleDetails = "You have fled from the battle.";

        emit passEndOfBattleDetailsToInformationV(battleDetails);

        emit getStatsBackFromBattle(hp, mp, exp);

        close();
    }
    else
    {
        //PLAY SOUND
        enemySound->stop();
        enemySound->play();

        //ELSE DAMAGE PLAYER
        hp -= enemyDamage;

        //SET LABELS
        setLabels();
    }
}

void Battle::on_closeB_clicked()
{
    //SHOW BUTTONS
    abilityOneB->show();
    abilityTwoB->show();
    abilityThreeB->show();

    //HIDE BUTTONS
    useB->hide();
    closeB->hide();
    bagLW->hide();
}
