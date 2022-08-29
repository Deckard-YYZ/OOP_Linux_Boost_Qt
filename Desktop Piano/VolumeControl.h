/*
 * @brief a obsever class that observe the change of  GUI Volume slider and send change to every pianokey objects
 * This class will add pianokey objects to the sound_observer vector and when a volume silder change value
 * on GUI, handler in mainwindow class will call a object of this class and that object will notify 
 * every pianokey objects attached to it to achieve volume change functionality.
 * @author YUNZHUO ZHANG
 */
#ifndef VCONTROL_H
#define VCONTROL_H

#include<iostream>
#include<string>
#include<vector>
#include"Pianokey.h"
class VolumeControl{

public:
/*
 * @brief constructor of VolumeControl
 */
        VolumeControl();
/*
 * @brief the function to notify every pianokey objects attached to this object a volume change event happened
 * Notify every objects inside sound_obsever a volume change event happened with the 
 * new volume amount number in double.
 * @param v the new volume
 */
        void control(qreal v);
/*
 * @brief the function to attach a piano key to the notify vector
 * @param s the pointer point to a piano key object
 */
        void attachsound(pianokey* s);
/*
 * @brief the function to detach a piano key to the notify vector
 * @param s the pointer point to a piano key object
 */
        void detachsound(pianokey* s);

private:
        std::vector<pianokey*> sound_obsever;
        //QSoundEffect * sound;

};

#endif