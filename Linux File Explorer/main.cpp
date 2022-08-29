#include<QtWidgets/QApplication>
#include "mainwindow.h"
#include"RenderContext.h"

 
int main(int argc, char *argv[]) 
{
  QApplication app(argc, argv);
  QApplication EditorApp(argc,argv);

  MainWindow mainWindow;
  mainWindow.setGeometry(0,0,541,746);
  mainWindow.showNormal();
  return app.exec();
}