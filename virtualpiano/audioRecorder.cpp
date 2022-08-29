//
// Created by Jason Xie on 2021-11-23.
//
#include "mainwindow.h"
#include "audioRecorder.h"

using namespace std;
using namespace boost::process;


audioRecorder::audioRecorder() { //constructor
}
audioRecorder::~audioRecorder() {}

// receive the file name from user and execute the record command in terminal
void audioRecorder::recordFile(QString filename){
    //    string recordCommand = "play " + filename + ".wav";
    string recordCommand = "rec -e float " + filename.toStdString() + ".wav";

    ipstream pipe_stream;
    child c(recordCommand, (std_out & std_err) > pipe_stream);
    address = &c;

    c.detach();
}

void audioRecorder::stopFile(){
    address->exit_code();
}

void audioRecorder::playFile(QString file){
    string playCommand = "play " + file.toStdString();
    ipstream pipe_stream;
    child c(playCommand, (std_out & std_err) > pipe_stream);
    address2 = &c;

    c.detach();
}

void audioRecorder::stopPlay(){
    address2->exit_code();
}