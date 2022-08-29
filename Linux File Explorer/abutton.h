#ifndef ABUTTON_H
#define ABUTTON_H

#include<QtWidgets/QPushButton>
#include<QtWidgets/QMainWindow>
#include<QtWidgets/QWidget>
namespace buttons {
  class abutton;
}
class abutton : public QMainWindow
{
  Q_OBJECT
  
public:
private:
    QPushButton* push;
};


#endif 
