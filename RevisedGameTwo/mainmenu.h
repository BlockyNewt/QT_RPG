#ifndef MAINMENU_H
#define MAINMENU_H

#include "mainmenusettings.h"
#include "ui_mainmenusettings.h"
#include "charactercreation.h"

#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include <QPixmap>

namespace Ui {
class MainMenu;
//class MainMenuSettings;

}

class MainMenu : public QDialog
{
    Q_OBJECT

public:
    explicit MainMenu(QWidget *parent = nullptr);
    ~MainMenu();

    //SETTINGS
    MainMenuSettings mms;
    //CHARACTER CREATION
    CharacterCreation cc;

    //PUSH BUTTONS
    QPushButton *playB, *settingsB, *exitB, *loadB;
    //LABELS
    QLabel *backgroundPicLabel;


private slots:
    void on_playB_clicked();
    void on_settingsB_clicked();
    void on_exitB_clicked();
    void on_loadB_clicked();

private:
    Ui::MainMenu *ui;
    //Ui::MainMenuSettings *uiS;
};

#endif // MAINMENU_H
