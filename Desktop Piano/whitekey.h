/*
 * @brief the class represent white piano key
 * This class inheritant from QPushButton. It is also the subject notified by volume control and tunescontrol.
 * An initialed object of this class will contain a QSoundEffect Object with .wav file URL set.
 * Any key press event in GUI will trigger the corresponding  whitekey's QSoundEffect Object play sound.
 * @author YUNZHUO ZHANG, ZINAN GONG
 */
#ifndef WHITEKEY_H
#define WHITEKEY_H
#include"Pianokey.h"
#include <QMainWindow>
#include <QPushButton>
#include <QSoundEffect>
//use name-piano map to play sound, if change tune, name won't
class whitekey : public pianokey{
public:
    using pianokey::pianokey;
/*
 * @brief the funcion to set the QPushButton geometry and the unchanged represent string of that key
 * This function will be called in factory class after called the default constructor of QPushButton
 * @param x,y,w,h for x-axis,y-axis,width and height 
 * @param piano_tune  for the initial tune index of the this whitekey
 */
    void setAll(int x, int y , int w, int h, const QString& piano_tune);
/*
 * @brief the funcion to set a new URL of the QSoundEffect object 
 * This function will set a new URL of the QSoundEffect object, the new .wav is 
 * either the next tune of the current .wav or the previous tune 
 * @param newtune specifies the new tune index
 */
    void set_piano_tune(QString newtune) ;
/*
 * @brief the funcion change the geo of the white key at runtime
 * @param x,y,w,h for x-axis,y-axis,width and height 
 */
    void set_piano_geo(int x_axis, int y_axis, int width, int high);
/*
 * @brief the funcion calls play() for QSoundEffect
 */

    void play();
/*
 * @brief the funcion get notified by VolumeControl and change the volume of QSoundEffect object
 * @param volume for the new volume set by user
 */

    void volumenotify(qreal voulme);

/*
 * @brief the funcion get notified by tuneschange and change the URL 
 * of QSoundEffect object by calling set_piano_tune()
 * @param t for the new tune index 
 */

    void tunesnotify(QString t);

/*
 * @brief the funcion return the unchanged name of the pianokey object
 * @return the string name 
 */

    std::string get_piano_name();

private:
    //QPushButton * key;
    QString piano_tune;
    std::string name;//the unchange name
    QSoundEffect * sound;
};

#endif