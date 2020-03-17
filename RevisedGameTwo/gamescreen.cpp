#include "gamescreen.h"
#include "ui_gamescreen.h"

#include <iostream>
#include <QtDebug>
#include <QScrollBar>
#include <QTime>
#include <QTimer>
#include <QMessageBox>
#include <fstream>
#include <ostream>
#include <QFile>

GameScreen::GameScreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameScreen),
    uiGs(new Ui::GameScreenSettings)
{
    ui->setupUi(this);

    //WINDOW INFORMATION
    setWindowTitle("Game Screen");
    resize(1280,720);

    //WINDOW BACKGROUND
    QPixmap background("C:/Users/Tommy/Desktop/QtGameLayout/gameScreen.png");
    QPalette palette;
    palette.setBrush(QPalette::Background, background);
    this->setPalette(palette);

    //PUSH BUTTONS
    this->inventoryB = ui->inventoryB;
    inventoryB->setText("Inventory");
    inventoryB->setStyleSheet("background:rgba(255,255,255,25%);color:black;font-size:16px;font-weight:bold;");
    this->gameScreenSettingsB = ui->gameScreenSettingsB;
    gameScreenSettingsB->setText(nullptr);
    gameScreenSettingsB->setStyleSheet("background-image:url(C:/Users/Tommy/Desktop/QtGameLayout/settingsButton.png);border: 0px solid black;");
    this->eraseB = ui->eraseB;
    eraseB->setText(nullptr);
    eraseB->setStyleSheet("background-image:url(C:/Users/Tommy/Desktop/QtGameLayout/eraseInformationBox.png);border: 0px solid black;");
    this->battleB = ui->battleB;
    battleB->setText("Battle");
    battleB->setStyleSheet("background:rgba(255,255,255,25%);color:black;font-size:16px;font-weight:bold;");
    //MAP PUSH BUTTONS
    this->mapReturnB = ui->mapReturnB;
    mapReturnB->setText("Map");
    mapReturnB->setStyleSheet("background:rgba(255,255,255,25%);color:black;font-size:16px;font-weight:bold;");
    this->mapOneB = ui->mapOneB;
    mapOneB->setText(nullptr);
    mapOneB->setStyleSheet("background:rgba(255,255,255,40%);");
    //MAP ONE PUSH BUTTONS - (JUST FOR TESTING)
    this->straightB = ui->straightB;
    straightB->setText("Straight");
    straightB->hide();
    this->backB = ui->backB;
    backB->setText("Back");
    backB->hide();
    this->leftB = ui->leftB;
    leftB->setText("Left");
    leftB->hide();
    this->rightB = ui->rightB;
    rightB->setText("Right");
    rightB->hide();
    this->mapOneFishB = ui->mapOneFishB;
    mapOneFishB->setText("Fish");
    mapOneFishB->hide();
    //SHOP BUTTONS
    this->mapOneShopB = ui->mapOneShopB;
    mapOneShopB->setText("Shop");
    mapOneShopB->hide();


    //LABELS
    QPixmap mapMain("C:/Users/Tommy/Desktop/QtGameLayout/mapMain.png");
    this->gameScreenPicLabel = ui->gameScreenPicLabel;
    gameScreenPicLabel->setPixmap(mapMain);
    //gameScreenPicLabel->setStyleSheet("background-color:black;");
    this->clockLabel = ui->clockLabel;
    clockLabel->setText("");


    //TEXTBROWSER
    this->informationTB = ui->informationTB;
    informationTB->setStyleSheet("background:rgba(255,255,255,25%);color:black;font-size:16px;font-weight:bold;");


    //DISCOVERY BOOLS
    this->inventoryDiscovered = false;
    this->gameScreenSettingsDiscovered = false;
    this->mapReturnDiscovered = false;
    this->mapOneFishingDiscovered = false;


    //TIMER - (FOR CLOCK)
    clockUpdateTimer = new QTimer(this);
    connect(clockUpdateTimer, SIGNAL(timeout()), this, SLOT(updateClock()));
    clockUpdateTimer->start(1000);

}

GameScreen::~GameScreen()
{
    delete ui;
}

void GameScreen::initGame(QString &characterName, QString &characterProfession)
{
    //PASS CHARACTERNAME AND CHARACTERPROFESSION INTO INVENTORY
    inv.initCharacter(characterName, characterProfession);


    //INIT BAG
    inv.initBag();

    //INIT MONEY
    inv.initMoney();

    //SHOPS INITS
    mos.initShop();
    mos.passMoneyToShop(inv.gold, inv.silver, inv.copper);
    mos.passSoundsToShop(gss.purchaseSound);

    //PASS ALLITEMS VECTOR INTO IVNENTORY
    inv.getAllItemsFromItem(shop.allItems);

    //INIT MAP
    initMap();
    //INIT MAP ENEMIES
    bat.initEnemies();
    bat.passEnemySounds(gss.boarSound, gss.dogSound);

    //ALSO NEED TO PASS SOUND

    //WEAPON INITS
    weaponOne->initWeap(999,999,"Flame Sword",1,999,999);

    //PASS SOUNDS TO INVENTORY AND TO SKILLS - (GET SOUNDS FOR OTHER CLASSES)
    inv.passSoundsToInventory(gss.skillClick, gss.openSkills, gss.discoverySound, gss.skillCharge, gss.skillSpearThrust, gss.skillBerserk, gss.skillStrike, gss.skillShieldBash, gss.skillHolyRay, gss.skillFireball, gss.skillVoid, gss.skillIceBreak, gss.skillGazeOfFear, gss.skillLifeTap, gss.skillSuffering, gss.skillPierce, gss.skillPistolShot, gss.skillHiddenStrike);

    //WELCOME MESSAGE FOR INFORMATIONV
    informationV.push_back("Welcome to the game.");
    //PRINT INFORMATIONTB
    informationTBUpdate();
}

void GameScreen::initFromLoad(const QString &name, const QString &profession, const int &level, const int &skillPoints, const int &expMax, const int &exp, const int &hpMax, const int &hp, const int &mpMax, const int &mp, const int &str, const int &intel, const int &dex, const int &gold, const int &silver, const int &copper, QString* items, QString* itemsDescription, const int& bagSize, const int& nrOfEl)
{
    //PASS VALUES TO CHARACTER
    inv.initCharacterFromLoad(name, profession, level, skillPoints, expMax, exp, hpMax, hp, mpMax, mp, str, intel, dex, gold, silver, copper);

    //INIT BAG
    inv.initBagFromLoad(items, itemsDescription, bagSize, nrOfEl);

    //SHOPS INITS
    mos.initShop();
    mos.passMoneyToShop(inv.gold, inv.silver, inv.copper);
    mos.passSoundsToShop(gss.purchaseSound);

    //PASS ALLITEMS VECTOR INTO IVNENTORY
    inv.getAllItemsFromItem(shop.allItems);

    //INIT MAP
    initMap();
    //INIT MAP ENEMIES
    bat.initEnemies();
    bat.passEnemySounds(gss.boarSound, gss.dogSound);

    //WEAPON INITS
    weaponOne->initWeap(999,999,"Flame Sword",1,999,999);

    //PASS SOUNDS TO INVENTORY AND TO SKILLS - (GET SOUNDS FOR OTHER CLASSES)
    inv.passSoundsToInventory(gss.skillClick, gss.openSkills, gss.discoverySound, gss.skillCharge, gss.skillSpearThrust, gss.skillBerserk, gss.skillStrike, gss.skillShieldBash, gss.skillHolyRay, gss.skillFireball, gss.skillVoid, gss.skillIceBreak, gss.skillGazeOfFear, gss.skillLifeTap, gss.skillSuffering, gss.skillPierce, gss.skillPistolShot, gss.skillHiddenStrike);

    //WELCOME MESSAGE FOR INFORMATIONV
    informationV.push_back("Welcome back to the game.");
    informationV.push_back("Game was loaded.");
    //PRINT INFORMATIONTB
    informationTBUpdate();

    //WILL NEED TO INIT OTHER STUFF LATER, BUT FOR NOW IT WORKS

}

void GameScreen::initMap()
{
    //CREATE MAP WITH MULTIDIMENSIONAL ARRAY
    for(int row = 0; row < mapSize; row++)
    {
        for(int column = 0; column < mapSize; column++)
        {
            map[row][column] = 0;
        }
    }

    //SET WALLS FOR MAP
    map[0][0] = 8;
    map[0][1] = 8;
    map[0][2] = 8;
    map[0][3] = 8;
    map[1][0] = 8;
    map[1][3] = 8;
    map[2][0] = 8;
    map[2][3] = 8;
    map[3][0] = 8;
    map[3][1] = 8;
    map[3][2] = 8;
    map[3][3] = 8;

    //SET PLAYER POSITION
    playerY = 0;
    playerX = 0;
    //map[playerY][playerX] = 1;

}

void GameScreen::straightLocations()
{
    if(map[playerY-1][playerX] != 8)
    {
        playerY --;

        if(playerY == 1 && playerX == 2)
        {
            //CHANGE LABEL PIC
            QPixmap mapOnePic("C:/Users/Tommy/Desktop/QtGameLayout/mapOneStraight.png");
            gameScreenPicLabel->setPixmap(mapOnePic);

            //HIDDEN BUTTONS
            mapOneB->hide();
            mapOneShopB->hide();
            backB->hide();
            mapOneFishB->hide();
            rightB->hide();
            straightB->hide();

            //SHOWN BUTTONS
            leftB->show();
            backB->show();
        }
    }
    else
    {
        informationV.push_back("Can go straight here.");
        informationTBUpdate();
    }
}

void GameScreen::backLocations()
{
    if(map[playerY+1][playerX] != 8)
    {
        playerY ++;

        if(playerY == 2 && playerX == 2)
        {
            //CHANGE LABEL PIC
            QPixmap mapOnePic("C:/Users/Tommy/Desktop/QtGameLayout/mapOneRight.png");
            gameScreenPicLabel->setPixmap(mapOnePic);

            //HIDDEN BUTTONS
            mapOneB->hide();
            mapOneShopB->hide();
            backB->hide();
            mapOneFishB->hide();
            rightB->hide();

            //SHOWN BUTTONS
            leftB->show();
            straightB->show();

            //RENAME BUTTON
            straightB->setText("Straight");

        }
    }
    else
    {
        informationV.push_back("Can go straight here.");
        informationTBUpdate();
    }
}

void GameScreen::leftLocations()
{
    if(map[playerY][playerX-1] != 8)
    {
        playerX --;

        if(playerY == 2 && playerX == 1)
        {
            //CHANGE LABEL PIC
            QPixmap mapOnePic("C:/Users/Tommy/Desktop/QtGameLayout/mapOne.png");
            gameScreenPicLabel->setPixmap(mapOnePic);

            //HIDDEN BUTTONS
            mapOneB->hide();
            backB->hide();
            straightB->hide();
            leftB->hide();
            mapOneShopB->hide();
            mapOneFishB->hide();

            //SHOWN BUTTONS
            rightB->show();

            //SHOW BUTTONS
            rightB->setText("Right");

        }
        else if(playerY == 1 && playerX == 1)
        {
            //CHANGE LABEL PIC
            QPixmap mapOnePic("C:/Users/Tommy/Desktop/QtGameLayout/mapOneBack.png");
            gameScreenPicLabel->setPixmap(mapOnePic);

            //HIDDEN BUTTONS
            mapOneB->hide();
            backB->hide();
            mapOneFishB->hide();
            straightB->hide();
            leftB->hide();

            //SHOWN BUTTONS
            rightB->show();
            mapOneShopB->show();

            //RENAME RIGHT BUTTON TO BACK
            rightB->setText("Back");

        }
    }
    else
    {
        informationV.push_back("Can go left here.");
        informationTBUpdate();
    }
}

void GameScreen::rightLocations()
{

    //CHANGE LABEL PIC

    if(map[playerY][playerX+1] != 8)
    {
        playerX ++;

        if(playerY == 2 && playerX == 2)
        {
            //CHANGE LABEL PIC
            QPixmap mapOnePic("C:/Users/Tommy/Desktop/QtGameLayout/mapOneRight.png");
            gameScreenPicLabel->setPixmap(mapOnePic);

            //HIDDEN BUTTONS
            mapOneB->hide();
            mapOneShopB->hide();
            backB->hide();
            mapOneFishB->hide();
            rightB->hide();

            //SHOWN BUTTONS
            leftB->show();
            straightB->show();

        }
        if(playerY == 1 && playerX == 2)
        {
            //CHANGE LABEL PIC
            QPixmap mapOnePic("C:/Users/Tommy/Desktop/QtGameLayout/mapOneStraight.png");
            gameScreenPicLabel->setPixmap(mapOnePic);

            //HIDDEN BUTTONS
            mapOneB->hide();
            mapOneShopB->hide();
            mapOneFishB->hide();
            rightB->hide();
            straightB->hide();

            //SHOWN BUTTONS
            leftB->show();
            backB->show();

            //RENAME RIGHT BUTTON TO RIGHT ONCE RETURNED
            rightB->setText("Right");

        }
    }
    else
    {
        informationV.push_back("Can go right here.");
        informationTBUpdate();
    }
}

void GameScreen::informationTBUpdate()
{
    QString informationTBString = "";
    for(int i = 0; i < informationV.size(); i++)
    {
        if(i > 0)
        {
            informationTBString += "\n";
            informationTBString += informationV[i];
            informationTB->setText(informationTBString);
            informationTB->verticalScrollBar()->setValue(informationTB->verticalScrollBar()->maximum());
        }
        else
        {
            informationTBString += informationV[i];
            informationTB->setText(informationTBString);
            informationTB->verticalScrollBar()->setValue(informationTB->verticalScrollBar()->maximum());
        }
    }

    //PLAY INFORMATIONTBNOTIFICATION SOUND HERE
    gss.informationTBNotification->stop();
    gss.informationTBNotification->play();
}

void GameScreen::informationVErase()
{
    //CLEAR INFORMATIONV
    this->informationV.clear();

    //THEN UPDATE IT
    informationV.push_back("Information Box has been cleared.");
    informationTBUpdate();
}

void GameScreen::saveGame()
{
    QFile saveTo("C:/Users/Tommy/Documents/QT/RevisedGameTwo/saveFile/myFile.txt");

    if(saveTo.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream addToFile(&saveTo);

        addToFile << inv.getName() << "\n" << inv.getProfession() << "\n" << inv.getLevel() << "\n" << inv.getSkillPoints() << "\n" << inv.getExpMax() << "\n" << inv.getExp() << "\n" << inv.gethpMax() << "\n" << inv.getHp() << "\n" << inv.getMpMax() << "\n" << inv.getMp() << "\n" << inv.getStr() << "\n" << inv.getIntel() << "\n" << inv.getDex() << "\n" << inv.getGold() << "\n" << inv.getSilver() << "\n" << inv.getCopper() << "\n";

        //ADD DISCOVERY BOOLS
        addToFile << inventoryDiscovered << "\n" << gameScreenSettingsDiscovered << "\n" << mapReturnDiscovered << "\n" << mapOneFishingDiscovered << "\n" << battleDiscovered << "\n" << inv.skillsDiscovered << "\n";

        //ADD BAG ITEMS
        addToFile << inv.getBagSize() << "\n" << inv.getNrOfEl();
        addToFile << "\n" << inv.getItems();

        //WRITE IT TO DISK
        saveTo.flush();
        saveTo.close();

        //PRINT TO INFORMATIONV
        informationV.push_back("Game was saved.");
        //PRINT INFORMATIONTB
        informationTBUpdate();
    }
    else
    {
        qDebug()<<"Not open";
    }

}

void GameScreen::loadGame()
{
    QFile loadFrom("C:/Users/Tommy/Documents/QT/RevisedGameTwo/saveFile/myFile.txt");

    if(loadFrom.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream getFromFile(&loadFrom);

        //STAT VALUES
        QString name = getFromFile.readLine();
        QString profession = getFromFile.readLine();
        int level = getFromFile.readLine().toInt();
        int skillPoints = getFromFile.readLine().toInt();
        int expMax = getFromFile.readLine().toInt();
        int exp = getFromFile.readLine().toInt();
        int hpMax = getFromFile.readLine().toInt();
        int hp = getFromFile.readLine().toInt();
        int mpMax = getFromFile.readLine().toInt();
        int mp = getFromFile.readLine().toInt();
        int str = getFromFile.readLine().toInt();
        int intel = getFromFile.readLine().toInt();
        int dex = getFromFile.readLine().toInt();

        //MONEY VALUES
        int gold = getFromFile.readLine().toInt();
        int silver = getFromFile.readLine().toInt();
        int copper = getFromFile.readLine().toInt();

        //DISCOVERY VALUES
        inventoryDiscovered = getFromFile.readLine().toInt();
        gameScreenSettingsDiscovered = getFromFile.readLine().toInt();
        mapReturnDiscovered = getFromFile.readLine().toInt();
        mapOneFishingDiscovered = getFromFile.readLine().toInt();
        battleDiscovered = getFromFile.readLine().toInt();
        inv.skillsDiscovered = getFromFile.readLine().toInt();

        //BAG ITEMS
        int bagSize = getFromFile.readLine().toInt();
        int nrOfEl = getFromFile.readLine().toInt();

        //ADD VALUES TO A TEMP ARRAY
        QString *items = new QString[bagSize];
        for(int i = 0; i < bagSize; i++)
        {
            items[i] = getFromFile.readLine();
        }

        //SKIP THE WHITESPACE BETWEEN THESE TWO ARRAYS
        getFromFile.skipWhiteSpace();

        QString *itemsDescription = new QString[bagSize];
        for(int i = 0; i < bagSize; i++)
        {
            itemsDescription[i] = getFromFile.readLine();
        }

        //CLOSE FILE
        loadFrom.close();

        //INIT GAME FROM INITFROMLOAD
        initFromLoad(name, profession, level, skillPoints, expMax, exp, hpMax, hp, mpMax, mp, str, intel, dex, gold, silver, copper, items, itemsDescription, bagSize, nrOfEl);

        //DELETE THIS AFTER WE INIT BAG INISDE OF INITFROMLOAD
        delete[] items;
        delete[] itemsDescription;
    }
}

void GameScreen::on_inventoryB_clicked()
{
    //PLAY INVENTORYOPEN
    gss.inventoryOpen->play();

    //DISCOVERED SETTINGS
    if(inventoryDiscovered == false)
    {
        inventoryDiscovered = true;

        //PLAY DISCOVERY SOUND
        gss.discoverySound->stop();
        gss.discoverySound->play();
        //ADD MESSAGE AND UPDATE
        informationV.push_back("You have discovered the inventory!");
        informationTBUpdate();
    }

    inv.setModal(true);

    //PASS INFORMATION V TO INVENTORY
    inv.passInformationVToInventory(informationV);
    //TAKE PASS BACK AS A REFERENCE FROM INVENTORY
    connect(&inv, SIGNAL(getUpdatedInformationVFromInventory(QVector<QString>&)), this, SLOT(updateInformationVFromInventory(QVector<QString>&)));

    inv.show();
    inv.exec();

    //DISCONNECT IT
    disconnect(&inv, SIGNAL(getUpdatedInformationVFromInventory(QVector<QString>&)), this, SLOT(updateInformationVFromInventory(QVector<QString>&)));
}

void GameScreen::on_gameScreenSettingsB_clicked()
{
    //PLAY INVENTORYOPEN
    gss.gameScreenSettingsOpen->play();

    //DISCOVERED SETTINGS
    if(gameScreenSettingsDiscovered == false)
    {
        gameScreenSettingsDiscovered = true;

        //PLAY DISCOVERY SOUND
        gss.discoverySound->stop();
        gss.discoverySound->play();
        //ADD MESSAGE AND UPDATE
        informationV.push_back("You have discovered the game screen settings!");
        informationTBUpdate();
    }

    //SAVE CONNECT
    connect(gss.saveB, SIGNAL(clicked()), this, SLOT(saveGame()));
    connect(gss.loadB, SIGNAL(clicked()), this, SLOT(loadGame()));

    //IF THIS VALUE IS TRUE THEN IT WILL LOAD
    if(gss.loaded == true)
    {

        //SET VALUE BACK TO FALSE
        gss.loaded = false;


    }


    gss.setModal(true);
    gss.show();
    gss.exec();

    //DISCONNECT FOR NO ISSUES
    disconnect(gss.saveB, SIGNAL(clicked()), this, SLOT(saveGame()));
    disconnect(gss.loadB, SIGNAL(clicked()), this, SLOT(loadGame()));
}

void GameScreen::on_eraseB_clicked()
{
    //ERASE AND UPDATE
    informationVErase();
}

void GameScreen::on_battleB_clicked()
{
    //DISCOVERED SETTINGS
    if(battleDiscovered == false)
    {
        battleDiscovered = true;

        //PLAY DISCOVERY SOUND
        gss.discoverySound->stop();
        gss.discoverySound->play();

        //ADD MESSAGE AND UPDATE
        informationV.push_back("You have discovered the battle button!");
        informationTBUpdate();
    }

    if(playerY > 0 && playerX > 0)
    {
        //GIVE MESSAGE
        QMessageBox::StandardButton battleConfirm;
        battleConfirm = QMessageBox::question(this,"Battle","Are you sure you want to look around?", QMessageBox::Yes | QMessageBox::No);

        if(battleConfirm == QMessageBox::Yes)
        {
            bat.setModal(true);

            //ROLL RANDOM NUMBER AND SEND IT INTO BATTLE
            srand(time(nullptr));
            int result = 0;
            result = rand() % 9 + 1;


            //PASS NEEDED INFORMATION
            //PASS STATS
            bat.passCharacterInformation(inv.getName(), inv.getExp(), inv.gethpMax(), inv.getHp(), inv.getMpMax(), inv.getMp(), inv.getStr(), inv.getIntel(), inv.getDex());
            //PASS MONEY
            bat.passMoney(inv.getGold(), inv.getSilver(), inv.getCopper());
            //PASS SKILLS
            bat.passSkillsInformation(inv.getSkillOneName(), inv.getSkillTwoName(), inv.getSkillThreeName(), inv.getSkillOneDamage(), inv.getSkillTwoDamage(), inv.getSkillThreeDamage(), inv.getSkillOneMp(), inv.getSkillTwoMp(), inv.getSkillThreeMp());
            //FINALLY START THE BATTLE
            bat.initBattle(result);
            //PASS SOUNDS - (GET THE SOUNDS THAT ARE SET INSIDE OF INV)
            bat.passSounds(inv.skillOneSound, inv.skillTwoSound, inv.skillThreeSound);
            //PASS BAG
            bat.passItems(inv.items, inv.bagSize);
            //PASS PIXMAP
            bat.passProfessionPic(inv.professionLink);



            //CONNECT AND RETRIEVE STATS
            connect(&bat, SIGNAL(getStatsBackFromBattle(const int&, const int&, const int&)), &inv, SLOT(updateAfterBattle(const int&, const int&, const int&)));

            //CONNECT MESSAGE TO INFORMATIONV
            connect(&bat, SIGNAL(passEndOfBattleDetailsToInformationV(const QString&)), this, SLOT(addMessageToInformationV(const QString&)));

            //CONNECT TO INVENTORY TO USE ITEMS
            connect(&bat, SIGNAL(getUsedItemNumberFromBattle(QString*, int&, int&, const int&)), &inv, SLOT(useItemFromBattle(QString*, int&, int&, const int&)));




            //SHOW BATTLE SCREEN
            bat.show();
            bat.exec();
        }

        //DISCONNECT
        disconnect(&bat, SIGNAL(getStatsBackFromBattle(const int&, const int&, const int&)), &inv, SLOT(updateAfterBattle(const int&, const int&, const int&)));

        disconnect(&bat, SIGNAL(passEndOfBattleDetailsToInformationV(const QString&)), this, SLOT(addMessageToInformationV(const QString&)));

        disconnect(&bat, SIGNAL(getUsedItemNumberFromBattle(QString*, int&, int&, const int&)), &inv, SLOT(useItemFromBattle(QString*, int&, int&, const int&)));

    }
    else
    {
        informationV.push_back("You cannot battle because you are not inside a map.");
        informationTBUpdate();
    }
}

void GameScreen::updateInformationVFromInventory(QVector<QString> &informationV)
{
    //SWAP VECTORS
    //this->informationV.swap(informationV);
    this->informationV = informationV;
    //THEN PRINT IT OUT
    informationTBUpdate();

}

void GameScreen::addMessageToInformationV(const QString &message)
{
    informationV.push_back(message);
    informationTBUpdate();
}

void GameScreen::updateClock()
{
    QTime time = QTime(QTime::currentTime());
    QString time_text = time.toString("hh : mm : ss");
    clockLabel->setText(time_text);
    clockLabel->setStyleSheet("font-size:16px");
}

/*
 *
 *
 * BEGGINING OF MAP BUTTONS
 *
 *
 */

void GameScreen::on_mapReturnB_clicked()
{
    //PLAY SOUND
    gss.mapOpen->stop();
    gss.mapOpen->play();

    //DISCOVERED SETTINGS
    if(mapReturnDiscovered == false)
    {
        mapReturnDiscovered = true;

        //PLAY DISCOVERY SOUND
        gss.discoverySound->stop();
        gss.discoverySound->play();
        //ADD MESSAGE AND UPDATE
        informationV.push_back("You have discovered how to look at the map!");
        informationTBUpdate();
    }

    QPixmap mapMain("C:/Users/Tommy/Desktop/QtGameLayout/mapMain.png");
    gameScreenPicLabel->setPixmap(mapMain);

    //RESET MAPONE POSITION TO ZERO
    playerY = 0;
    playerX = 0;
    map[playerY][playerX] = 0;

    //HIDDEN BUTTONS
    backB->hide();
    straightB->hide();
    leftB->hide();
    mapOneShopB->hide();
    rightB->hide();
    mapOneFishB->hide();

    //SHOWN BUTTONS
    mapOneB->show();
}

void GameScreen::on_mapOneB_clicked()
{
    QPixmap mapOnePic("C:/Users/Tommy/Desktop/QtGameLayout/mapOne.png");
    gameScreenPicLabel->setPixmap(mapOnePic);

    //SET PLAYER POSITION
    playerY = 2;
    playerX = 1;

    //HIDDEN BUTTONS
    mapOneB->hide();
    mapOneShopB->hide();
    straightB->hide();
    backB->hide();
    leftB->hide();
    mapOneFishB->hide();

    //SHOWN BUTTONS
    rightB->show();
}




//MAP ONE PUSH BUTTONS - (JUST FOR TESTING)

void GameScreen::on_straightB_clicked()
{
    straightLocations();
}

void GameScreen::on_backB_clicked()
{
    backLocations();
}

void GameScreen::on_leftB_clicked()
{
    leftLocations();
}

void GameScreen::on_rightB_clicked()
{
    rightLocations();
}

void GameScreen::on_mapOneFishB_clicked()
{
    //STILL WORKING ON THIS


    //DISCOVERED SETTINGS
    if(mapOneFishingDiscovered == false)
    {
        mapOneFishingDiscovered = true;

        //PLAY DISCOVERY SOUND
        gss.discoverySound->stop();
        gss.discoverySound->play();
        //ADD MESSAGE AND UPDATE
        informationV.push_back("You discovered how to fish!");
        informationTBUpdate();
    }


    QMessageBox::StandardButton fishing;
    fishing = QMessageBox::question(this,"Fishing", "Would you like to clear the text box before starting?", QMessageBox::Yes | QMessageBox::No);

    if(fishing == QMessageBox::Yes)
    {
        QMessageBox::information(this,"Fishing", "Clearing text box.");
        informationVErase();
    }

    //START FISHING PROCESS
    //GOING TO BE BASED ON TIME
    //GOING TO GAIN EXP AND ALSO THROW
    //CAUGHT ITEMS INTO BAG
}



/*
 *
 *
 * BEGGINING OF SHOP BUTTONS
 *
 *
 */

void GameScreen::on_mapOneShopB_clicked()
{
    mos.setModal(true);

    //PASS MONEY
    //mos.passMoneyToShop(inv.gold, inv.silver, inv.copper);


    //PASS INFORMATIONV
    mos.passInformationVToMapOneShop(informationV);

    //CONNECT TO UPDATE MONEY IN INVENTORY
    connect(&mos, SIGNAL(getUpdatedMoneyFromShop(const int&, const int&, const int&)), &inv, SLOT(updateInventoryMoney(const int&, const int&, const int&)));
    //SEND THE ITEM INTO BAG
    connect(&mos, SIGNAL(getItemFromMapOneShop(const QString&, const QString&)), &inv, SLOT(itemsAdd(const QString&, const QString&)));
    //CONNECT TO UPDATE INFORMATIONV
    connect(&mos, SIGNAL(getUpdatedInformationVFromMapOneShop(QVector<QString>&)), this, SLOT(updateInformationVFromInventory(QVector<QString>&)));


    mos.show();
    mos.exec();

    //DISCONNECT UPDATE MONEY IN INVENTORY
    disconnect(&mos, SIGNAL(getUpdatedMoneyFromShop(const int&, const int&, const int&)), &inv, SLOT(updateInventoryMoney(const int&, const int&, const int&)));
    //DISCONNECT SEND THE ITEM INTO BAG
    disconnect(&mos, SIGNAL(getItemFromMapOneShop(const QString&, const QString&)), &inv, SLOT(itemsAdd(const QString&, const QString&)));
    //DISCONNECT UPDATE INFORMATIONV
    disconnect(&mos, SIGNAL(getUpdatedInformationVFromMapOneShop(QVector<QString>&)), this, SLOT(updateInformationVFromInventory(QVector<QString>&)));
}
