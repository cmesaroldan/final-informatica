#include "fondo_niveles.h"

Fondo_niveles::Fondo_niveles()
{

}

Fondo_niveles::Fondo_niveles(int n_level)
{
    cambiar_frame = new QTimer() ;

    connect( cambiar_frame , SIGNAL( timeout() ) , this , SLOT( frames() ) ) ;

    int milsec = 1 ;

    if( n_level == 1 ){             //Se Cargan las imagenes de cada nivel

        escenario_1.load(":/Recursos/stage1.png") ;

        milsec = 100 ;

    }

    cambiar_frame->start( milsec ) ;

}

void Fondo_niveles::set_escenario()
{

}


