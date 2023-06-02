#include "enemigos.h"
#include "proyectil.h"
#include "puntaje.h"

extern puntaje *Score ;

enemigos::enemigos( int n_enemy ){

    if( n_enemy == 0 ){

        sprites1.load(":/Recursos/New_enemigo_100.png") ;

        tX = 61 ;

        tY = 50 ;

        n = 0 ;
    }
    else if( n_enemy == 1 ){

        sprites1.load(":/Recursos/new_enemigo_150.png") ;

        tX = 60 ;

        tY = 50 ;

        n = 1 ;
    }
    else if( n_enemy == 2 ){

        sprites1.load(":/Recursos/new_enemigo_200.png") ;

        tX = 62 ;

        tY = 58 ;

        n = 2 ;
    }

    timer_enemy = new QTimer() ;

    connect( timer_enemy , SIGNAL( timeout() ) , this , SLOT( movimiento_enemigos() ) ) ;

    timer_enemy->start( T ) ;

    explosion = new QSoundEffect ;

    explosion->setSource( QUrl("qrc:/Recursos/explosion.wav") ) ;

    explosion->setVolume( 0.20f ) ;

}

void enemigos::set_enemigo(){

    if( n == 0 ){

        enemy = sprites1.copy( tX*frame , 0 , tX , tY ) ;

    }
    else if( n == 1 ){

        enemy = sprites1.copy( tX*frame , 0 , tX , tY ) ;

    }
    else if( n == 2 ){

        enemy = sprites1.copy( tX*frame , 0 , tX , tY ) ;

    }

    setPixmap( enemy.scaled( tX , tY ) ) ;
}



void enemigos::movimiento_enemigos(){

        //colisiones

    colisiones = collidingItems() ;

    for( int i = 0 , nl = colisiones.size() ; i < nl ; i++ ){  //iteramos sobre la lista colisiones


        if( (typeid( *( colisiones[i] )  ) ==  typeid( proyectil )) && collide ){

            Score->aumentar_puntaje( n ) ;

            explosion->play() ;

            scene()->removeItem( colisiones[i] ) ;

            delete colisiones[i] ;

            frame = 1 ;

            set_enemigo() ;

            collide = false ;

            QTimer::singleShot( 800 , this, SLOT( muerte() ) );

            return;

        }


    }

    int px , py ;

    px = this->x() ;

    py = this->y() ;


    if( n == 0 ){

        setPos( px - 5 , py ) ;  //generando mov hacia la izquierda

    }
    else if( n == 1 ){


        setPos( px - 8 , py ) ; //movimiento mas rapido, depende del nivel.

    }
    else if( n == 2 ){


        double pos_y = 5*qSin( 4*t_disc*(0.001*T) ) ;  //mov sinusoidal.

        setPos( px - 5 , py + pos_y ) ;

        t_disc++ ;

    }


    //si el objeto salio de la pantalla lo quitamos.

    int flag = this->x() + 62 ;

    if( flag < 0 ){

        scene()->removeItem( this ) ;

        delete this ;
    }

}


void enemigos::muerte(){

    scene()->removeItem( this ) ;

    delete this ;

    return;
}
