#include "proyectil.h"
#include "enemigos.h"

proyectil::proyectil(){

    bullet.load(":/Recursos/bullet.png") ;

    timer_bala = new QTimer() ;

    connect( timer_bala , SIGNAL( timeout() ) , this , SLOT( movimiento_bala() ) ) ;

    timer_bala->start( 20 ) ;


}

void proyectil::movimiento_bala(){


    setPos( this->x() + 15 , this->y() ) ;

    setPixmap( bullet.scaled( 15 , 15 ) ) ;

   /* if(identificador==0){

    setPos( this->x() + 15 , this->y() ) ;

    setPixmap( bullet.scaled( 15 , 15 ) ) ;
}
    else if(identificador==1){

        setPos( this->x() - 15 , this->y() ) ;

        setPixmap( bullet.scaled( 15 , 15 ) ) ;
    }*/

    if( this->x() > 800 ){

        scene()->removeItem( this ) ;

        delete this ;

    }

   /* if(this->x()<0)
    {
        scene()->removeItem(this);

        delete this;
    }*/


}
