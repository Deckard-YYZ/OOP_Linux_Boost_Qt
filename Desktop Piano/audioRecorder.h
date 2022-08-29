//
// Created by Jason Xie on 2021-11-23.
//

#ifndef INC_3307_VIRTUALPIANO_AUDIORECORDER_H
#define INC_3307_VIRTUALPIANO_AUDIORECORDER_H

#include<iostream>
#include<string>
#include <QAudioRecorder>
#include <QAudioEncoderSettings>
#include <QMultimedia>
#include <QMediaRecorder>

//#include "sox.h"
#include <memory>
#include <boost/process.hpp>
#include <boost/process/exception.hpp>
#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;
using namespace boost::process;

class QLineEdit;
class QPushButton;
class QLabel;
class QTextBrowser;

class audioRecorder{
    //Q_OBJECT

public:
    audioRecorder();
    ~audioRecorder();

    public slots:
    //void addEffect(string, sox_format_t*);
    void recordFile(QString);
    void stopFile();
    void playFile(QString);
    void stopPlay();

private:
    QString result;
    child* address;
    child* address2;


};


#endif //INC_3307_VIRTUALPIANO_AUDIORECORDER_H
