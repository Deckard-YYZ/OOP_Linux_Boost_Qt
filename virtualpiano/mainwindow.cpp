#include "mainwindow.h"

//#include "VolumeControl.cpp"//we know this is wrong but we couldn't figure out a solution, so sad

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent)
{
    resize(964,710);
    //all the configure buttons
    Replay = new QPushButton("Replay",this);
    Replay->setGeometry(130,90,141,61);
    Record = new QPushButton("Record",this);
    Record->setGeometry(388,90,131,61);
    //buttons for tune change and connect them to handler
    ReduceTune = new QPushButton("<",this);
    ReduceTune->setGeometry(120,210,51,41);
    AddTune = new QPushButton(">",this);
    AddTune->setGeometry(220,210,51,41);
    connect(ReduceTune,&QPushButton::released,this,&MainWindow::handleTune);
    connect(AddTune,&QPushButton::released,this,&MainWindow::handleTune);

    Tune = new QLabel("+0",this);
    Tune->setGeometry(184,215,31,31);
    QFont font = Tune->font();
    font.setPointSize(11);
    font.setBold(true);
    Metronome = new QPushButton("< | >",this);
    Metronome->setGeometry(860,70,100,41);
    Pause = new QPushButton("Pause",this);
    Pause->setGeometry(650,90,141,61);
    Mute = new QRadioButton("Mute",this);
    Mute->setGeometry(630,220,65,21);
    connect(Mute, &QRadioButton::released,this,&MainWindow::handlemute);

    VControl = new QSlider(this);
    VControl->setOrientation(Qt::Horizontal);
    VControl->setMinimum(0);
    VControl->setMaximum(100);
    VControl->setValue(30);
    VControl->setGeometry(695,220,160,22);
    connect(VControl, &QSlider::valueChanged, this, &MainWindow::handleVolume);//connect to the Volume Control class
    handleVolume();//to set the default sound to not too loud either too silent
    //set font for these buttons
    Tune->setFont(font);Replay->setFont(font);Record->setFont(font);ReduceTune->setFont(font);
    AddTune->setFont(font);Metronome->setFont(font);Pause->setFont(font);Mute->setFont(font);


        //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    whitefactory wf;
    C = wf.CreateKey("\n\n\n\nC",93,296,90,350,"C+0",this);
    D = wf.CreateKey("\n\n\n\nD",169,296,90,350,"D+0",this);
    E = wf.CreateKey("\n\n\n\nE",245,296,90,350,"E+0",this);
    F = wf.CreateKey("\n\n\n\nF",321,296,90,350,"F+0",this);
    G = wf.CreateKey("\n\n\n\nG",397,296,90,350,"G+0",this);
    A = wf.CreateKey("\n\n\n\nA",473,296,90,350,"A+0",this);
    B = wf.CreateKey("\n\n\n\nB",549,296,90,350,"B+0",this);
    C_1 = wf.CreateKey("\n\n\n\nC_1",625,296,90,350,"C_1",this);
    D_1 = wf.CreateKey("\n\n\n\nD_1",701,296,90,350,"D+1",this);
    E_1 = wf.CreateKey("\n\n\n\nE_1",777,296,80,350,"E+1",this);
    //add white keys to the sound observer vector
    VC.attachsound(C);VC.attachsound(D);VC.attachsound(E);VC.attachsound(F);VC.attachsound(G);
    VC.attachsound(A);VC.attachsound(B);VC.attachsound(C_1);VC.attachsound(D_1);VC.attachsound(E_1);
    //add white keys to the Qpushbutton vector
    TC.attachtunes(C);TC.attachtunes(D);TC.attachtunes(E);TC.attachtunes(F);TC.attachtunes(G);
    TC.attachtunes(A);TC.attachtunes(B);TC.attachtunes(C_1);TC.attachtunes(D_1);TC.attachtunes(E_1);
    keys.push_back(C);keys.push_back(D);keys.push_back(E);keys.push_back(F);keys.push_back(G);
    keys.push_back(A);keys.push_back(B);keys.push_back(C_1);keys.push_back(D_1);keys.push_back(E_1);
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    blackkeyfactory bf;
    cSharp = bf.CreateKey("C#",146,296,60,180,"cSharp",this);
    eFlat = bf.CreateKey("Eb",222,296,60,180,"eFlat",this);
    fSharp = bf.CreateKey("F#",374,296,60,180,"fSharp",this);
    gSharp = bf.CreateKey("G#",450,296,60,180,"gSharp",this);
    bFlat = bf.CreateKey("Bb",526,296,60,180,"bFlat",this);
    cSharp2 = bf.CreateKey("C#",678,296,60,180,"cSharp2",this);
    eFlat2 = bf.CreateKey("Eb",754,296,60,180,"eFlat2",this);
    VC.attachsound(cSharp);VC.attachsound(eFlat);VC.attachsound(fSharp);VC.attachsound(gSharp);
    VC.attachsound(bFlat);VC.attachsound(cSharp2);VC.attachsound(eFlat2);
    //cSharp = new QPushButton("C#", this);
//    cSharp->setObjectName("cSharp");
//    eFlat = new QPushButton("Eb", this);
//    eFlat->setObjectName("eFlat");
//    fSharp = new QPushButton("F#", this);
//    fSharp->setObjectName("fSharp");
//    gSharp = new QPushButton("G#", this);
//    gSharp->setObjectName("gSharp");
//    bFlat = new QPushButton("Bb", this);
//    bFlat->setObjectName("bFlat");
//    cSharp2 = new QPushButton("C#", this);
//    cSharp2->setObjectName("cSharp2");
//    eFlat2 = new QPushButton("Eb", this);
//    eFlat2->setObjectName("eFlat2");
    //add black keys to the Qpushbutton vectors
    keys.push_back(cSharp);keys.push_back(eFlat);keys.push_back(fSharp);keys.push_back(gSharp);
    keys.push_back(bFlat);keys.push_back(cSharp2);keys.push_back(eFlat2);

//    cSharp->setGeometry(146,296,60,180);
//    cSharp->setStyleSheet("QPushButton:!default{background-color: rgb(0, 0, 0);border-style:solid;border-right-color: rgb(255, 255, 255);color: rgb(255, 255, 255);}");
//    eFlat->setGeometry(222,296,60,180);
//    eFlat->setStyleSheet("QPushButton:!default{background-color: rgb(0, 0, 0);border-style:solid;border-right-color: rgb(255, 255, 255);color: rgb(255, 255, 255);}");
//    fSharp->setGeometry(374,296,60,180);
//    fSharp->setStyleSheet("QPushButton:!default{background-color: rgb(0, 0, 0);border-style:solid;border-right-color: rgb(255, 255, 255);color: rgb(255, 255, 255);}");
//    gSharp->setGeometry(450,296,60,180);
//    gSharp->setStyleSheet("QPushButton:!default{background-color: rgb(0, 0, 0);border-style:solid;border-right-color: rgb(255, 255, 255);color: rgb(255, 255, 255);}");
//    bFlat->setGeometry(526,296,60,180);
//    bFlat->setStyleSheet("QPushButton:!default{background-color: rgb(0, 0, 0);border-style:solid;border-right-color: rgb(255, 255, 255);color: rgb(255, 255, 255);}");
//    cSharp2->setGeometry(678,296,60,180);
//    cSharp2->setStyleSheet("QPushButton:!default{background-color: rgb(0, 0, 0);border-style:solid;border-right-color: rgb(255, 255, 255);color: rgb(255, 255, 255);}");
//    eFlat2->setGeometry(754,296,60,180);
//    eFlat2->setStyleSheet("QPushButton:!default{background-color: rgb(0, 0, 0);border-style:solid;border-right-color: rgb(255, 255, 255);color: rgb(255, 255, 255);}");
    //all piano keys
    // C = new QPushButton("\n\n\n\nC",this);
    // C->setObjectName("C");
    // D = new QPushButton("\n\n\n\nD",this);
    // D->setObjectName("D");
    // E = new QPushButton("\n\n\n\nE",this);
    // E->setObjectName("E");
    // F = new QPushButton("\n\n\n\nF",this);
    // F->setObjectName("F");
    // G = new QPushButton("\n\n\n\nG",this);
    // G->setObjectName("G");
    // A = new QPushButton("\n\n\n\nA",this);
    // A->setObjectName("A");
    // B = new QPushButton("\n\n\n\nB",this);
    // B->setObjectName("B");
    // C_1 = new QPushButton("\n\n\n\nC_1",this);
    // C_1->setObjectName("C_1");
    // D_1 = new QPushButton("\n\n\n\nD_1",this);
    // D_1->setObjectName("D_1");
    // E_1 = new QPushButton("\n\n\n\nE_1",this);
    // E_1->setObjectName("E_1");
    // C->setGeometry(93,296,90,350);
    // D->setGeometry(169,296,90,350);
    // E->setGeometry(245,296,90,350);
    // F->setGeometry(321,296,90,350);
    // G->setGeometry(397,296,90,350);
    // A->setGeometry(473,296,90,350);
    // B->setGeometry(549,296,90,350);
    // C_1->setGeometry(625,296,90,350);
    // D_1->setGeometry(701,296,90,350);
    // E_1->setGeometry(777,296,90,350);
    //whitekey *C = new whitekey("\n\n\n\nC",93,296,90,350,"C",this);
    // whitekey *D = new whitekey("\n\n\n\nD",169,296,90,350,"D",this);
    // whitekey *E = new whitekey("\n\n\n\nE",245,296,90,350,"E",this);
    // whitekey *F = new whitekey("\n\n\n\nF",321,296,90,350,"F",this);
    // whitekey *G = new whitekey("\n\n\n\nG",397,296,90,350,"G",this);
    // whitekey *A = new whitekey("\n\n\n\nA",473,296,90,350,"A",this);
    // whitekey *B = new whitekey("\n\n\n\nB",549,296,90,350,"B",this);
    // whitekey *C_1 = new whitekey("\n\n\n\nC_1",625,296,90,350,"C_1",this);
    // whitekey *D_1 = new whitekey("\n\n\n\nD_1",701,296,90,350,"D_1",this);
    // whitekey *E_1 = new whitekey("\n\n\n\nE_1",777,296,80,350,"E_1",this);

    //connect all keys to the same handler
    for (auto ir = keys.begin(); ir != keys.end(); ++ir){
        connect(*ir, &QPushButton::clicked, this, &MainWindow::handlePianoKeys);
    }
    //sound.setVolume(0.5);
}
//play sound should be another


void MainWindow::handleMetronome(){
    if(m_on){
        m_on = false;
        Metronome->setText("<  |  >");
    }else{
        m_on = true;
    }
    while(m_on){
        QSound::play("");
    }
}



void MainWindow::handleTune(){
    QPushButton *addORreduece = (QPushButton *)sender();
    QString qs = Tune->text();
    std::string s = qs.toStdString();
    char posOrNeg = s.at(0);
    int a = s.at(1) - '0';
    QString out;
    if(addORreduece->text() == ">"){
        if (qs == "+2")
        {
            return;
        }
        if(posOrNeg == '+'){
            a++;
            out = QString::fromStdString("+") + QString::number(a);

        }else{
            a--;
            if (a == 0)
            {
                out = QString::fromStdString("+") + QString::number(a);
            }else{
                out = QString::fromStdString("-") + QString::number(a);
            }
        }
    }else{
        if(qs == "-2"){
            return;
        }
        if(posOrNeg == '+'){
            if (a == 0){
                a++;
                out = QString::fromStdString("-") + QString::number(a);
            }else{
                a--;
                out = QString::fromStdString("+") + QString::number(a);
            }
        }else{
            a++;
            out = QString::fromStdString("-") + QString::number(a);
        }
    }
    Tune->setText(out);
    TC.tcontrol(out);
//    }

}

void MainWindow::handlemute(){
    if(Mute->isChecked()){
        VC.control(0);
        Replay->setText("DOWNNNNN!");
    }
    else{
        handleVolume();
        Replay->setText("Raise!!!!");
    }
}
void MainWindow::handlePianoKeys(){
    // QString objn = "mysound/";

    //thekey->play();
    // QString key = thekey->objectName();
    // objn =  objn + key +".wav";
    // sound.setSource(QUrl::fromLocalFile(objn));
    pianokey *thekey = (pianokey *)sender();
    thekey->play();


}
void MainWindow::handleVolume(){
    qreal a = (qreal) (VControl->value())/(qreal)100;
    Record->setText(QString::number(a));
    VC.control(a);
    //std::cout << a << std::endl;
}

void MainWindow::keyPressEvent(QKeyEvent *event){
    int keyboard_key = event->key();
    switch(keyboard_key){
        case Qt::Key_A:emit C->animateClick();break;
        case Qt::Key_W:emit cSharp->animateClick();break;
        case Qt::Key_S:emit D->animateClick();break;
        case Qt::Key_E:emit eFlat->animateClick();break;
        case Qt::Key_D:emit E->animateClick();break;
        case Qt::Key_F:emit F->animateClick();break;
        case Qt::Key_T:emit fSharp->animateClick();break;
        case Qt::Key_G:emit G->animateClick();break;
        case Qt::Key_Y:emit gSharp->animateClick();break;
        case Qt::Key_H:emit A->animateClick();break;
        case Qt::Key_U:emit bFlat->animateClick();break;
        case Qt::Key_J:emit B->animateClick();break;
        case Qt::Key_K:emit C_1->animateClick();break;
        case Qt::Key_O:emit cSharp2->animateClick();break;
        case Qt::Key_L:emit D_1->animateClick();break;
        case Qt::Key_P:emit eFlat2->animateClick();break;
        case Qt::Key_Semicolon:emit E_1->animateClick();break;
    }
}
