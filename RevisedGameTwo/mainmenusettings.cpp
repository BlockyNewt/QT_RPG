#include "mainmenusettings.h"
#include "ui_mainmenusettings.h"

#include <QPixmap>

MainMenuSettings::MainMenuSettings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainMenuSettings)
{
    ui->setupUi(this);

    //WINDOW INFORMATION
    setWindowTitle("Main Menu Settings");
    resize(430,500);

    //WINDOW BACKGROUND
    QPixmap pix("C:/Users/Tommy/Desktop/QtGameLayout/mainMenuSettings.png");
    QPalette palette;
    palette.setBrush(QPalette::Background, pix);
    this->setPalette(palette);

    //SLIDER
    this->volumeSlider = ui->volumeSlider;

    //MEDIA PLAYER
    backgroundMusic = new QMediaPlayer(this);
    backgroundMusic->setMedia(QUrl::fromLocalFile("C:/Users/Tommy/Desktop/QtGameLayout/music/lotr.wav"));
    clickEffect = new QMediaPlayer(this);
    clickEffect->setMedia(QUrl::fromLocalFile("C:/Users/Tommy/Desktop/QtGameLayout/music/buttonClick.mp3"));
    berserkerVoice = new QMediaPlayer(this);
    berserkerVoice->setMedia(QUrl::fromLocalFile("C:/Users/Tommy/Desktop/QtGameLayout/music/voices/berserkerVoice2.wav"));
    paladinVoice = new QMediaPlayer(this);
    paladinVoice->setMedia(QUrl::fromLocalFile("C:/Users/Tommy/Desktop/QtGameLayout/music/voices/paladinVoice.wav"));
    wizardVoice = new QMediaPlayer(this);
    wizardVoice->setMedia(QUrl::fromLocalFile("C:/Users/Tommy/Desktop/QtGameLayout/music/voices/wizardVoice.wav"));
    warlockVoice = new QMediaPlayer(this);
    warlockVoice->setMedia(QUrl::fromLocalFile("C:/Users/Tommy/Desktop/QtGameLayout/music/voices/warlockVoice.wav"));
    thiefVoice = new QMediaPlayer(this);
    thiefVoice->setMedia(QUrl::fromLocalFile("C:/Users/Tommy/Desktop/QtGameLayout/music/voices/thiefVoice.wav"));

    //SOUND SETTINGS
    backgroundMusic->setVolume(100);

    //SOUND AND VOLUME SETTINGS
    volumeSlider->setValue(backgroundMusic->volume());
    connect(volumeSlider, SIGNAL(valueChanged(int)), backgroundMusic, SLOT(setVolume(int)));

}

MainMenuSettings::~MainMenuSettings()
{
    delete ui;
}


void MainMenuSettings::on_volumeSlider_valueChanged()
{

}
