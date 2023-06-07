#include "juego.h"
juego::juego(){
}
void juego::escena_Menu(){
    menu = new QGraphicsScene ;

    menu->setSceneRect(0 , 0 , tam_X , tam_Y );

    menu->setBackgroundBrush(QImage(":/Recursos/Fondo-Menu.jpg").scaled( tam_X ,tam_Y ) );      //Dibujamos el fondo del menu

   }

   void juego::set_level_one(){


       nivel_uno = new QGraphicsScene ;

       nivel_uno->setSceneRect( 0 , 0 , tam_X , tam_Y );



        //escenario

       fondo_juego = new Fondo_niveles( nivel_jugador ) ;

       fondo_juego->num_escenario = nivel_jugador ;

       fondo_juego->set_escenario() ;

       nivel_uno->addItem( fondo_juego ) ;        //Añadimos el elemento que va a hacer el papel de fondo de cada nivel



        //juagdor

       jugador = new Jugador_1( select_av ) ;

       jugador->set_imagen_jugador( select_av ) ;

       jugador->setX( 130 ) ;

       jugador->setY( 240 ) ;

       nivel_uno->addItem( jugador ) ;     //Añadimos al personaje principal con su respectivo sprite y animacion
       //Timer del GAME OVER

          Revisar_game_over = new QTimer() ;

          connect( Revisar_game_over , SIGNAL( timeout() ) , this , SLOT( Fin_del_Juego() ) ) ;

          Revisar_game_over->start( 10 ) ; //Frecuencia en la que se revisa si acabo o no

      }
       void juego::disparar(){

       int px , py ;

       px = jugador->x() + 50 ; //Punto exacto del jugador

       py = jugador->y() + 39 ;

       disparo = new proyectil;

       disparo->setPos( px , py ) ;

       nivel_uno->addItem( disparo ) ;
      }


       void juego::Fin_del_Juego(){


          if( jugador->GAME_OVER ){

              fondo_juego->cambiar_frame->stop() ;



              Fin_partida = true ;

              Revisar_game_over->stop() ;

   }
      }
