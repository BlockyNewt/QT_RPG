#ifndef MAINMENUSETTINGS_H
#define MAINMENUSETTINGS_H

#include <QDialog>
#include <QSlider>
#include <QMediaPlayer>

namespace Ui {
class MainMenuSettings;
}

class MainMenuSettings : public QDialog
{
    Q_OBJECT

public:
    explicit MainMenuSettings(QWidget *parent = nullptr);
    ~MainMenuSettings();

    //SLIDER
    QSlider *volumeSlider;

    //MEDIA PLAYER
    QMediaPlayer *backgroundMusic, *clickEffect, *berserkerVoice, *paladinVoice, *wizardVoice, *warlockVoice, *thiefVoice;

private slots:
    void on_volumeSlider_valueChanged();

private:
    Ui::MainMenuSettings *ui;
};

#endif // MAINMENUSETTINGS_H
