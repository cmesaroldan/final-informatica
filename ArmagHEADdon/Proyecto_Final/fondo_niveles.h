#ifndef FONDO_NIVELES_H
#define FONDO_NIVELES_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QTimer>

class Fondo_niveles: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

    friend class juego ;

public:

    Fondo_niveles( int n_level );       //Constructor para los fondos de cada nivel

    void set_escenario() ;      //Funcion para cargar los frames de cada fondo

    int frame = 0 , num_escenario ;     //Variables utiles para la Animacion del fondo

    QTimer *cambiar_frame ;     //Timer para la animacion de los fondos

public slots:

    void frames() ;     //Slot que se encarga de animar el fondo

private:

    QPixmap escenario_1 , escenario_2 , escenario_3 , escenario_actual ;        //Sprites de los fondos





};

#endif // FONDO_NIVELES_H
