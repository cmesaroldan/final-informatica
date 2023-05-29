#ifndef JUEGO_H
#define JUEGO_H
#include <QObject>
#include <QGraphicsScene>
#include "jugador_1.h"
#include "fondo_niveles.h"


class juego: public QObject
{
public:
    juego();
    void escena_Menu();

    void set_level_one();

    int getTam_X() const;

    int getTam_Y() const;

    QGraphicsScene *getMenu() const;



public slots:


    private:
    int tam_X = 800, tam_Y = 600;    //tamaños del graphics view,
    int nivel_jugador = 1;
    QGraphicsScene *menu, *level_one;
    Fondo_niveles *backg_screen ;

};

#endif // JUEGO_H
