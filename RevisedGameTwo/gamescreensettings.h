#ifndef GAMESCREENSETTINGS_H
#define GAMESCREENSETTINGS_H

#include <QDialog>
#include <QSlider>
#include <QMediaPlayer>
#include <QPushButton>

namespace Ui {
class GameScreenSettings;
}

class GameScreenSettings : public QDialog
{
    Q_OBJECT

public:
    explicit GameScreenSettings(QWidget *parent = nullptr);
    ~GameScreenSettings();

    //BOOL TO CHECK IF IT WAS LOADED
    bool loaded = false;

    //PUSH BUTTONS
    QPushButton *saveB, *loadB;
    //SLIDERS
    QSlider *effectsSlider, *discoverySlider, *abilitiesSlider;

    //EFFECTS AND MUSIC
    QMediaPlayer *inventoryOpen, *gameScreenSettingsOpen, *discoverySound, *informationTBNotification, *mapOpen;
    QMediaPlayer *skillClick, *openSkills, *purchaseSound;
    //SKILL SOUNDS
    QMediaPlayer *skillCharge, *skillSpearThrust, *skillBerserk;
    QMediaPlayer *skillStrike, *skillShieldBash, *skillHolyRay;
    QMediaPlayer *skillFireball, *skillVoid, *skillIceBreak;
    QMediaPlayer *skillGazeOfFear, *skillLifeTap, *skillSuffering;
    QMediaPlayer *skillPierce, *skillPistolShot, *skillHiddenStrike;

    //ENEMY SOUNDS
    QMediaPlayer *boarSound, *dogSound;

    //FUNCTIONS
    void saveGame();
    void loadGame();


private slots:
    void on_effectsSlider_valueChanged();
    void on_discoverySlider_valueChanged();
    void on_abilitiesSlider_valueChanged();
    //SAVE AND LOAD BUTTONS
    void on_saveB_clicked();
    void on_loadB_clicked();

private:
    Ui::GameScreenSettings *ui;
};

#endif // GAMESCREENSETTINGS_H
