#ifndef JUGADOR_1_H
#define JUGADOR_1_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QTimer>



class jugador_1: public QObject, public QGraphicsPixmapItem
{
public:
    jugador_1();
    jugador_1(int n);
    void set_imagen_jugador(int n);
    int num_plane, frame = 0, tam_x_plane;// variables para la animacion de la cabeza.
    QTimer *animacion;

public slots:
    void animacion_sprite();



private:

    QPixmap sprite_jugador, sprite_actual;


};

#endif // JUGADOR_1_H
