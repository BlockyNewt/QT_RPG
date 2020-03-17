#ifndef SKILLS_H
#define SKILLS_H

#include <QDialog>
#include <QPushButton>
#include <QMediaPlayer>

namespace Ui {
class Skills;
}

class Skills : public QDialog
{
    Q_OBJECT

public:
    explicit Skills(QWidget *parent = nullptr);
    ~Skills();

    //PUSH BUTTON
    QPushButton *offSkillOne, *offSkillTwo, *offSkillThree;
    QPushButton *defSkillOne, *defSkillTwo, *defSkillThree;
    //MEDIA PLAYER
    QMediaPlayer *skillClick, *discoverySound;

    //STATS PASSED FROM INVENTORY
    int hpMax, mpMax, skillPoints, str, intel, dex;
    //USED SO SKILL POINTS DONT GO NEGATIVE
    int minimumAmount;


    //FUNCTIONS
    void passStatsToSkills(int& hpMax, int& mpMax, int& skillPoints, int &str, int& intel, int& dex);
    void passSoundsToSkills(QMediaPlayer *skillClick, QMediaPlayer *discoverySound);


signals:
    //FOR PASSING REFERENCES THROUGH BUTTON PRESSES - (BOOKMARKED IN CHROME)
    //RETURNING STATS BACK TO INVENTORY
    void getUpdatedStatsFromSkills(const int&hpMax, const int& mpMax, const int& skillPoints, const int& str, const int& intel, const int& dex);


private slots:
    //OFFENCE SKILLS
    void on_offSkillOne_clicked();
    void on_offSkillTwo_clicked();
    void on_offSkillThree_clicked();
    //DEFENCE SKILLS
    void on_defSkillOne_clicked();
    void on_defSkillTwo_clicked();
    void on_defSkillThree_clicked();

private:
    Ui::Skills *ui;
};

#endif // SKILLS_H
