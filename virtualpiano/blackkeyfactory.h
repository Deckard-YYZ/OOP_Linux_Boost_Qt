/*
 * @brief the factory class of creating black piano key objects
 * @author YUNZHUO ZHANG
 */
#ifndef VIRTUALPIANO_BLACKKEYFACTORY_H
#define VIRTUALPIANO_BLACKKEYFACTORY_H
#include "keyfactory.h"
#include "blackkey.h"
class blackkeyfactory: public keyfactory
        {

        public:
/*
 * @brief the factory function of creating black piano key objects
 * @return the whitekey with specific configuration
 */
            virtual pianokey * CreateKey(QString piano_name,int x_axis, int y_axis, int width, int high,const QString& piano_tunes,QMainWindow* window){
                blackkey* akey = new blackkey(piano_name, window);
                akey->setAll(x_axis,y_axis,width,high,piano_tunes);
                return akey;

            }




        };


#endif //VIRTUALPIANO_BLACKKEYFACTORY_H
