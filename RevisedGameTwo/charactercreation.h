#ifndef CHARACTERCREATION_H
#define CHARACTERCREATION_H

#include <QDialog>
#include <QPushButton>
#include <QLineEdit>
#include <QTextBrowser>
#include <QLabel>
#include <QMediaPlayer>
#include <QString>

#include "gamescreen.h"
#include "mainmenusettings.h"

namespace Ui {
class CharacterCreation;
}

class CharacterCreation : public QDialog
{
    Q_OBJECT

public:
    //PASSED SOUND THROUGH CONSTRUCTOR
    explicit CharacterCreation(QMediaPlayer *backgroundMusic, QWidget *parent = nullptr);
    ~CharacterCreation();

    //GAMESCREEN
    GameScreen gs;
    //MAIN MENU SETTINGS
    MainMenuSettings mms;

    //PUSH BUTTONS
    QPushButton *berserkerB, *paladinB, *wizardB, *warlockB, *thiefB, *acceptB;
    //LABELS
    QLabel *professionPicLabel, *nameLabel, *backgroundPicLabel;
    //TEXTBROWSER
    QTextBrowser *professionDescriptionTB;
    //LINE EDIT
    QLineEdit *nameLE;
    //MEDIA PLAYER
    QMediaPlayer *backgroundMusic;

    //PROFESSION NAMES
    QString berserkerName, paladinName, wizardName, warlockName, thiefName;
    //PROFESSION DESCRIPTIONS
    QString berserkerDescription, paladinDescription, wizardDescription, warlockDescription, thiefDescription;
    //PROFESSION SELECTED OR NOT - (FOR CLICKING ACCEPT)
    bool berserkerSelected, paladinSelected, wizardSelected, warlockSelected, thiefSelected;

    //CHARACTER CREATED NAME AND SELECTED PROFESSION
    QString characterName, characterProfession;


private slots:
    void on_berserkerB_clicked();
    void on_paladinB_clicked();
    void on_wizardB_clicked();
    void on_warlockB_clicked();
    void on_thiefB_clicked();
    void on_acceptB_clicked();

private:
    Ui::CharacterCreation *ui;
};

#endif // CHARACTERCREATION_H
