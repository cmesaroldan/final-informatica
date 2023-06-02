#ifndef PROYECTIL_H
#define PROYECTIL_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>

class proyectil: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

    friend class juego ;

public:

    proyectil();


public slots:

    void movimiento_bala() ;

private:

    QPixmap bullet ;

    QTimer *timer_bala ;


};

#endif // PROYECTIL_H
