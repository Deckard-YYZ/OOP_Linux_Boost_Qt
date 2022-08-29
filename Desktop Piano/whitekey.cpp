#include "whitekey.h"
void whitekey::setAll(int x, int y , int w, int h, const QString& piano_tune){
    this->setGeometry(x,y,w,h);
    name = this->text().toStdString();
    QString url = "mysound/" + piano_tune + ".wav";
    sound = new QSoundEffect();
    sound->setSource(QUrl::fromLocalFile(url));
    //std::cout << this->name  << std::endl;
}
void whitekey::set_piano_tune(QString newtune){
    std::string tmp = this->name;
    tmp.erase(std::remove(tmp.begin(),tmp.end(),'\n'),tmp.end());
    QString Qname = QString::fromStdString(tmp);
    QString url = "mysound/" + Qname + newtune + ".wav";
    sound->setSource(QUrl::fromLocalFile(url));
}
void whitekey::set_piano_geo(int x_axis, int y_axis, int width, int high){
    this->setGeometry(x_axis,y_axis,width,high);
}

void whitekey::play(){
    sound->play();

}

void whitekey::volumenotify(qreal volume){
    sound->setVolume(volume);
    //std::cout << this-> name  << std::endl;
}
void whitekey::tunesnotify(QString t) {
    std::string tmp = this->name;
    QString Qname = QString::fromStdString(tmp)+"\n"+t;
    this->setText(Qname);
    this->set_piano_tune(t);
}
std::string whitekey::get_piano_name() {
    return this->name;
}