#ifndef PUNTAJE_H
#define PUNTAJE_H

#include <QGraphicsTextItem>
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsItem>

extern unsigned long int puntos ;
extern short int vidas ;

class puntaje: public QGraphicsTextItem
{
public:

   void aumentar_puntaje( int num );

   void whos_playing( QString nombre ) ;

   bool salud( int flag ) ;

};

#endif // PUNTAJE_H
