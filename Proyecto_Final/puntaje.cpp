#include "puntaje.h"


void puntaje::aumentar_puntaje( int num ){

    //Aumentamos el puntaje dependiendo del enemigo que se elimino

    if( num == 0 ){

        puntos = puntos + 100 ;
    }
    else if( num == 1 ){

        puntos = puntos + 150 ;
    }
    else if( num == 2 ){

        puntos = puntos + 200 ;
    }



    setPlainText( QString( "Puntaje: " ) + QString::number( puntos ) ) ;

    setDefaultTextColor( Qt::white ) ;

    setFont( QFont("Fixedsys" , 20) ) ;

    setPos( 0 , 15 ) ;

}

void puntaje::whos_playing(QString nombre){

    setPlainText( nombre ) ;

    setDefaultTextColor( Qt::white ) ;

    setFont( QFont("Fixedsys" , 28) ) ;

}

bool puntaje::salud( int flag ){


    if( flag == 0 ){        //restamos la vida

        vidas-- ;

    }

    setPlainText( QString( "Vidas: " ) + QString::number( vidas ) ) ;

    setDefaultTextColor( Qt::white ) ;

    setFont( QFont("Fixedsys" , 20) ) ;

    setPos( 0 , 30 ) ;

    if( vidas == 0 ){

        return true;
    }
    else{

        return  false;
    }

}
