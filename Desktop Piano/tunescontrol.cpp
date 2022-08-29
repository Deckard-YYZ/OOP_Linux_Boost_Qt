//
// Created by 龚梓南 on 2021/11/27.
//

#include "tunescontrol.h"

tunescontrol::tunescontrol() {

}
void tunescontrol::attachtunes(pianokey *s) {
    if (find(tunes_observer.begin(), tunes_observer.end(), s) == tunes_observer.end())
        this->tunes_observer.push_back(s);
}
void tunescontrol::detachtunes(pianokey *s) {
    std::vector<pianokey*>::iterator it;

    it = find(tunes_observer.begin(), tunes_observer.end(), s);

    if (it != tunes_observer.end())
        tunes_observer.erase(it);
}
void tunescontrol::tcontrol(QString t){
    std::vector<pianokey*>::iterator it;

    for (it = tunes_observer.begin(); it != tunes_observer.end(); ++it)
        (*it)->tunesnotify(t);
}

