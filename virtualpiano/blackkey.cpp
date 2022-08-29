#include "blackkey.h"
void blackkey::setAll(int x, int y , int w, int h, const QString& piano_tune){
    this->setGeometry(x,y,w,h);
    this->setStyleSheet("QPushButton:!default{background-color: rgb(0, 0, 0);border-style:solid;border-right-color: rgb(255, 255, 255);color: rgb(255, 255, 255);}");
    name = piano_tune.toStdString();
    QString url = "mysound/" + piano_tune + ".wav";
    sound = new QSoundEffect();
    sound->setSource(QUrl::fromLocalFile(url));
    sound->setVolume(0.3);
    //std::cout << this->name  << std::endl;
}
void blackkey::set_piano_tune(QString newtune){
    std::string tmp = this->name;
    tmp.erase(std::remove(tmp.begin(),tmp.end(),'\n'),tmp.end());
    QString Qname = QString::fromStdString(tmp);
    QString url = "/Users/gongzinan/CLionProjects/jerry/mysound/" + Qname + newtune + ".wav";
    sound->setSource(QUrl::fromLocalFile(url));
}
void blackkey::set_piano_geo(int x_axis, int y_axis, int width, int high){
    this->setGeometry(x_axis,y_axis,width,high);
}

void blackkey::play(){
    sound->play();

}

void blackkey::volumenotify(qreal voulme){
    sound->setVolume(voulme);

    //std::cout << this-> name  << std::endl;
}
void blackkey::tunesnotify(QString t) {
    std::string tmp = this->name;
    QString Qname = QString::fromStdString(tmp)+"\n"+t;
    this->setText(Qname);
    this->set_piano_tune(t);
}
std::string blackkey::get_piano_name() {
    return this->name;
}