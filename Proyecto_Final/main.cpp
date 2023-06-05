#include "mainwindow.h"
#include "puntaje.h"
#include <QApplication>


unsigned long int puntos = 0 ;        // Declaración de variables globales
short int vidas = 3 ;

puntaje *puntuacion ;
puntaje *nombre_jugador ;
puntaje *health ;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
