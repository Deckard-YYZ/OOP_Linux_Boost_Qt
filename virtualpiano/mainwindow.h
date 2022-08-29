#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "VolumeControl.h"
#include <iostream>
#include <boost/asio.hpp>
#include <QSound>
#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <vector>
#include <QLabel>
#include <QTextEdit>
//#include <QGridLayout>
//#include <QListWidget>
//#include <QListWidgetItem>
#include <sstream>
#include <QApplication>
#include <QFrame>
#include <iostream>
#include <QPushButton>
#include<QtWidgets/QRadioButton>
#include<QtWidgets/QSlider>
#include<QFont>
#include<QtMultimedia/QMediaPlayer>
//#include<QSoundEffect>
#include <QKeyEvent>
#include"whitekey.h"
#include"whitefactory.h"
#include "blackkey.h"
#include "blackkeyfactory.h"
#include "tunescontrol.h"

class MainWindow : public QMainWindow
{
Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
private:
    //QSoundEffect sound;
    bool m_on = false;
    VolumeControl VC;
    tunescontrol TC;
    std::vector<QPushButton*> keys;
    QPushButton *Replay;
    QPushButton *Record;
    QPushButton *Pause;
    QPushButton *ReduceTune;
    QPushButton *AddTune;
    QPushButton *Metronome;
    QRadioButton *Mute;
    QSlider *VControl;
    QLabel *Tune;
    pianokey *cSharp;
    pianokey *eFlat;
    pianokey *fSharp;
    pianokey *gSharp;
    pianokey *bFlat;
    pianokey *cSharp2;
    pianokey *eFlat2;
    pianokey *C;
    pianokey *D;
    pianokey *E;
    pianokey *F;
    pianokey *G;
    pianokey *A;
    pianokey *B;
    pianokey *C_1;
    pianokey *D_1;
    pianokey *E_1;
    
    void handleMetronome();
    //void Metronome_run(const boost::system::error_code& /*e*/);
    void handlePianoKeys();
    void handleVolume();
    void handlemute();
    void handleTune();
    void keyPressEvent(QKeyEvent *event);

};

#endif