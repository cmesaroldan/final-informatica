#ifndef ENEMIGOS_H
#define ENEMIGOS_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>
#include <QList>
#include <qmath.h>
#include <QSoundEffect>
#include "proyectil.h"
#include "proyectil_en.h"

class enemigos: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:

    enemigos( int n_enemy, int nivel );

    void set_enemigo() ;

    int amplitud,frame = 0 ;

    QTimer *timer_enemy ;

    QTimer *bala_enemy;

public slots:

    void movimiento_enemigos() ;

    void movimiento_bala();

    void muerte() ;

private:

    QPixmap sprites1, enemy ;

    int tX =0 , tY = 0 , n, shoot , T = 30 ;

    unsigned long long t_disc = 1 ,t_disc1 = 1;

    bool collide = true ;



    QList<QGraphicsItem*> colisiones ;

    QSoundEffect *explosion ;

    proyectil_en *bala;

};

#endif // ENEMIGOS_H
