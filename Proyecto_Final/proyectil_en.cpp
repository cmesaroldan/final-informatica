#include "proyectil_en.h"

proyectil_en::proyectil_en(){

    bullet.load(":/Recursos/bullet_2.png") ;

    timer_bala = new QTimer() ;

    connect( timer_bala , SIGNAL( timeout() ) , this , SLOT( movimiento_bala() ) ) ;

    timer_bala->start( 20 ) ;


}

void proyectil_en::movimiento_bala(){


setPos( this->x() - 15 , this->y() ) ;

setPixmap( bullet.scaled( 15 , 15 ) ) ;

    if(this->x()<0)
    {
        scene()->removeItem(this);

        delete this;
    }


}
