/* 
Author: Yunzhuo Zhang
Date: 2021/10/3
The header file of class mainwindow
*/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include"RenderContext.h"
#include<QtCore/QString>
#include<QtWidgets/QMainWindow>
#include<QtWidgets/QPushButton>
#include<QtWidgets/QLabel>
#include<QtWidgets/QLineEdit>
#include<QtWidgets/QFrame>
#include<QtWidgets/QTextBrowser>
#include<QtCore/QFile>
#include<QtCore/QTextStream>
#include<QtWidgets/QListWidget>
#include<QtWidgets/QMessageBox>
//for group
#include<QtWidgets/QRadioButton>
#include<QtWidgets/QSlider>
#include<QFont>
//


namespace Ui {
  class MainWindow;
}
class MainWindow : public QMainWindow
{
  Q_OBJECT
  
public:
  int HisNum; //the num indicates how many comds have entered
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow();
private slots:
  void handleButton();
  void showhis(QListWidgetItem*);
private:
  RenderContext rec;
  //for next assign
  QPushButton *Replay;
  QPushButton *Record;
  QPushButton *Pause;
  QPushButton *ReduceTune;
  QPushButton *AddTune;
  QPushButton *Metaphore;
  //QPushButton *Pause;
  QRadioButton *Mute;
  QSlider *VControl;
  QLabel *Tune;


  //
  
  QPushButton *enter;
  QLineEdit *comd_input;
  QLabel *comd,*output,*exit,*his;
  QFrame *line;
  QTextBrowser *display_output;
  QListWidget *display_his;

};
#endif // MAINWINDOW_H