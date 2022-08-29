/*
 * @brief the factory class of creating white piano key objects
 * @author YUNZHUO ZHANG
 */
#ifndef WHITEFACTORY_H
#define WHITEFACTORY_H
#include "keyfactory.h"
#include "whitekey.h"
class whitefactory: public keyfactory
{
public:
/*
 * @brief the factory function of creating white piano key objects
 * @return the whitekey with specific configuration
 */
    virtual pianokey * CreateKey(QString piano_name,int x_axis, int y_axis, int width, int high,const QString& piano_tunes,QMainWindow* window){
        whitekey* akey = new whitekey(piano_name, window);
        akey->setAll(x_axis,y_axis,width,high,piano_tunes);
        return akey;
    }




};

#endif