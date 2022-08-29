QT       += core widgets gui multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TARGET = CommandGUI
TEMPLATE = app
SOURCES += main.cpp mainwindow.cpp VolumeControl.cpp whitekey.cpp tunescontrol.cpp blackkey.cpp audioRecorder.cpp
HEADERS += mainwindow.h VolumeControl.h whitekey.h whitefactory.h Pianokey.h tunescontrol.h blackkeyfactory.h blackkey.h audioRecorder.h
INCLUDEPATH += /usr/include/x86_64-linux-gnu/qt5 $$PWD
LIBS += -lboost_thread -lpthread