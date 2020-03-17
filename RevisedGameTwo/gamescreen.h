#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include "inventory.h"
#include "gamescreensettings.h"
#include "ui_gamescreensettings.h"
#include "weapon.h" //FOR NOW
#include "shops.h"
#include "battle.h"

#include <QDialog>
#include <QLabel>
#include <QTextBrowser>
#include <QPushButton>
#include <QString>
#include <QVector>
#include <QTimer>

namespace Ui {
class GameScreen;
class GameScreenSettings;
}

class GameScreen : public QDialog
{
    Q_OBJECT

public:
    explicit GameScreen(QWidget *parent = nullptr);
    ~GameScreen();

    //INVENTORY
    Inventory inv;
    //GAMESCREEN SETTINGS
    GameScreenSettings gss;
    //WEAPONS - (FOR NOW)
    FlameSword fs;
    Weapon *weaponOne = &fs;
    //SHOPS - (FOR NOW)
    MapOneShop mos;
    Shops shop;
    Shops *shopOne = &mos;
    //BATTLE
    Battle bat;

    //MAP ARRAY
    int mapSize = 4;
    int map[4][4];
    //int mapPlayerPosition[3][3];
    int playerY = 0;  //ROW - (LEFT)
    int playerX = 0;  //COLUMN - (RIGHT)



    //PUSH BUTTONS
    QPushButton *inventoryB, *gameScreenSettingsB, *eraseB, *battleB;
    QPushButton *mapReturnB, *mapOneB, *straightB, *backB, *rightB, *leftB, *mapOneFishB;
    QPushButton *mapOneShopB;
    //LABELS
    QLabel *gameScreenPicLabel, *clockLabel;
    //TEXTBROWSER
    QTextBrowser *informationTB;
    //INFORMATIONTB DATA
    QVector<QString>informationV;
    //TIMER - (FOR CLOCK)
    QTimer *clockUpdateTimer;

    //DISCOVERY BOOLS
    bool inventoryDiscovered, gameScreenSettingsDiscovered, mapReturnDiscovered, mapOneFishingDiscovered, battleDiscovered;

    //FUNCTIONS
    //GAME LOADS AND INITS EVERYTHING HERE
    void initGame(QString &characterName, QString &characterProfession);
    void initFromLoad(const QString& name, const QString& profession, const int& level, const int& skillPoints, const int& expMax, const int& exp, const int& hpMax, const int& hp, const int& mpMax, const int& mp, const int& str, const int &intel, const int& dex, const int& gold, const int& silver, const int& copper, QString* items, QString* itemsDescription,  const int& bagSize, const int& nrOfEl);
    //, const int* bag, const int& bagSize = 5
    //GAME MAP INIT
    void initMap();
    void straightLocations();
    void backLocations();
    void leftLocations();
    void rightLocations();
    //CALL THIS FUNCTION AFTER YOU DO A PUSHBACK
    void informationTBUpdate();
    void informationVErase();

public slots:
    //SAVE AND LOAD
    void saveGame();
    void loadGame();

private slots:
    void on_inventoryB_clicked();
    void on_gameScreenSettingsB_clicked();
    void on_eraseB_clicked();
    void on_battleB_clicked();

    //TAKING INFORMATIONV BACK FROM INVENTORY TO PRINT
    void updateInformationVFromInventory(QVector<QString>& informationV);
    void addMessageToInformationV(const QString& message);

    void updateClock();


    //MAP BUTTONS
    void on_mapReturnB_clicked();
    void on_mapOneB_clicked();
    //MAP ONE PUSH BUTTONS - (JUST FOR TESTING)
    void on_straightB_clicked();
    void on_backB_clicked();
    void on_leftB_clicked();
    void on_rightB_clicked();
    void on_mapOneFishB_clicked();
    //SHOP BUTTONS - (JUST FOR TESTING)
    void on_mapOneShopB_clicked();

private:
    Ui::GameScreen *ui;
    Ui::GameScreenSettings *uiGs;
};

#endif // GAMESCREEN_H
