#include "juego.h"

juego::juego(){


}

void juego::escena_Menu(){

    menu = new QGraphicsScene ;

    menu->setSceneRect(0 , 0 , tam_X , tam_Y );

    menu->setBackgroundBrush(QImage(":/Recursos/Fondo-Menu.jpg").scaled( tam_X ,tam_Y ) );      //Dibujamos el fondo del menu

}

void juego::set_level_one(){


    level_one = new QGraphicsScene ;

    level_one->setSceneRect( 0 , 0 , tam_X , tam_Y );


        //escenario

    backg_screen = new Fondo_niveles( nivel_jugador ) ;

    backg_screen->num_escenario = nivel_jugador ;

    backg_screen->set_escenario() ;

    level_one->addItem( backg_screen ) ;        //Añadimos el elemento que va a hacer el papel de fondo de cada nivel



        //juagdor

    Main_player = new Jugador_1( select_plane ) ;

    Main_player->set_imagen_jugador( select_plane ) ;

    Main_player->setX( 130 ) ;      //130

    Main_player->setY( 240 ) ;

    level_one->addItem( Main_player ) ;     //Añadimos al personaje principal con su respectivo sprite y animacion

        //Timer del GAME OVER

    Revisar_game_over = new QTimer() ;

    connect( Revisar_game_over , SIGNAL( timeout() ) , this , SLOT( Fin_del_Juego() ) ) ;

    Revisar_game_over->start( 10 ) ;


}

void juego::disparar(){

    int px , py ;

    px = Main_player->x() + 50 ;

    py = Main_player->y() + 39 ;

    disparo = new proyectil ;

    disparo->setPos( px , py ) ;

    level_one->addItem( disparo ) ;

}

void juego::Fin_del_Juego(){


    if( Main_player->GAME_OVER ){

        backg_screen->cambiar_frame->stop() ;

        Fin_partida = true ;

        Revisar_game_over->stop() ;  //Qtimer


    }

}


