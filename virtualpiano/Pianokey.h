/*
 * @brief the base class represent piano key
 * This class inheritant from QPushButton. It is also the subject notified by volume control and tunescontrol.
 * An initialed object of this class will contain a QSoundEffect Object with .wav file URL set.
 * @author ZINAN GONG
 */

#ifndef PIANO_KEY_H
#define PIANO_KEY_H
#include<QString>
#include<string>
#include<QPushButton>
#include<iostream>
class pianokey: public QPushButton {
private: QString piano_name;
private:
public:
    using QPushButton::QPushButton;
/*
 * Not implement, pure virtual
 * @brief the funcion to set a new URL of the QSoundEffect object 
 * This function will set a new URL of the QSoundEffect object, the new .wav is 
 * either the next tune of the current .wav or the previous tune 
 * @param newtune specifies the new tune index
 */  
    virtual void set_piano_tune(QString) = 0;
/*
 * Not implement, pure virtual
 * @brief the funcion change the geo of the key at runtime
 */ 
    virtual void set_piano_geo(int,int,int,int) =0;
 /*
 * Not implement, pure virtual
 * @brief the funcion calls play() for QSoundEffect
 */   
    virtual void play() =0;
/*
 * Not implement, pure virtual
 * @brief the funcion get notified by VolumeControl and change the volume of QSoundEffect object
 */
    virtual void volumenotify(qreal) = 0;
/*
 * Not implement, pure virtual
 * @brief the funcion get notified by tuneschange and change the URL 
 */
    virtual void tunesnotify(QString) = 0;
/*
 * Not implement, pure virtual
 * @brief the funcion return the unchanged name of the pianokey object
 * @return the string name 
 */
    virtual std::string get_piano_name()=0;

};


#endif //VIRTUALPIANO_PIANOKEY_H
