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

class enemigos: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:

    enemigos( int n_enemy );

    void set_enemigo() ;

    int frame = 0 ;

    QTimer *timer_enemy ;

public slots:

    void movimiento_enemigos() ;

    void muerte() ;

private:

    QPixmap sprites1, enemy ;

    int tX , tY , n , T = 30 ;

    unsigned long long t_disc = 0 ;

    bool collide = true ;



    QList<QGraphicsItem*> colisiones ;

    QSoundEffect *explosion ;


};

#endif // ENEMIGOS_H
