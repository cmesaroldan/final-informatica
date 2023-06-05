#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QIcon>
#include "juego.h"
#include "jugador_1.h"
#include "fondo_niveles.h"
#include <QDebug>
#include <QMediaPlayer>
#include <QSoundEffect>
#include <QMessageBox>
#include <QFile>
#include <time.h>
#include <QKeyEvent>
#include "enemigos.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:

    MainWindow(QWidget *parent = nullptr);

 void setMenu();     //Metodo para mostrar el menu
 void Guardar_nuevo_jugador() ; //Funcion que guarda el nuevo jugador ingresado
 void Cargar_partida_1jugador() ;        //Funcion que lee el archivo de guardado
 void nivel_1() ;        //Configuracion para el nivel 1 del juego
 void keyPressEvent( QKeyEvent *teclas);
 void Guardar_progerso() ;
 void borrar_cambio_escena() ;
 void multi_jugador() ;

   ~MainWindow();
private slots:
 //Slots de los botones de la interfaz
void on_Jugar_clicked();

void on_regresar_clicked();
void on_Salir_clicked();
void on_nueva_partida_clicked();
void on_cargar_partida_clicked();

void set_interfaz_1() ;
void on_aceptar_clicked();
void perdiste() ;
void barra_press() ;
void spawn_enemigo() ;
void on_instrucciones_clicked();
void update_nivel();
void change_player_multiP() ;
void perdiste_multiplayer() ;
void final_multiP() ;

private:

Ui::MainWindow *ui;
juego *GAME ;   //Puntero al Juego principal
QMediaPlayer *music , *msc_2, *ending_theme, *lvl_cambio ;  //Punteros que almacenaran la musica del menu y cuando se esté jugando
QSoundEffect *efecto_boton_click, *gameO_efecto, *sonido_disparo , *cambio_p_effect ;      //Puntero para lo efectos de sonido de click del menu
QMessageBox * msg_box ;     //Puntero para crear los message box necesarios
QTimer *end_game , *timer_spawn_enemy ;
enemigos *ENEmigos ;
};
#endif // MAINWINDOW_H
