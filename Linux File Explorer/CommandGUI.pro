QT       += core widgets
TARGET = CommandGUI
TEMPLATE = app 
SOURCES += main.cpp mainwindow.cpp  RenderContext.cpp abutton.cpp
HEADERS += mainwindow.h abutton.h
LIBS += -lboost_thread -lpthread