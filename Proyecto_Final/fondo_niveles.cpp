
#include "fondo_niveles.h"

Fondo_niveles::Fondo_niveles( int n_level ){


    cambiar_frame = new QTimer() ;

    connect( cambiar_frame , SIGNAL( timeout() ) , this , SLOT( frames() ) ) ;

    int milsec = 1 ;

    if( n_level == 1 ){             //Se Cargan las imagenes de cada nivel

       escenario_1.load(":/Recursos/stage1.png") ;

       milsec = 100 ;

    }
    else if( n_level == 2 ){

        escenario_2.load(":/Recursos/newStage2.png") ;

        milsec = 40 ;

    }
    else if( n_level == 3 ){

        escenario_3.load(":/Recursos/stage3.png") ;

        milsec = 20 ;
    }


    cambiar_frame->start( milsec ) ;        //Inicio del conteo del timer para la animacion

}

void Fondo_niveles::set_escenario(){        //Las imagenes quedan listas para ser mostradas en pantalla

    if( num_escenario == 1 ){


        escenario_actual = escenario_1.copy( 800*frame , 0 , 800 , 500 ) ;

    }
    else if( num_escenario == 2 ){


       escenario_actual = escenario_2.copy( 800*frame , 0 , 800 , 500 ) ;

    }
    else{


      escenario_actual = escenario_3.copy( 800*frame , 0 , 800 , 500 ) ;

    }


    setPixmap( escenario_actual.scaled( 800 , 500 ) ) ;
}

void Fondo_niveles::frames(){

    frame++ ;

    if( num_escenario == 3 && frame == 29 ){   //29 frames

        frame = 0 ;
    }
    else if( num_escenario == 2 && frame == 19 ){      //19 frames

        frame = 0 ;

    }else if( num_escenario == 1 && frame == 14 ){     //14 frames

        frame = 0 ;

    }

    set_escenario() ;       //Desplegamos la imagen del personaje

}
