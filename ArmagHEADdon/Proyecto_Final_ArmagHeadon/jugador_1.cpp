#include "jugador_1.h"

jugador_1::jugador_1()
{

}

jugador_1::jugador_1(int n)
{
    //Definimos las dos opciones de cabezas que hay.
    switch (n){
    case 1:{
        sprite_jugador.load(":/recursos/avn_p1.png");

    }
    case 2:{
        sprite_jugador.load(":/recursos/avn_p1.png");

    }break;

    }

    num_plane = n ;     //Asiganamos el valor del sprite de la cabeza

    animacion = new QTimer() ;

    connect( animacion , SIGNAL( timeout() ) , this , SLOT( animacion_sprite() ) ) ;

    animacion->start( 60 ) ;




}

void jugador_1::set_imagen_jugador(int n)
{
    switch( n ){            //Alistamos las imagenes de las cabezas para ser mostradas en pantalla

    case 1:{

        tam_x_plane = 80 ;

        sprite_actual = sprite_jugador.copy( 80*frame , 0 , 80 , 48 ) ;

        setPixmap( sprite_actual.scaled( 80 , 48 ) ) ;

    }break;

    case 2:{

        tam_x_plane = 64 ;

        sprite_actual = sprite_jugador.copy( 64*frame , 0 , 64 , 48 ) ;

        setPixmap( sprite_actual.scaled( 64 , 48 ) ) ;

    }break;

    }

}

void jugador_1::animacion_sprite()
{
    frame++ ;
                     //Se ejecuta la animacion de cada cabeza.
    if( frame == 3 ){

        frame = 0 ;

    }

    set_imagen_jugador( num_plane ) ;

}
