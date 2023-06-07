#include "jugador_1.h"
#include "enemigos.h"
#include "puntaje.h"
extern puntaje *health ;


Jugador_1::Jugador_1( int n ){


    switch( n ){
     case 1:{ sprite_jugador.load(":/Recursos/avn_p1.png") ;

    }break;
    case 2:{

                sprite_jugador.load(":/Recursos/avn_2.png") ;

            }break;

        }

        cara_1 = n ;     //Asiganamos el valor del sprite del personaje

        animacion = new QTimer() ;

        connect( animacion , SIGNAL( timeout() ) , this , SLOT( animacion_sprite() ) ) ;

        animacion->start( 60 ) ;    //iniciamos el timer para la animacion del personaje

        caida_libre = new QTimer() ;

        connect( caida_libre , SIGNAL( timeout() ) , this , SLOT( caida_libre_av() ) ) ;

        caida_libre->start( T ) ;
        perder_vida = new QSoundEffect ;

        perder_vida->setSource( QUrl("qrc:/Recursos/Lose.wav") ) ;

    }

    void Jugador_1::set_imagen_jugador( int n ){switch( n ){            //Alistamos las imagenes del personaje para ser mostradas en pantalla

        case 1:
        {   tam_x_av = 80 ;
            sprite_actual = sprite_jugador.copy( 80*frame , 0 , 80 , 48 ) ;
            setPixmap( sprite_actual.scaled( 80 , 48 ) ) ;
        }
            break;

        case 2:
        {   tam_x_av = 64 ;
            sprite_actual = sprite_jugador.copy( 64*frame , 0 , 64 , 48 ) ;

            setPixmap( sprite_actual.scaled( 64 , 48 ) ) ;

        }break;
    }

}
    void Jugador_1::animacion_sprite(){

        frame++ ;
                                //Se ejecuta la animacion de cada personaje
        if( frame == 3 ){

            frame = 0 ;

        }

        set_imagen_jugador( cara_1 ) ;

    }

    void Jugador_1::caida_libre_av(){
        //Se revisan las colisones

            colisiones = collidingItems() ;

            for( int i = 0 , nl = colisiones.size() ; i < nl ; i++ ){


                if( ((typeid( *( colisiones[i] )  ) ==  typeid( enemigos )) && choque)||((typeid( *( colisiones[i] )  ) ==  typeid( proyectil_en )) && choque)){


                    choque = false ;

                    GAME_OVER = health->salud( 0 ) ;

                    if(!GAME_OVER) perder_vida->play() ;

                    if( GAME_OVER ){

                        caida_libre->stop() ;

                        animacion->stop() ;
                    }
                    else{

                        QTimer::singleShot( 2500 , this, SLOT( tiempo_inmunidad() ) );
                    }

                }


            }

                //Movimiento caida libre

        float x , y ;

        pos_0x = this->x() ;

        pos_0y = this->y() ;

        x = pos_0x - vel_0x*n*( 0.001*T ) ;

        y =  pos_0y + vel_0y*n*( 0.001*T ) - 0.5*G*n*( 0.001*T )*( 0.001*T ) ;

        this->setPos( int( x ) , int( y ) ) ;

        n++ ;

        int condicion_GAME_OVER1  = this->x() + 40 ;

        int condicion_GAME_OVER2  = this->y() ;


        if( condicion_GAME_OVER1 < 0 || condicion_GAME_OVER2 > 468 ){

            qDebug() << "GAME OVER" ;

            caida_libre->stop() ;

            animacion->stop() ;

            GAME_OVER = true ;
            vidas = 0 ;
            health->salud( 1 );

        }


    }
    void Jugador_1::movimientos_personaje( int num ){

        pos_0x = this->x() ;

        pos_0y = this->y() ;

        bool cond1 = pos_0y - 5 > 0 ;

        bool cond2 = (pos_0x + tam_x_av ) + 5 < 800 ;

        if( cond1 && cond2 ){       //Condiciones para los boredes derecho y superior de la pantalla


                if( num == 0 ){       //arriba


                  this->setPos( pos_0x , pos_0y - 5 ) ;

                }
                else if( num == 1 ){      //abajo

                     this->setPos( pos_0x , pos_0y + 5 ) ;
                }
                else if( num == 2 ){      //izquierda

                     this->setPos( pos_0x - 5 , pos_0y ) ;
                }
                else if( num == 3 ){          //derecha

                     this->setPos( pos_0x + 5 , pos_0y ) ;
                }
                else if( num == 4 ){        //diagonal derecha - arriba

                    this->setPos( pos_0x + 5 , pos_0y - 5 ) ;
                }
                else if( num == 5 ){        //diagonal abajo - izq

                    this->setPos( pos_0x - 5 , pos_0y + 5 ) ;
                }

                n = 0 ;

        }


    }
    void Jugador_1::tiempo_inmunidad(){
    choque = true ;
    }
