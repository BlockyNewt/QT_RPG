#include "gamescreensettings.h"
#include "ui_gamescreensettings.h"

#include <QFile>

GameScreenSettings::GameScreenSettings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameScreenSettings)
{
    ui->setupUi(this);

    //WINDOW INFORMATION
    setWindowTitle("Game Screen Settings");
    resize(430,500);

    //WINDOW BACKGROUND
    QPixmap pix("C:/Users/Tommy/Desktop/QtGameLayout/gameScreenSettings.png");
    QPalette palette;
    palette.setBrush(QPalette::Background, pix);
    this->setPalette(palette);

    //PUSH BUTTONS
    this->saveB = ui->saveB;
    saveB->setText("Save");
    this->loadB = ui->loadB;
    loadB->setText("Load");

    //SLIDERS
    this->effectsSlider = ui->effectsSlider;
    this->discoverySlider = ui->discoverySlider;
    this->abilitiesSlider = ui->abilitiesSlider;

    //MEDIA PLAYER
    inventoryOpen = new QMediaPlayer(this);
    inventoryOpen->setMedia(QUrl::fromLocalFile("C:/Users/Tommy/Desktop/QtGameLayout/music/openinventory.wav"));
    inventoryOpen->setVolume(25);
    gameScreenSettingsOpen = new QMediaPlayer(this);
    gameScreenSettingsOpen->setMedia(QUrl::fromLocalFile("C:/Users/Tommy/Desktop/QtGameLayout/music/opensettings.wav"));
    gameScreenSettingsOpen->setVolume(25);
    discoverySound = new QMediaPlayer(this);
    discoverySound->setMedia(QUrl::fromLocalFile("C:/Users/Tommy/Desktop/QtGameLayout/music/discoverysound.wav"));
    discoverySound->setVolume(25);
    informationTBNotification = new QMediaPlayer(this);
    informationTBNotification->setMedia(QUrl::fromLocalFile("C:/Users/Tommy/Desktop/QtGameLayout/music/informationboxnotification.wav"));
    mapOpen = new QMediaPlayer(this);
    mapOpen->setMedia(QUrl::fromLocalFile("C:/Users/Tommy/Desktop/QtGameLayout/music/openMap.wav"));
    skillClick = new QMediaPlayer(this);
    skillClick->setMedia(QUrl::fromLocalFile("C:/Users/Tommy/Desktop/QtGameLayout/music/skillbuttonclick.wav"));
    skillClick->setVolume(25);
    openSkills = new QMediaPlayer(this);
    openSkills->setMedia(QUrl::fromLocalFile("C:/Users/Tommy/Desktop/QtGameLayout/music/openskill.wav"));
    openSkills->setVolume(25);
    purchaseSound = new QMediaPlayer(this);
    purchaseSound->setMedia(QUrl::fromLocalFile("C:/Users/Tommy/Desktop/QtGameLayout/music/moneypay.wav"));
    purchaseSound->setVolume(25);
    //SKILL SOUNDS
    //BERSERKER
    skillCharge = new QMediaPlayer(this);
    skillCharge->setMedia(QUrl::fromLocalFile("C:/Users/Tommy/Desktop/QtGameLayout/music/spells/berserk/chargeComplete.wav"));
    skillCharge->setVolume(25);
    skillSpearThrust = new QMediaPlayer(this);
    skillSpearThrust->setMedia(QUrl::fromLocalFile("C:/Users/Tommy/Desktop/QtGameLayout/music/spells/berserk/spearThrust.wav"));
    skillSpearThrust->setVolume(25);
    skillBerserk = new QMediaPlayer(this);
    skillBerserk->setMedia(QUrl::fromLocalFile("C:/Users/Tommy/Desktop/QtGameLayout/music/spells/berserk/Berserk.wav"));
    //PALADIN
    skillStrike = new QMediaPlayer(this);
    skillStrike->setMedia(QUrl::fromLocalFile("C:/Users/Tommy/Desktop/QtGameLayout/music/spells/paladin/strike.aiff"));
    skillStrike->setVolume(25);
    skillShieldBash = new QMediaPlayer(this);
    skillShieldBash->setMedia(QUrl::fromLocalFile("C:/Users/Tommy/Desktop/QtGameLayout/music/spells/paladin/shieldBash.wav"));
    skillShieldBash->setVolume(25);
    skillHolyRay = new QMediaPlayer(this);
    skillHolyRay->setMedia(QUrl::fromLocalFile("C:/Users/Tommy/Desktop/QtGameLayout/music/spells/paladin/holyRay.wav"));
    skillHolyRay->setVolume(25);
    //WIZARD
    skillFireball = new QMediaPlayer(this);
    skillFireball->setMedia(QUrl::fromLocalFile("C:/Users/Tommy/Desktop/QtGameLayout/music/spells/wizard/fireball.wav"));
    skillFireball->setVolume(25);
    skillVoid = new QMediaPlayer(this);
    skillVoid->setMedia(QUrl::fromLocalFile("C:/Users/Tommy/Desktop/QtGameLayout/music/spells/wizard/void.wav"));
    skillVoid->setVolume(25);
    skillIceBreak = new QMediaPlayer(this);
    skillIceBreak->setMedia(QUrl::fromLocalFile("C:/Users/Tommy/Desktop/QtGameLayout/music/spells/wizard/ice.wav"));
    skillIceBreak->setVolume(25);
    //WARLOCK
    skillGazeOfFear = new QMediaPlayer(this);
    skillGazeOfFear->setMedia(QUrl::fromLocalFile("C:/Users/Tommy/Desktop/QtGameLayout/music/spells/warlock/gazeOfFear.wav"));
    skillGazeOfFear->setVolume(25);
    skillLifeTap = new QMediaPlayer(this);
    skillLifeTap->setMedia(QUrl::fromLocalFile("C:/Users/Tommy/Desktop/QtGameLayout/music/spells/warlock/lifeTap.mp3"));
    skillLifeTap->setVolume(25);
    skillSuffering = new QMediaPlayer(this);
    skillSuffering->setMedia(QUrl::fromLocalFile("C:/Users/Tommy/Desktop/QtGameLayout/music/spells/warlock/suffering.wav"));
    skillSuffering->setVolume(25);
    //THIEF
    skillPierce = new QMediaPlayer(this);
    skillPierce->setMedia(QUrl::fromLocalFile("C:/Users/Tommy/Desktop/QtGameLayout/music/spells/thief/pierce.wav"));
    skillPierce->setVolume(25);
    skillPistolShot = new QMediaPlayer(this);
    skillPistolShot->setMedia(QUrl::fromLocalFile("C:/Users/Tommy/Desktop/QtGameLayout/music/spells/thief/pistolShot.wav"));
    skillPistolShot->setVolume(25);
    skillHiddenStrike = new QMediaPlayer(this);
    skillHiddenStrike->setMedia(QUrl::fromLocalFile("C:/Users/Tommy/Desktop/QtGameLayout/music/spells/thief/hiddenStrike.wav"));
    skillHiddenStrike->setVolume(25);
    //ENEMY SOUNDS
    boarSound = new QMediaPlayer(this);
    boarSound->setMedia(QUrl::fromLocalFile("C:/Users/Tommy/Desktop/QtGameLayout/music/enemies/boar.wav"));
    boarSound->setVolume(100);
    dogSound = new QMediaPlayer(this);
    dogSound->setMedia(QUrl::fromLocalFile("C:/Users/Tommy/Desktop/QtGameLayout/music/enemies/wolf.wav"));
    dogSound->setVolume(25);

    //PUSH ENEMY SOUNDS BACK INTO CONTAINER

    //SET SLIDERS
    effectsSlider->setValue(inventoryOpen->volume());
    discoverySlider->setValue(discoverySound->volume());
    abilitiesSlider->setValue(skillStrike->volume());
    //CONNECT SLIDERS
    connect(effectsSlider, SIGNAL(valueChanged(int)), inventoryOpen, SLOT(setVolume(int)));
    connect(effectsSlider, SIGNAL(valueChanged(int)), gameScreenSettingsOpen, SLOT(setVolume(int)));
    connect(effectsSlider, SIGNAL(valueChanged(int)), informationTBNotification, SLOT(setVolume(int)));
    connect(effectsSlider, SIGNAL(valueChanged(int)), mapOpen, SLOT(setVolume(int)));
    connect(effectsSlider, SIGNAL(valueChanged(int)), openSkills, SLOT(setVolume(int)));
    connect(effectsSlider, SIGNAL(valueChanged(int)), skillClick, SLOT(setVolume(int)));
    //DISCOVERY SLIDER
    connect(discoverySlider, SIGNAL(valueChanged(int)), discoverySound, SLOT(setVolume(int)));
    //ABILITIES SLIDER
    connect(abilitiesSlider, SIGNAL(valueChanged(int)), skillStrike, SLOT(setVolume(int)));
    connect(abilitiesSlider, SIGNAL(valueChanged(int)), skillShieldBash, SLOT(setVolume(int)));
    connect(abilitiesSlider, SIGNAL(valueChanged(int)), skillHolyRay, SLOT(setVolume(int)));
    connect(abilitiesSlider, SIGNAL(valueChanged(int)), skillFireball, SLOT(setVolume(int)));
    connect(abilitiesSlider, SIGNAL(valueChanged(int)), skillVoid, SLOT(setVolume(int)));
    connect(abilitiesSlider, SIGNAL(valueChanged(int)), skillIceBreak, SLOT(setVolume(int)));
    connect(abilitiesSlider, SIGNAL(valueChanged(int)), skillGazeOfFear, SLOT(setVolume(int)));
    connect(abilitiesSlider, SIGNAL(valueChanged(int)), skillLifeTap, SLOT(setVolume(int)));
    connect(abilitiesSlider, SIGNAL(valueChanged(int)), skillSuffering, SLOT(setVolume(int)));
    connect(abilitiesSlider, SIGNAL(valueChanged(int)), skillPierce, SLOT(setVolume(int)));
    connect(abilitiesSlider, SIGNAL(valueChanged(int)), skillPistolShot, SLOT(setVolume(int)));
    connect(abilitiesSlider, SIGNAL(valueChanged(int)), skillHiddenStrike, SLOT(setVolume(int)));
    connect(abilitiesSlider, SIGNAL(valueChanged(int)), skillCharge, SLOT(setVolume(int)));
    connect(abilitiesSlider, SIGNAL(valueChanged(int)), skillSpearThrust, SLOT(setVolume(int)));
    connect(abilitiesSlider, SIGNAL(valueChanged(int)), skillBerserk, SLOT(setVolume(int)));
}

GameScreenSettings::~GameScreenSettings()
{
    delete ui;
}


void GameScreenSettings::on_effectsSlider_valueChanged()
{

}

void GameScreenSettings::on_discoverySlider_valueChanged()
{

}

void GameScreenSettings::on_abilitiesSlider_valueChanged()
{

}

void GameScreenSettings::on_saveB_clicked()
{

}

void GameScreenSettings::on_loadB_clicked()
{
    loaded = true;
}

