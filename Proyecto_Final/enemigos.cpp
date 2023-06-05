#include "enemigos.h"
#include "proyectil.h"
#include "puntaje.h"
#include "proyectil_en.h"

extern puntaje *puntuacion ;

enemigos::enemigos( int n_enemy, int nivel ){

    shoot=rand()%2;

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

        amplitud=rand()%3;

        n = 1 ;
    }
    else if( n_enemy == 2 ){


        sprites1.load(":/Recursos/new_enemigo_200.png") ;

        tX = 62 ;


        tY = 58 ;

        amplitud=rand()%3;

        n = 2 ;

    }

    if(n!=0 && shoot==1) // Solo disparan los enemigos 1 y 2, los enemigos 0, no lo hacen

    {
        bala_enemy= new QTimer;

        connect( bala_enemy , SIGNAL( timeout() ) , this , SLOT( movimiento_bala() ) ) ;

        bala_enemy->start( 1500-(300*nivel) ) ;  // Depende del nivel del enemigo, para sus balas y velocidades
    }

    timer_enemy = new QTimer() ;

    connect( timer_enemy , SIGNAL( timeout() ) , this , SLOT( movimiento_enemigos() ) ) ;

    timer_enemy->start( T ) ; //Tiempo entre enemigos

    explosion = new QSoundEffect ;

    explosion->setSource( QUrl("qrc:/Recursos/explosion.wav") ) ;

    explosion->setVolume( 0.20f ) ;

}

void enemigos::set_enemigo(){  //

    if( n == 0 ){

        enemy = sprites1.copy( tX*frame , 0 , tX , tY ) ; //Dimensiones a copiar

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

    //Se procede a crear una lista de punteros
    colisiones = collidingItems() ; // verifica si hay colisiones en el escenario con algun enemigo

    for( int i = 0 , nl = colisiones.size() ; i < nl ; i++ ){

        //typeid operador que verifica conlisiones con otras instancias
        if( (typeid( *( colisiones[i] )  ) ==  typeid( proyectil )) && collide ){

            puntuacion->aumentar_puntaje( n ) ;

            explosion->play() ;

            scene()->removeItem( colisiones[i] ) ; //removeItem, para remover del escenario

            delete colisiones[i] ; //libera espacio en memoria

            if(n!=0 && shoot==1){ //Si el enemigo es de clase 1 o 2 y además dispara

            bala_enemy->stop();
            delete bala_enemy;

            }

            frame = 1 ;

            set_enemigo() ;

            collide = false ; //Regresa a ser falso

            QTimer::singleShot( 800 , this, SLOT( muerte() ) ); //800 sera el tiempo que siga en pie el enemigo, explotando

            return;

        }


    }

    int px , py ; //Toma las actuales posciones del enemigo

    px = this->x() ;

    py = this->y() ;



    if( n == 0 ){

        setPos( px , py+5 ) ;

    }

    //Movimientos definidos apartir de números aleatorios previos

    else if( n == 2 || n == 1){

        double pos_x=0;
        double pos_y=0;

        if (amplitud==0){

            pos_x = 5*qCos(4*t_disc*(0.001*T));

            pos_y = 5*qSin( 4*t_disc*(0.001*T) ) ;


            if(t_disc==43)
            {
                t_disc=0;
            }
        }
        else if(amplitud==1)
        {
            pos_x = 8*qCos(4*t_disc*(0.001*T));

            pos_y = 8*qSin( 4*t_disc*(0.001*T) ) ;
            if(t_disc==45)
            {
                t_disc=0;
            }

        }
        else if(amplitud==2)
        {
            pos_x = 10*qCos(4*t_disc*(0.001*T));

            pos_y = 10*qSin( 4*t_disc*(0.001*T) ) ;

            if(t_disc==45)
            {
                t_disc=0;
            }
        }

        t_disc++;

        setPos( px - 3 - pos_x , py + pos_y ) ;

    }



    int flag = this->x() + 62 ;

    if( flag < 0 ){

        scene()->removeItem( this ) ;

        delete this ;
    }

    int flag2= this->y();

    if(flag2>500){

        scene()->removeItem(this);

        delete this;
    }

}

void enemigos::movimiento_bala()
{
    int px , py ;

    px = this->x() + 50 ;

    py = this->y() + 39 ;

    bala = new proyectil_en ;

    bala->setPos( px , py ) ;

    scene()->addItem( bala ) ;
}

void enemigos::muerte(){

    scene()->removeItem( this ) ;

    delete this ;

    return;
}
