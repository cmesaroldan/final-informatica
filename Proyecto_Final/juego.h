//Proximamente
#ifndef JUEGO_H
#define JUEGO_H
#include <QObject>
#include <QGraphicsScene>
#include "jugador_1.h"
#include "fondo_niveles.h"
#include "proyectil.h"
#include "enemigos.h"
class juego: public QObject
{
    Q_OBJECT
    friend class MainWindow ;
public:

    juego();
     void escena_Menu();     //Funcion para configurar la escena del menu
     void set_level_one() ;  //Funcion para configurar la escena del primer nivel
     void disparar() ;
public slots:

        void Fin_del_Juego() ;

    private:
    int tam_X = 800 , tam_Y = 500, pixelX = 64 , pixel_Y = 48 ; //Tamaños a usar dentro del juego
    int btx = 120 , bty = 30 ;  //Mas tamaños

    QGraphicsScene *menu, *nivel_uno ;      //Escenas del menu y el nivel 1

    int val_btn_presionado, nivel_jugador = 1, int_flag = 0 , select_av, tiempo_enemigos = 4000 , puntos_1player = 0 , puntos_2player = 0 ;//Variables importantes para la configuracion del juego

    QString nombre_jugador ;        //Qstring que contendrá el nombre del jugador

    bool condicion_aceptar = true , encontrado = false , existente_name = true , Fin_partida = false , tecleable = false , dis_paro = true, epic_fail = false , flag_multip = true ;    //Variables utiles para el manejo del menu

    Jugador_1 *jugador ;    //Puntero para el objeto jugador

      Fondo_niveles *fondo_juego ;   //Puntero para los diferentes escenarios de los 3 niveles
      QTimer *Revisar_game_over ;
      proyectil *disparo ;
  };

  #endif // JUEGO_H
