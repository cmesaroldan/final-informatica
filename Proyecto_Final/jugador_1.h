#ifndef JUGADOR_1_H
#define JUGADOR_1_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QTimer>
#include <QDebug>
#include <QList>
#include <QSoundEffect>
class Jugador_1: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Jugador_1( int n );     //Constructor del objeto, se le debe pasar el # del personaje del jugador
    void set_imagen_jugador( int n );   //Funcion para setear las diferentes imagenes del personaje
        int frame = 0 , num_av, tam_x_av ;     //Variables utiles para la animacion del personaje
        int vel_0y = 1 , vel_0x = 2 , G = 1 , pos_0x , pos_0y , T = 50  ;

        bool GAME_OVER = false , choque = true ;
        QTimer *animacion, *caida_libre ;     //Timer para la animacion del personaje

        unsigned long long n = 0 ;

    public slots:

        void animacion_sprite() ;       //Slot para la animacion del personaje
        void caida_libre_av() ;
        void movimientos_personaje( int num );
        void tiempo_inmunidad() ;
    private:
        QPixmap sprite_jugador , sprite_actual ;        //Aqui se guardan los sprites del personaje
        QList<QGraphicsItem*> colisiones ;
        QSoundEffect *perder_vida ;
      };

      #endif // JUGADOR_1_H
