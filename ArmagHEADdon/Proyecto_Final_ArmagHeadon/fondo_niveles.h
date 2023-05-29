#ifndef FONDO_NIVELES_H
#define FONDO_NIVELES_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QTimer>

class Fondo_niveles: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Fondo_niveles();
    Fondo_niveles( int n_level );
    void set_escenario() ;
    int num_escenario ;
    QTimer *cambiar_frame ;

private:

    QPixmap escenario_1, escenario_actual;

};


#endif // FONDO_NIVELES_H
