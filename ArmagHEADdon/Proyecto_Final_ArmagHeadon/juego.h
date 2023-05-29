#ifndef JUEGO_H
#define JUEGO_H
#include <QObject>
#include <QGraphicsScene>

class juego: public QObject
{
public:
    juego();
    void escena_Menu();

    void set_level_one();

    int getTam_X() const;

    int getTam_Y() const;

    QGraphicsScene *getMenu() const;

public slots:

    private:
    int tam_X = 800, tam_Y = 600;    //tamaños del graphics view,

    QGraphicsScene *menu;


};

#endif // JUEGO_H
