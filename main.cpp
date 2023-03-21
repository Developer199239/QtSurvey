#include "mainwindow.h"

#include <QApplication>
#include<QSplashScreen>
#include<QTimer>
#include <QWidget>
#include <QLabel>
#include <QTimer>
#include "loginwindow.h"
#include "homewindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    QSplashScreen *splash = new QSplashScreen;
//    splash->setPixmap(QPixmap(":/icons/splash_bg.png"));
//    splash->show();

//    LoginWindow loginWindow;
//    QTimer::singleShot(2000,splash,SLOT(close()));
//    QTimer::singleShot(2000,&loginWindow,SLOT(show()));

    HomeWindow homeWindow;
  homeWindow.show();

    return a.exec();
}
