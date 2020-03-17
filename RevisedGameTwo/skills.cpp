#include "skills.h"
#include "ui_skills.h"

#include <QDebug>
#include <QMessageBox>

Skills::Skills(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Skills)
{
    ui->setupUi(this);

    //WINDOW INFORMATION
    setWindowTitle("Skills");
    resize(400,550);

    //WINDOW DESIGN
    QPixmap pix("C:/Users/Tommy/Desktop/QtGameLayout/skills.png");
    QPalette palette;
    palette.setBrush(QPalette::Background, pix);
    this->setPalette(palette);

    //PUSH BUTTONS
    this->offSkillOne = ui->offSkillOne;
    offSkillOne->setText("STR +1");
    offSkillOne->setToolTip("Increase strength by 1 point");
    offSkillOne->setStyleSheet("border: 1px solid black; border-radius:20px; background-color: white");
    this->offSkillTwo = ui->offSkillTwo;
    offSkillTwo->setText("DEX +1");
    offSkillTwo->setToolTip("Increase dexerity by 2 points");
    offSkillTwo->setStyleSheet("border: 1px solid black; border-radius:20px; background-color: white");
    this->offSkillThree = ui->offSkillThree;
    offSkillThree->setText("STR +3");
    offSkillThree->setToolTip("Increase strength by 3 points");
    offSkillThree->setStyleSheet("border: 1px solid black; border-radius:20px; background-color: white");
    this->defSkillOne = ui->defSkillOne;
    defSkillOne->setText("HP +2");
    defSkillOne->setToolTip("Increase health by 2 points");
    defSkillOne->setStyleSheet("border: 1px solid black; border-radius:20px; background-color: white");
    this->defSkillTwo = ui->defSkillTwo;
    defSkillTwo->setText("MP +1");
    defSkillTwo->setToolTip("Increase mana by 1 point");
    defSkillTwo->setStyleSheet("border: 1px solid black; border-radius:20px; background-color: white");
    this->defSkillThree = ui->defSkillThree;
    defSkillThree->setText("HP +4");
    defSkillThree->setToolTip("Increase health by 4 points");
    defSkillThree->setStyleSheet("border: 1px solid black; border-radius:20px; background-color: white");
}

Skills::~Skills()
{
    delete ui;
}

void Skills::passStatsToSkills(int& hpMax, int& mpMax, int& skillPoints, int &str, int& intel, int& dex)
{
    //PASSING STATS
    this->hpMax = hpMax;
    this->mpMax = mpMax;
    this->skillPoints = skillPoints;
    this->str = str;
    this->intel = intel;
    this->dex = dex;
}

void Skills::passSoundsToSkills(QMediaPlayer *skillClick, QMediaPlayer *discoverySound)
{
    //SOUND SETTINGS - (BROUGHT FROM GAMESCREEN.CPP)
    this->skillClick = new QMediaPlayer(this);
    this->skillClick = skillClick;
    this->discoverySound = new QMediaPlayer(this);
    this->discoverySound = discoverySound;
}

void Skills::on_offSkillOne_clicked()
{    
    //SET MINIMUM AMOUNT
    minimumAmount = 1;

    if(skillPoints > 0 && skillPoints >= minimumAmount)
    {
        //SOUND SETTINGS
        skillClick->stop();
        skillClick->play();

        //INCREASE STR BY 1
        str++;
        //DECREASE SKILL POINTS
        skillPoints -= minimumAmount;

        //LET INVENTORY TAKE BACK STATS
        emit getUpdatedStatsFromSkills(hpMax, mpMax, skillPoints, str, intel, dex);
    }
    else
    {
        QMessageBox::information(this,"Information", "Not enough skill points.");
    }
}

void Skills::on_offSkillTwo_clicked()
{
    //SET MINIMUM AMOUNT
    minimumAmount = 2;

    if(skillPoints > 0 && skillPoints >= minimumAmount)
    {
        //SOUND SETTINGS
        skillClick->stop();
        skillClick->play();

        //INCREASE DEX BY 1
        dex++;
        //DECREASE SKILL POINTS
        skillPoints -= minimumAmount;

        //LET INVENTORY TAKE BACK STATS
        emit getUpdatedStatsFromSkills(hpMax, mpMax, skillPoints, str, intel, dex);
    }
    else
    {
        QMessageBox::information(this,"Information", "Not enough skill points.");
    }
}

void Skills::on_offSkillThree_clicked()
{
    //SET MINIMUM AMOUNT
    minimumAmount = 3;

    if(skillPoints > 0 && skillPoints >= minimumAmount)
    {
        //SOUND SETTINGS
        skillClick->stop();
        skillClick->play();

        //INCREASE HP BY 1
        str += 3;
        //DECREASE SKILL POINTS
        skillPoints -= minimumAmount;

        //LET INVENTORY TAKE BACK STATS
        emit getUpdatedStatsFromSkills(hpMax, mpMax, skillPoints, str, intel, dex);
    }
    else
    {
        QMessageBox::information(this,"Information", "Not enough skill points.");
    }
}

void Skills::on_defSkillOne_clicked()
{
    //SET MINIMUM AMOUNT
    minimumAmount = 1;

    if(skillPoints > 0 && skillPoints >= minimumAmount)
    {
        //SOUND SETTINGS
        skillClick->stop();
        skillClick->play();

        //INCREASE HP BY 2
        hpMax += 2;
        //DECREASE SKILL POINTS
        skillPoints -= minimumAmount;

        //LET INVENTORY TAKE BACK STATS
        emit getUpdatedStatsFromSkills(hpMax, mpMax, skillPoints, str, intel, dex);
    }
    else
    {
        QMessageBox::information(this,"Information", "Not enough skill points.");
    }
}

void Skills::on_defSkillTwo_clicked()
{
    //SET MINIMUM AMOUNT
    minimumAmount = 2;

    if(skillPoints > 0 && skillPoints >= minimumAmount)
    {
        //SOUND SETTINGS
        skillClick->stop();
        skillClick->play();

        //INCREASE MP BY 1
        mpMax++;
        //DECREASE SKILL POINTS
        skillPoints -= minimumAmount;

        //LET INVENTORY TAKE BACK STATS
        emit getUpdatedStatsFromSkills(hpMax, mpMax, skillPoints, str, intel, dex);
    }
    else
    {
        QMessageBox::information(this,"Information", "Not enough skill points.");
    }
}

void Skills::on_defSkillThree_clicked()
{
    //SET MINIMUM AMOUNT
    minimumAmount = 3;

    if(skillPoints > 0 && skillPoints >= minimumAmount)
    {
        //SOUND SETTINGS
        skillClick->stop();
        skillClick->play();

        //INCREASE HEALTH BY 4
        hpMax += 4;
        //DECREASE SKILL POINTS
        skillPoints -= minimumAmount;

        //LET INVENTORY TAKE BACK STATS
        emit getUpdatedStatsFromSkills(hpMax, mpMax, skillPoints, str, intel, dex);
    }
    else
    {
        QMessageBox::information(this,"Information", "Not enough skill points.");
    }
}
