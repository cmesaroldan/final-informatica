#include "juego.h"

juego::juego()
{

}

void juego::escena_Menu(){
    menu = new QGraphicsScene ;

    menu->setSceneRect(0 , 0 , tam_X , tam_Y );
    menu->setBackgroundBrush(QImage(":/Recursos/Fondo-Menu.jpg").scaled( tam_X ,tam_Y ) );      //Dibujamos el fondo del menu

}

void juego::set_level_one()
{
    level_one = new QGraphicsScene ;

    level_one->setSceneRect( 0 , 0 , tam_X , tam_Y );

    //escenario:


    backg_screen = new Fondo_niveles( nivel_jugador ) ;

    backg_screen->num_escenario = nivel_jugador ;

    backg_screen->set_escenario() ;

    level_one->addItem( backg_screen ) ;



}



int juego::getTam_X() const
{
    return tam_X;
}

int juego::getTam_Y() const
{
    return tam_Y;
}

QGraphicsScene *juego::getMenu() const
{
    return menu;
}
