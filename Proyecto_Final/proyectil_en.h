#ifndef PROYECTIL_EN_H
#define PROYECTIL_EN_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>

class proyectil_en: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

    friend class juego ;

public:

    proyectil_en();


public slots:

    void movimiento_bala() ;

private:

    QPixmap bullet ;

    QTimer *timer_bala ;

};
#endif // PROYECTIL_EN_H
