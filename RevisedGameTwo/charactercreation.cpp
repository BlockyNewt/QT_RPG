#include "charactercreation.h"
#include "ui_charactercreation.h"

#include <QDebug>

CharacterCreation::CharacterCreation(QMediaPlayer *backgroundMusic, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CharacterCreation)
{
    ui->setupUi(this);

    //WINDOW INFORMATION
    setWindowTitle("Character Creation");
    resize(1280,720);

    //WINDOW BACKGROUND
    QPixmap background("C:/Users/Tommy/Desktop/QtGameLayout/characterCreationBackground.png");
    QPalette palette;
    palette.setBrush(QPalette::Background, background);
    this->setPalette(palette);

    //PUSH BUTTONS
    this->berserkerB = ui->berserkerB;
    berserkerB->setText("Berserker");
    berserkerB->setStyleSheet("font-family:Morris Roman;font-size:22px;color:black;");
    this->paladinB = ui->paladinB;
    paladinB->setText("Paladin");
    paladinB->setStyleSheet("font-family:Morris Roman;font-size:22px;color:black;");
    this->wizardB = ui->wizardB;
    wizardB->setText("Wizard");
    wizardB->setStyleSheet("font-family:Morris Roman;font-size:22px;color:black;");
    this->warlockB = ui->warlockB;
    warlockB->setText("Warlock");
    warlockB->setStyleSheet("font-family:Morris Roman;font-size:22px;color:black;");
    this->thiefB = ui->thiefB;
    thiefB->setText("Thief");
    thiefB->setStyleSheet("font-family:Morris Roman;font-size:22px;color:black;");
    this->acceptB = ui->acceptB;
    acceptB->setText("Accept");
    acceptB->setStyleSheet("font-family:Morris Roman;font-size:22px;color:black;");

    //LABELS
    this->professionPicLabel = ui->professionPicLabel;
    professionPicLabel->setText("");
    this->nameLabel = ui->nameLabel;
    nameLabel->setText("Name:");
    nameLabel->setStyleSheet("color:white;font-family:Morris Roman;font-size:22px");
    this->backgroundPicLabel = ui->backgroundPicLabel;
    backgroundPicLabel->setStyleSheet("background-color:black;");
    backgroundPicLabel->hide();

    //TEXTBROWSER
    this->professionDescriptionTB = ui->professionDescriptionTB;
    professionDescriptionTB->setStyleSheet("background:white;color:black;font-size:22px;");

    //LINE EDIT
    this->nameLE = ui->nameLE;
    nameLE->setStyleSheet("background:white;color:black;font-size:22px;");

    //PROFESSION NAMES
    this->berserkerName = "Berserker";
    this->paladinName = "Paladin";
    this->wizardName = "Wizard";
    this->warlockName = "Warlock";
    this->thiefName = "Thief";
    //PROFESSION DESCRIPTIONS
    this->berserkerDescription = "He is human but yet he is insane! Do not touch, talk, look, or even think about him or else you will suffer a serious beating, maybe even instant death.";
    this->paladinDescription = "A rank above the normal Knight, but has been appointed by a King or Queen for his noble deeds. He brings light into dark corners of the planet and helps the innocent with his power to cure";
    this->wizardDescription = "Robes, pointy, hat, and lives in a tower along with his fellow wizards. The study and observe the planet with every second they have and hardly ever visit the mainland.";
    this->warlockDescription = "Once a wizard but fell into the study of dark magic. The High Wizards exile wizards who do so and you then become a Warlock.";
    this->thiefDescription = "Normal folk that walk amongst other town folk, but no one know really who they are, or what there duties are. They vanish in a second, and take what they want.";
    //PROFESSION SELECTED OR NOT - (FOR CLICKING ACCEPT)
    this->berserkerSelected = false;
    this->paladinSelected = false;
    this->wizardSelected = false;
    this->warlockSelected = false;
    this->thiefSelected = false;

    //CHARACTER RELATED INFORMATION - (NAME AND SELECTED PROFESSION)
    this->characterName = "";
    this->characterProfession = "";

    //MEDIA PLAYER - (HAVE TO MAKE THIS VARIABLE IN ORDER TO STOP)
    this->backgroundMusic = new QMediaPlayer(this);
    this->backgroundMusic = backgroundMusic;
    //SOUND
    backgroundMusic->setVolume(25);
}

CharacterCreation::~CharacterCreation()
{
    delete ui;
}

void CharacterCreation::on_berserkerB_clicked()
{
    //MAKE SURE PROFESSION HAS BEEN SELECTED
    this->paladinSelected = false;
    this->wizardSelected = false;
    this->warlockSelected = false;
    this->thiefSelected = false;
    this->berserkerSelected = true;

    if(berserkerSelected == true)
    {
        //CHARACTER PROFESSION SELECTED
        characterProfession = berserkerName;

        //SOUND SETTINGS
        mms.paladinVoice->stop();
        mms.wizardVoice->stop();
        mms.warlockVoice->stop();
        mms.thiefVoice->stop();
        mms.clickEffect->stop();
        mms.berserkerVoice->play();

        //TEXTBROWSER SET PROFESSION DESCRIPTION
        professionDescriptionTB->setText(berserkerDescription);

        //PROFESSION PICTURE SET
        QPixmap berserkerPic("C:/Users/Tommy/Desktop/QtGameLayout/berserker.png");
        professionPicLabel->setPixmap(berserkerPic);
    }
}

void CharacterCreation::on_paladinB_clicked()
{
    //MAKE SURE PROFESSION HAS BEEN SELECTED
    this->berserkerSelected = false;
    this->wizardSelected = false;
    this->warlockSelected = false;
    this->thiefSelected = false;
    this->paladinSelected = true;

    if(paladinSelected == true)
    {
        //CHARACTER PROFESSION SELECTED
        characterProfession = paladinName;

        //SOUND SETTINGS
        mms.berserkerVoice->stop();
        mms.wizardVoice->stop();
        mms.warlockVoice->stop();
        mms.thiefVoice->stop();
        mms.clickEffect->stop();
        mms.paladinVoice->play();

        //TEXTBROWSER SET PROFESSION DESCRIPTION
        professionDescriptionTB->setText(paladinDescription);

        //PROFESSION PICTURE SET
        QPixmap paladinPic("C:/Users/Tommy/Desktop/QtGameLayout/paladin.png");
        professionPicLabel->setPixmap(paladinPic);

    }
}

void CharacterCreation::on_wizardB_clicked()
{
    //MAKE SURE PROFESSION HAS BEEN SELECTED
    this->berserkerSelected = false;
    this->warlockSelected = false;
    this->thiefSelected = false;
    this->paladinSelected = false;
    this->wizardSelected = true;

    if(wizardSelected == true)
    {
        //CHARACTER PROFESSION SELECTED
        characterProfession = wizardName;

        //SOUND SETTINGS
        mms.berserkerVoice->stop();
        mms.paladinVoice->stop();
        mms.warlockVoice->stop();
        mms.thiefVoice->stop();
        mms.clickEffect->stop();
        mms.wizardVoice->play();

        //TEXTBROWSER SET PROFESSION DESCRIPTION
        professionDescriptionTB->setText(wizardDescription);

        //PROFESSION PICTURE SET
        QPixmap wizardPic("C:/Users/Tommy/Desktop/QtGameLayout/wizard.png");
        professionPicLabel->setPixmap(wizardPic);

    }
}

void CharacterCreation::on_warlockB_clicked()
{
    //MAKE SURE PROFESSION HAS BEEN SELECTED
    this->berserkerSelected = false;
    this->thiefSelected = false;
    this->paladinSelected = false;
    this->wizardSelected = false;
    this->warlockSelected = true;

    if(warlockSelected == true)
    {
        //CHARACTER PROFESSION SELECTED
        characterProfession = warlockName;

        //SOUND SETTINGS
        mms.berserkerVoice->stop();
        mms.paladinVoice->stop();
        mms.wizardVoice->stop();
        mms.thiefVoice->stop();
        mms.clickEffect->stop();
        mms.warlockVoice->play();

        //TEXTBROWSER SET PROFESSION DESCRIPTION
        professionDescriptionTB->setText(warlockDescription);

        //PROFESSION PICTURE SET
        QPixmap warlockPic("C:/Users/Tommy/Desktop/QtGameLayout/warlock.png");
        professionPicLabel->setPixmap(warlockPic);
    }
}

void CharacterCreation::on_thiefB_clicked()
{
    //MAKE SURE PROFESSION HAS BEEN SELECTED
    this->berserkerSelected = false;
    this->paladinSelected = false;
    this->wizardSelected = false;
    this->warlockSelected = true;
    this->thiefSelected = true;

    if(thiefSelected == true)
    {
        //CHARACTER PROFESSION SELECTED
        characterProfession = thiefName;

        //SOUND SETTINGS
        mms.berserkerVoice->stop();
        mms.paladinVoice->stop();
        mms.wizardVoice->stop();
        mms.warlockVoice->stop();
        mms.clickEffect->stop();
        mms.thiefVoice->play();

        //TEXTBROWSER SET PROFESSION DESCRIPTION
        professionDescriptionTB->setText(thiefDescription);

        //PROFESSION PICTURE SET
        QPixmap thiefPic("C:/Users/Tommy/Desktop/QtGameLayout/thief.png");
        professionPicLabel->setPixmap(thiefPic);
    }
}

void CharacterCreation::on_acceptB_clicked()
{
    if(berserkerSelected == true || paladinSelected == true || wizardSelected == true || warlockSelected == true || thiefSelected == true)
    {
        if(nameLE->text() != nullptr)
        {
            //NAME CREATED
            characterName = nameLE->text();

            //SOUND SETTINGS
            mms.berserkerVoice->stop();
            mms.paladinVoice->stop();
            mms.wizardVoice->stop();
            mms.warlockVoice->stop();
            mms.thiefVoice->stop();
            mms.clickEffect->play();

            //STOP MUSIC
            backgroundMusic->stop();

            //PASS CHARACTER NAME AND SELECTED PROFESSION
            gs.initGame(characterName, characterProfession);

            gs.setModal(true);
            gs.show();
            //CLOSE CHARACTER CREATION WINDOW
            close();
            gs.exec();

        }
    }
}
