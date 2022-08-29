/*
 * @brief the base factory class of creating piano key objects
 * @author YUNZHUO ZHANG
 */
#ifndef KEYFACTORY_H
#define KEYFACTORY_H

#include <string>
#include"Pianokey.h"
#include<QMainWindow>
class keyfactory
{
  public:
    
  
  protected:
/*
 * @brief the base factory function of creating piano key objects
 * @return a pianokey object with specific configuration
 */  
    virtual pianokey* CreateKey(QString ,int , int , int , int ,const QString& ,QMainWindow* ) = 0;
};

#endif
