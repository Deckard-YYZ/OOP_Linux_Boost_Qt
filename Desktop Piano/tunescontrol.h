
#include<iostream>
#include<string>
#include<vector>
#include"Pianokey.h"
#ifndef PIANOFINAL2_TUNESCONTROL_H
#define PIANOFINAL2_TUNESCONTROL_H

class tunescontrol {
public:
    tunescontrol();
    void attachtunes(pianokey* s);
    void detachtunes(pianokey* s);
    void tcontrol(QString t);

private:
    std::vector<pianokey*> tunes_observer;
};


#endif //PIANOFINAL2_TUNESCONTROL_H
