/* 
Author: Yunzhuo Zhang    
Date: 2021/10/3
The cpp file of class mainwindow, which is the class of the whole GUI with its functions, signal handlers.
mianwindow will catch user inpute, pass the input to RenderContext class, get the command outputs, 
show the output in output widget, show history command on his widget, show exit on exit widget.
When user double clicked the history output, the output will be displayed on output widget again.
*/
#include "mainwindow.h"
using namespace std;

RenderContext rec;
/**
 * Fuction: MainWindow
 * Description: construct and initial everything of the GUI
 * Parameter: Qwidget parent
 * Return: None
*/
MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
{
  //For next assign
  QFont font = Tune->font();
  font.setPointSize(11);
  font.setBold(true);
  Replay = new QPushButton("Replay",this);
  Replay->setGeometry(130,90,141,61);
  Record = new QPushButton("Record",this);
  Record->setGeometry(388,90,131,61);
  ReduceTune = new QPushButton("<",this);
  ReduceTune->setGeometry(120,210,5,41);
  AddTune = new QPushButton(">",this);
  AddTune->setGeometry(220,210,51,41);
  Tune = new QLabel("+0",this);
  Tune->setGeometry(184,215,20,31);
  Metaphore = new QPushButton("Metaphore",this);
  Metaphore->setGeometry(390,190,131,71);
  Pause = new QPushButton("Pause",this);
  Pause->setGeometry(650,90,141,61);
  Mute = new QRadioButton("Mute",this);
  Mute->setGeometry(630,220,61,21);
  VControl = new QSlider(this);
  Tune->setFont(font);Replay->setFont(font);Record->setFont(font);ReduceTune->setFont(font);
  AddTune->setFont(font);Metaphore->setFont(font);Pause->setFont(font);Mute->setFont(font);
  //this part would be done by a function in the future



  //
  HisNum = 1;
  //create and locate the Button
  enter = new QPushButton("Enter", this);
  enter->setGeometry(430,30,75,23);
  //create and locate all Qlabels
  comd = new QLabel("Command",this);
  comd->setGeometry(60,30,75,23);//Command: Label
  output = new QLabel("Output",this);
  output->setGeometry(80,60,54,21);//Output Label
  exit = new QLabel("Exit State",this);
  exit->setGeometry(10,370,95,17);//Exit State Label
  his = new QLabel("History",this);
  his->setGeometry(80,404,61,21);//History Label
//create and locate horizontal line
line = new QFrame(this);
line->setGeometry(0,380,541,20);
line->setFrameShape(QFrame::HLine);
//create and locate the input box
comd_input = new QLineEdit(this);
comd_input->setGeometry(130,30,291,21);
//create and locate all text browsers
display_output = new QTextBrowser(this);
display_output->setGeometry(80,80,401,271);//output browser
display_his = new QListWidget(this);
display_his->setGeometry(80,425,401,271);//history browser
// Connect button signal to its handler
connect(enter, &QPushButton::released, this, &MainWindow::handleButton);
// Connect the double click history output signal to its handler
connect(display_his, &QListWidget::itemDoubleClicked, this , &MainWindow::showhis);
}

/**
 * Fuction: handleButton
 * Description: Button released handler
 * Parameter: None
 * Return: None
*/
void MainWindow::handleButton()
{
  QString s = comd_input->text();// transfer the command to a QString
  if(s == NULL){//if no text input, just exit the function(do nothing)
    return;
  }
  comd_input->setText("");//clean the input part for user
  display_output->setText(rec.setComdAndRun(s.toStdString()));//show the output
  //configure the context format to be |{HisNum}.comd ({ExitNum})|
  QString hisStr = QString::number(HisNum);//{HisNum}
  hisStr += '.';//{HisNum}.
  hisStr.append(s);//{HisNum}.comd
  HisNum++;
  QString exitstr = QString::fromStdString(to_string(rec.getexitStatus()));//{ExitNum}
  hisStr += " (" + exitstr + ")";//{HisNum}.comd ({ExitNum})
  QListWidgetItem *i = new QListWidgetItem(hisStr);
  display_his->addItem(i);//show this on his widget(add the ListWidgetItem on the ListWidget)
  exit->setText("Exit Status: ("+exitstr + ')');//show the exit status on exit widget
}
/**
 * Fuction: showhis
 * Description: history output double clicked handler, show the history output on output widget
 * Parameter: the ListWidgetItem that being double clicked
 * Return: None
*/
void MainWindow::showhis(QListWidgetItem * item)
{

  int i = display_his->row(item);//get the command index
  string s = rec.getNthOutput(i);//get that output
  string comd_withexit = item->text().toStdString();//get the context of history command
  //"Exit Status: " + ({Exit Status}) to construct a QString
  string the_exit = "Exit Status: " + comd_withexit.substr(comd_withexit.length()-4,comd_withexit.length()-2);
  QString exitstr = QString::fromStdString(the_exit);
  exit->setText(exitstr);//show the exit status on the exit status widget
  //QMessageBox::information(this,item->text(),QString::fromStdString(s)); an alternative 
  display_output->setText(QString::fromStdString(s));//show the his output on output widget
}
/**
 * Fuction: ~MainWindow
 * Description: the  destorctor 
 * Parameter: None
 * Return: None
*/
MainWindow::~MainWindow(){
  delete enter;
  delete comd_input;
  delete comd;
  delete output;
  delete exit;
  delete his;
  delete line;
  delete display_output;
  delete display_his;
}

