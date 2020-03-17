#include "inventory.h"
#include "ui_inventory.h"

#include <QPixmap>
#include <QDebug>
#include <QMessageBox>

Inventory::Inventory(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Inventory),
    uiSk(new Ui::Skills)
{
    ui->setupUi(this);

    //WINDOW INFORMATION
    setWindowTitle("Character Creation");
    resize(600,700);

    //INVENTORY BACKGROUND
    QPixmap pix("C:/Users/Tommy/Desktop/QtGameLayout/inventory.png");
    QPalette palette;
    palette.setBrush(QPalette::Background, pix);
    this->setPalette(palette);


    //PUSHBUTTONS
    this->skillsB = ui->skillsB;
    skillsB->setText("Skills");
    skillsB->setStyleSheet("background:rgba(255,255,255,25%);color:black;font-size:16px;font-weight:bold;");
    this->deleteB = ui->deleteB;
    deleteB->setText("Delete");
    deleteB->setStyleSheet("background:rgba(255,255,255,25%);color:black;font-size:16px;font-weight:bold;");
    this->inspectB = ui->inspectB;
    inspectB->setText("Inspect");
    inspectB->setStyleSheet("background:rgba(255,255,255,25%);color:black;font-size:16px;font-weight:bold;");
    this->useB = ui->useB;
    useB->setText("Use");
    useB->setStyleSheet("background:rgba(255,255,255,25%);color:black;font-size:16px;font-weight:bold;");
    this->organizeBagB = ui->organizeBagB;
    organizeBagB->setText(nullptr);
    organizeBagB->setStyleSheet(("background-image:url(C:/Users/Tommy/Desktop/QtGameLayout/organizeButton.png);border: 0px solid black;"));

    //LABELS
    this->nameLabel = ui->nameLabel;
    nameLabel->setStyleSheet("color:white;font-size:14px");
    this->professionLabel = ui->professionLabel;
    professionLabel->setStyleSheet("color:white;font-size:14px");
    this->levelLabel = ui->levelLabel;
    levelLabel->setStyleSheet("color:white;font-size:14px");
    this->skillPointsLabel = ui->skillPointsLabel;
    skillPointsLabel->setStyleSheet("color:white;font-size:14px");
    this->strLabel = ui->strLabel;
    strLabel->setStyleSheet("color:white;font-size:14px");
    this->intelLabel = ui->intelLabel;
    intelLabel->setStyleSheet("color:white;font-size:14px");
    this->dexLabel = ui->dexLabel;
    dexLabel->setStyleSheet("color:white;font-size:14px");
    this->professionPicLabel = ui->professionPicLabel;
    professionPicLabel->setStyleSheet("color:white;font-size:14px");
    this->goldLabel = ui->goldLabel;
    goldLabel->setStyleSheet("color:white;font-size:14px");
    this->silverLabel = ui->silverLabel;
    silverLabel->setStyleSheet("color:white;font-size:14px");
    this->copperLabel = ui->copperLabel;
    copperLabel->setStyleSheet("color:white;font-size:14px");

    //PROGRESS BARS
    this->hpPB = ui->hpPB;
    this->mpPB = ui->mpPB;


    //LIST VIEW
    this->bagLW = ui->bagLW;
    bagLW->setStyleSheet("background:rgba(255,255,255,25%);color:black;font-size:16px;font-weight:bold;");


    //CHARACTER INFORMATION AND STATS
    name = nullptr;
    profession = nullptr;
    level = 0;
    expMax = 0;
    exp = 0;
    skillPoints = 0;
    hpMax = 0;
    hp = 0;
    mpMax = 0;
    mp = 0;
    str = 0;
    intel = 0;
    dex = 0;
    gold = 0;
    silver = 0;
    copper = 0;


    //DISCOVERY BOOLS
    this->skillsDiscovered = false;

}

Inventory::~Inventory()
{
    delete ui;
}

void Inventory::initCharacter(QString &name, QString &profession)
{
    //CREATE NAME AND PROFESSION AND THEN INIT EXP
    this->name = name;
    this->profession = profession;
    this->level = 1;
    this->expMax = 10;
    this->exp = 1;
    this->skillPoints = 200;
    this->gold = 0;
    this->silver = 0;
    this->copper = 0;

    //CHARACTER INFORMATION AND STATS
    //BERSERKER STATS
    if(this->profession == "Berserker")
    {
        this->hpMax = 34;
        this->hp = hpMax;
        this->mpMax = 8;
        this->mp = mpMax;
        this->str = 6;
        this->intel = 0;
        this->dex = 3;
    }
    //PALADIN STATS
    if(this->profession == "Paladin")
    {
        this->hpMax = 38;
        this->hp = hpMax;
        this->mpMax = 10;
        this->mp = mpMax;
        this->str = 3;
        this->intel = 3;
        this->dex = 3;
    }
    //WIZARD STATS
    if(this->profession == "Wizard")
    {
        this->hpMax = 28;
        this->hp = hpMax;
        this->mpMax = 12;
        this->mp = mpMax;
        this->str = 0;
        this->intel = 9;
        this->dex = 0;
    }
    //WARLOCK STATS
    if(this->profession == "Warlock")
    {
        this->hpMax = 28;
        this->hp = hpMax;
        this->mpMax = 12;
        this->mp = mpMax;
        this->str = 0;
        this->intel = 9;
        this->dex = 0;
    }
    //THIEF STATS
    if(this->profession == "Thief")
    {
        this->hpMax = 34;
        this->hp = hpMax;
        this->mpMax = 8;
        this->mp = mpMax;
        this->str = 3;
        this->intel = 0;
        this->dex = 6;
    }

    //UPDATE STATS
    statUpdate();
    initSkills();
}

void Inventory::getAllItemsFromItem(QVector<Item> &allItems)
{
    this->allItems = allItems;
}

void Inventory::initCharacterFromLoad(const QString& name, const QString& profession, const int& level, const int& skillPoints, const int& expMax, const int& exp, const int& hpMax, const int& hp, const int& mpMax, const int& mp, const int& str, const int& intel, const int& dex, const int& gold, const int& silver, const int& copper)
{
    this->name = name;
    this->profession = profession;
    this->level = level;
    this->expMax = expMax;
    this->exp = exp;
    this->skillPoints = skillPoints;
    this->gold = gold;
    this->silver = silver;
    this->copper = copper;
    this->hpMax = hpMax;
    this->hp = hp;
    this->mpMax = mpMax;
    this->mp = mp;
    this->str = str;
    this->intel = intel;
    this->dex = dex;

    //UPDATE LABELS
    statUpdate();
    initSkills();
    moneyUpdate();
}

void Inventory::initBag()
{
    //CREATE BAG
    for(int i = 0; i < bagSize; i++)
    {
        items[i] = nullptr;
        itemsDescription[i] = nullptr;
        bagLW->addItem(items[i]);
    }
}

void Inventory::initBagFromLoad(QString *items, QString* itemsDescription,  const int &bagSize, const int& nrOfEl)
{
    //SET BAGSIZE
    this->bagSize = bagSize;
    this->nrOfEl = nrOfEl;
    this->items = new QString[bagSize];
    this->itemsDescription = new QString[bagSize];

    //JUST COPY OVER THE VALUES FROM LOAD BAG
    for(int i = 0; i < bagSize; i++)
    {
        this->items[i] = items[i];
    }
    for(int i = 0; i < bagSize; i++)
    {
        this->itemsDescription[i] = itemsDescription[i];
    }

    //SKILL SETUP
    //PRINT BAGLW - (UDPATE)
    bagLWPrint();
}

void Inventory::initSkills()
{
    if(profession == "Berserker")
    {
        //ABILITY NAME
        skillOneName = "Charge";
        skillTwoName = "Spear thrust";
        skillThreeName = "Berserk";
        //ABILITY DAMAGE
        skillOneDamage = 1;
        skillTwoDamage = 3;
        skillThreeDamage = 5;
        //ABILITY MP USE
        skillOneMp = 0;
        skillTwoMp = 5;
        skillThreeMp = 7;
    }
    if(profession == "Paladin")
    {
        //ABILITY NAME
        skillOneName = "Strike";
        skillTwoName = "Shield Bash";
        skillThreeName = "Holy Ray";
        //ABILITY DAMAGE
        skillOneDamage = 1;
        skillTwoDamage = 3;
        skillThreeDamage = 5;
        //ABILITY MP USE
        skillOneMp = 0;
        skillTwoMp = 5;
        skillThreeMp = 7;
    }
    if(profession == "Wizard")
    {
        //ABILITY NAME
        skillOneName = "Fireball";
        skillTwoName = "Mind Crush";
        skillThreeName = "Ice Break";
        //ABILITY DAMAGE
        skillOneDamage = 1;
        skillTwoDamage = 3;
        skillThreeDamage = 5;
        //ABILITY MP USE
        skillOneMp = 0;
        skillTwoMp = 5;
        skillThreeMp = 7;
    }
    if(profession == "Warlock")
    {
        //ABILITY NAME
        skillOneName = "Gaze of Fear";
        skillTwoName = "Life Tap";
        skillThreeName = "Suffering";
        //ABILITY DAMAGE
        skillOneDamage = 1;
        skillTwoDamage = 3;
        skillThreeDamage = 5;
        //ABILITY MP USE
        skillOneMp = 0;
        skillTwoMp = 5;
        skillThreeMp = 7;
    }
    if(profession == "Thief")
    {
        //ABILITY NAME
        skillOneName = "Pierce";
        skillTwoName = "Pistol Shot";
        skillThreeName = "Hidden Strike";
        //ABILITY DAMAGE
        skillOneDamage = 1;
        skillTwoDamage = 3;
        skillThreeDamage = 5;
        //ABILITY MP USE
        skillOneMp = 0;
        skillTwoMp = 5;
        skillThreeMp = 7;
    }
}

void Inventory::itemsAdd(const QString& itemName, const QString& itemDescription)
{
    //IF THE CURRENT POSITION IN THE BAG
    //IS BIGGER THAN THE CURRENT SIZE
    //IT WILL INCREASE THE BAG FOR US
    if(nrOfEl >= bagSize)
    {
        itemsExpand();
    }

    //CHECK FOR VALUES INSIDE ARRAY AND CHECK IF THEY ARE NULL
    //IF SO, IT WILL ADD THE ITEM INTO THE NULL POSITION
    for(int i = 0; i < bagSize; i++)
    {
        if(items[i] == nullptr)
        {
            nrOfEl = i;
            items[nrOfEl] = itemName;
            itemsDescription[nrOfEl++] = itemDescription;
            break;
        }
    }

    //ADD ITEM THEN INCREMENT POSISITION - (ORIGINAL CODE)
    //items[nrOfEl++] = el;

    //UPDATE WIDGET LIST
    bagLWPrint();
}

void Inventory::useItemFromBattle(QString* items, int& hp, int& mp, const int& itemNumber)
{
    this->items = items;

    for(int i = 0; i < allItems.size(); i++)
    {
        if(this->items[itemNumber] == allItems[i].name)
        {
            allItems[i].itemUse(hp, mp);
            itemsDeleteAt(itemNumber);
            hpPB->setValue(this->hp);
            mpPB->setValue(this->mp);
            break;
        }
    }

    bagLWPrint();
}

void Inventory::itemsExpand()
{
    //1: INCREASE BAGSPACE
    bagSize *= 2;

    //2: CREATE TEMP ARRAY
    QString *tempItems = new QString[bagSize];
    QString *tempItemsDescription = new QString[bagSize];

    //3: COPY OVER VALID VALUES FROM OLD ARRAY
    for(int i = 0; i < nrOfEl; i++)
    {
        tempItems[i] = items[i];
        tempItemsDescription[i] = itemsDescription[i];
    }

    //4: DELETE OLD ARRAY MEMORY
    delete[] items;
    delete[] itemsDescription;

    //5: POINT OLD ARRAY POINTER TO NEW ARRAY LOCATION
    items = tempItems;
    itemsDescription = tempItemsDescription;

    //PRINT BAGLW - (UDPATE)
    bagLWPrint();


    QMessageBox::information(this,"Bag","Bag size has doubled.");
}

void Inventory::itemsOrganize()
{
    //2: CREATE TEMP ARRAY
    QString *tempItems = new QString[bagSize];
    QString *tempItemsDescription = new QString[bagSize];

    //3: COPY OVER VALID VALUES FROM OLD ARRAY
    fakeI = 0;
    for(int i = 0; i < bagSize; i++)
    {
        if(items[i] != nullptr)
        {
            tempItems[fakeI] = items[i];
            tempItemsDescription[fakeI] = itemsDescription[i];

            itemsDeleteAt(i);

            fakeI++;
        }
        else
        {
            tempItems[i] = items[i];
            tempItemsDescription[i] = itemsDescription[i];

            //SET NROFEL
            nrOfEl = fakeI ;

        }
    }

    //4: DELETE OLD ARRAY MEMORY
    delete[] items;
    delete[] itemsDescription;

    //5: POINT OLD ARRAY POINTER TO NEW ARRAY LOCATION
    items = tempItems;
    itemsDescription = tempItemsDescription;

    bagLW->scrollToTop();
    //PRINT BAGLW - (UDPATE)
    bagLWPrint();


    QMessageBox::information(this,"Bag","Bag has been organized.");
}

QString Inventory::itemsGetAt(int index)
{
    //DOES NOT WORK RIGHT NOW
    QString value = "";

    if(index >= nrOfEl)
    {
        throw("OUT OF BOUNDS");
    }
    else
        value = items[index];

    return value;
}

void Inventory::itemsDeleteAt(int index)
{
    //TESTING FOR NOW


    if(items[index] == nullptr)
    {
        //IF THE ITEM IS ALREADY NULL WILL PRINT A MESSAGE
        QMessageBox::information(this,"Bag","No item in that slot");
    }
    else
    {
        //SET CURRENTLY SELECTED ITEM TO NULL
        items[index] = nullptr;
        itemsDescription[index] = nullptr;
        bagLWPrint();
    }
}

void Inventory::itemsPrint()
{
    //USED ONLY FOR PRINTING BAG - (FOR TESTING ONLY)
    for(int i = 0; i < bagSize; i++)
    {
        qDebug()<<"bag-print: " << items[i];
    }
}

void Inventory::bagLWPrint()
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

void Inventory::initMoney()
{
    //CREATE MONEY
    this->gold = 99;
    this->silver = 0;
    this->copper = 0;

    //UPDATE LABELS
    moneyUpdate();
}

void Inventory::moneyUpdate()
{
    //LABELS UPDATE
    goldLabel->setText(QString::number(this->gold));
    silverLabel->setText(QString::number(this->silver));
    copperLabel->setText(QString::number(this->copper));
}

void Inventory::statUpdate()
{
    //SETTING PROFESSION PIC
    //BERSERKER INVENTORY PIC
    if(this->profession == "Berserker")
    {
        QPixmap berserkerInventoryPic("C:/Users/Tommy/Desktop/QtGameLayout/berserkerInventory.png");
        professionPicLabel->setPixmap(berserkerInventoryPic);
        professionLink = new QPixmap(berserkerInventoryPic);
    }
    //PALADIN INVENTORY PIC
    if(this->profession == "Paladin")
    {
        QPixmap paladinInventoryPic("C:/Users/Tommy/Desktop/QtGameLayout/paladinInventory.png");
        professionPicLabel->setPixmap(paladinInventoryPic);
        professionLink = new QPixmap(paladinInventoryPic);
    }
    //WIZARD INVENTORY PIC
    if(this->profession == "Wizard")
    {
        QPixmap wizardInventoryPic("C:/Users/Tommy/Desktop/QtGameLayout/wizardInventory.png");
        professionPicLabel->setPixmap(wizardInventoryPic);
        professionLink = new QPixmap(wizardInventoryPic);
    }
    //WARLOCK INVENTORY PIC
    if(this->profession == "Warlock")
    {
        QPixmap warlockInventoryPic("C:/Users/Tommy/Desktop/QtGameLayout/warlockInventory.png");
        professionPicLabel->setPixmap(warlockInventoryPic);
        professionLink = new QPixmap(warlockInventoryPic);
    }
    //THIEF INVENTORY PIC
    if(this->profession == "Thief")
    {
        QPixmap thiefInventoryPic("C:/Users/Tommy/Desktop/QtGameLayout/thiefInventory.png");
        professionPicLabel->setPixmap(thiefInventoryPic);
        professionLink = new QPixmap(thiefInventoryPic);
    }

    //LABELS UPDATE
    nameLabel->setText(this->name);
    professionLabel->setText(this->profession);
    levelLabel->setText(QString::number(this->level));
    skillPointsLabel->setText(QString::number(this->skillPoints));
    strLabel->setText(QString::number(this->str));
    intelLabel->setText(QString::number(this->intel));
    dexLabel->setText(QString::number(this->dex));

    //PROGRESS BARS UPDATE
    hpPB->setMaximum(hpMax);
    hpPB->setValue(hp);
    mpPB->setMaximum(mpMax);
    mpPB->setValue(mp);
}

void Inventory::passSoundsToInventory(QMediaPlayer *skillClick, QMediaPlayer *openSkills, QMediaPlayer *discoverySound,  QMediaPlayer *skillCharge, QMediaPlayer *skillSpearThrust, QMediaPlayer *skillBerserk, QMediaPlayer *strike, QMediaPlayer *shieldBash, QMediaPlayer *holyRay, QMediaPlayer *fireBall, QMediaPlayer *mindCrush, QMediaPlayer *iceBreak,  QMediaPlayer *gazeOfFear, QMediaPlayer *lifeTap, QMediaPlayer *suffering,  QMediaPlayer *pierce, QMediaPlayer *pistolShot, QMediaPlayer *hiddenStrike)
{
    //PASS NEEDED SOUNDS IN SKILLS TO SKILLS
   sk.passSoundsToSkills(skillClick, discoverySound);

   //SET SOUNDS
   this->openSkills = new QMediaPlayer(this);
   this->openSkills = openSkills;
   this->discoverySound = new QMediaPlayer(this);
   this->discoverySound = discoverySound;

   //SKILLS SOUNDS
   this->skillOneSound = new QMediaPlayer(this);
   this->skillTwoSound = new QMediaPlayer(this);
   this->skillThreeSound = new QMediaPlayer(this);

   if(profession == "Berserker")
   {
       skillOneSound = skillCharge;
       skillTwoSound = skillSpearThrust;
       skillThreeSound = skillBerserk;
   }
   if(profession == "Paladin")
   {
       skillOneSound = strike;
       skillTwoSound = shieldBash;
       skillThreeSound = holyRay;
   }
   if(profession == "Wizard")
   {
       skillOneSound = fireBall;
       skillTwoSound = mindCrush;
       skillThreeSound = iceBreak;
   }
   if(profession == "Warlock")
   {
       skillOneSound = gazeOfFear;
       skillTwoSound = lifeTap;
       skillThreeSound = suffering;
   }
   if(profession == "Thief")
   {
       skillOneSound = pierce;
       skillTwoSound = pistolShot;
       skillThreeSound = hiddenStrike;
   }

}

void Inventory::passInformationVToInventory(QVector<QString> &informationV)
{
    //MAKE INVENTORY INFORMATIONV EQUAL GAMESCREEN INFORMATIONV
    this->informationV = informationV;
}

QString Inventory::getItems()
{
    QString itemsToString;
    for(int i = 0; i < bagSize; i++)
    {
        itemsToString += items[i] + "\n";
    }
    itemsToString += "\n";

    QString itemsDescriptionToString;
    for(int i = 0; i < bagSize; i++)
    {
        itemsDescriptionToString += itemsDescription[i] + "\n";
    }
    itemsDescriptionToString += "\n";

    return itemsToString + "\n" + itemsDescriptionToString;
}

void Inventory::on_skillsB_clicked()
{
    bagLWPrint();

    //SOUND SETTINGS
    openSkills->stop();
    openSkills->play();

    //DISCOVERED SETTINGS
    if(skillsDiscovered == false)
    {
        skillsDiscovered = true;

        //PLAY DISCOVERY SOUND
        discoverySound->stop();
        discoverySound->play();
        //ADD MESSAGE AND UPDATE
        this->informationV.push_back("You have discovered the skills window!");
        emit getUpdatedInformationVFromInventory(this->informationV);
        discoverySound->play();
    }

    sk.setModal(true);

    //PASS STATS FROM INVENTORY TO SKILLS
    sk.passStatsToSkills(this->hpMax, this->mpMax, this->skillPoints, this->str, this->intel, this->dex);

    //TAKING STATS THAT WE PASSED INTO SKILLS BACK FROM SKILLS - (VERY USEFUL)
    connect(&sk, SIGNAL(getUpdatedStatsFromSkills(const int&, const int&, const int&, const int&, const int&, const int&)), this, SLOT(updateInventoryStats(const int&, const int&, const int&, const int&, const int&, const int&)));

    sk.show();
    sk.exec();

    //DISCONNECT
    disconnect(&sk, SIGNAL(getUpdatedStatsFromSkills(const int&, const int&, const int&, const int&, const int&, const int&)), this, SLOT(updateInventoryStats(const int&, const int&, const int&, const int&, const int&, const int&)));
}

void Inventory::on_deleteB_clicked()
{
    //ONLY DELETES FROM THE LISTWIDGET
    if(bagLW->currentItem() != nullptr && items[bagLW->currentRow()] != nullptr && itemsDescription[bagLW->currentRow()] != nullptr)
    {
        itemsDeleteAt(bagLW->currentRow());
    }
    else
        QMessageBox::information(this,"Delete","No item has been selected or there is no item in this position.");

}

void Inventory::on_inspectB_clicked()
{
    if(bagLW->currentItem() != nullptr)
    {
       QMessageBox::information(this,"Inspect",itemsDescription[bagLW->currentRow()]);
    }
    else
        QMessageBox::information(this,"Inspect","No item has been selected or there is no item in this position.");
}

void Inventory::on_useB_clicked()
{
    for(int i = 0; i < allItems.size(); i++)
    {
        if(bagLW->currentItem()->text() == allItems[i].name)
        {
            allItems[i].itemUse(hp, mp);
            itemsDeleteAt(bagLW->currentRow());
            hpPB->setValue(this->hp);
            mpPB->setValue(this->mp);
            break;
        }
    }
}

void Inventory::on_organizeBagB_clicked()
{
    itemsOrganize();
}

void Inventory::updateInventoryStats(const int& hpMax, const int& mpMax, const int& skillPoints, const int& str, const int& intel, const int& dex)
{
    //UPDATE INFORMATIONV FIRST TO CHECK FOR STAT CHANGES
    if(hpMax != this->hpMax)
    {
        statTotal = hpMax - this->hpMax;
        total = "Health increased by +" + QString::number(statTotal);
        this->informationV.push_back(total);
        emit getUpdatedInformationVFromInventory(this->informationV);
    }
    if(mpMax != this->mpMax)
    {
        statTotal = mpMax - this->mpMax;
        total = "Mana increased by +" + QString::number(statTotal);
        this->informationV.push_back(total);
        emit getUpdatedInformationVFromInventory(this->informationV);
    }
    if(str != this->str)
    {
        statTotal = str - this->str;
        total = "Strength increased by +" + QString::number(statTotal);
        this->informationV.push_back(total);
        emit getUpdatedInformationVFromInventory(this->informationV);
    }
    if(intel != this->intel)
    {
        statTotal = intel - this->intel;
        total = "Intelligence increased by +" + QString::number(statTotal);
        this->informationV.push_back(total);
        emit getUpdatedInformationVFromInventory(this->informationV);
    }
    if(dex != this->dex)
    {
        statTotal = dex - this->dex;
        total = "Dexerity increased by +" + QString::number(statTotal);
        this->informationV.push_back(total);
        emit getUpdatedInformationVFromInventory(this->informationV);
    }

    //UPDATE STATS AND LABELS
    this->hpMax = hpMax;
    hpPB->setMaximum(hpMax);
    this->mpMax = mpMax;
    mpPB->setMaximum(mpMax);
    this->skillPoints = skillPoints;
    skillPointsLabel->setText(QString::number(this->skillPoints));
    this->str = str;
    strLabel->setText(QString::number(this->str));
    this->intel = intel;
    intelLabel->setText(QString::number(this->intel));
    this->dex = dex;
    dexLabel->setText(QString::number(this->dex));
}

void Inventory::updateInventoryMoney(const int &gold, const int &silver, const int &copper)
{
    //UPDATE STATS AND LABELS
    this->gold = gold;
    goldLabel->setText(QString::number(this->gold));
    this->silver = silver;
    silverLabel->setText(QString::number(this->silver));
    this->copper = copper;
    copperLabel->setText(QString::number(this->copper));
}

void Inventory::updateAfterBattle(const int &hp, const int &mp, const int &exp)
{
    //UPDATE STATS AND LABELS
    this->hp = hp;
    hpPB->setValue(this->hp);
    this->mp = mp;
    mpPB->setValue(this->mp);
    this->exp += exp;
}
