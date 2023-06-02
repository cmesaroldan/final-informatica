#include "mainwindow.h"
#include "puntaje.h"

#include <QApplication>

unsigned long int puntos = 0 ;        //Variable global para los puntos, se instancia en puntaje
short int vidas = 3 ;

puntaje *Score ;
puntaje *player_name ;
puntaje *health ;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
