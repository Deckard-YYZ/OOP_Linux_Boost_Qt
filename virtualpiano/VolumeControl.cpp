#include "VolumeControl.h"
VolumeControl::VolumeControl(){}
void VolumeControl::attachsound(pianokey* s){
    if (find(sound_obsever.begin(), sound_obsever.end(), s) == sound_obsever.end())
    this->sound_obsever.push_back(s);

}
void VolumeControl::detachsound(pianokey* s){
    std::vector<pianokey*>::iterator it;

    it = find(sound_obsever.begin(), sound_obsever.end(), s);

    if (it != sound_obsever.end())
        sound_obsever.erase(it);
}

void VolumeControl::control(qreal v){
    std::vector<pianokey*>::iterator it;

    for (it = sound_obsever.begin(); it != sound_obsever.end(); ++it)
        (*it)->volumenotify(v);


}

