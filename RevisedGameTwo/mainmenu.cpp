#include "mainmenu.h"
#include "ui_mainmenu.h"

#include <QObject>

MainMenu::MainMenu(QWidget *parent) :
    QDialog(parent),
    cc(mms.backgroundMusic),
    ui(new Ui::MainMenu)
  //,uiS(new Ui::MainMenuSettings)
{
    ui->setupUi(this);

    //WINDOW INFORMATION
    setWindowTitle("Main Menu");
    resize(1280,720);

    //WINDOW BACKGROUND
    QPixmap background("C:/Users/Tommy/Desktop/QtGameLayout/mainMenu.png");
    QPalette palette;
    palette.setBrush(QPalette::Background, background);
    this->setPalette(palette);


    //PUSH BUTTONS
    this->playB = ui->playB;
    playB->setText("Play");
    playB->setStyleSheet("font-family:Morris Roman;font-size:22px");
    this->settingsB = ui->settingsB;
    settingsB->setText("Settings");
    settingsB->setStyleSheet("font-family:Morris Roman;font-size:22px");
    this->exitB = ui->exitB;
    exitB->setText("Exit");
    exitB->setStyleSheet("font-family:Morris Roman;font-size:22px");
    this->loadB = ui->loadB;
    loadB->setText("Load");
    loadB->setStyleSheet("font-family:Morris Roman;font-size:22px");


    //LABELS - (BACKGROUND LABEL)
    QPixmap backgroundPic("C:/Users/Tommy/Desktop/QtGameLayout/mainMenuPicNew.jpg");
    backgroundPicLabel = ui->backgroundPicLabel;
    backgroundPicLabel->setPixmap(backgroundPic);
    backgroundPicLabel->hide();

    //MUSIC
    mms.backgroundMusic->play();
    mms.backgroundMusic->setVolume(100);
}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::on_playB_clicked()
{
    //SOUND SETTINGS
    mms.backgroundMusic->setVolume(25);

    cc.setModal(true);
    cc.show();
    //CLOSE MAIN MENU WINDOW
    close();
    cc.exec();
}

void MainMenu::on_settingsB_clicked()
{
    mms.setModal(true);
    mms.show();
    mms.exec();
}

void MainMenu::on_exitB_clicked()
{
    close();
}

void MainMenu::on_loadB_clicked()
{
    //STOP MUSIC
    cc.backgroundMusic->stop();

    //LOAD FILE
    cc.gs.loadGame();

    //SET UP GAMESCREEN GUI FROM THE CHARACTERCREATION.H FILE
    cc.gs.setModal(true);
    cc.gs.show();

    //CLOSE CHARACTER CREATION WINDOW
    close();
    cc.gs.exec();

}
