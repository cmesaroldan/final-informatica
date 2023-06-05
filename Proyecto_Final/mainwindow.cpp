#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "puntaje.h"

extern puntaje *puntuacion ;
extern puntaje *nombre_jugador ;
extern puntaje *health ;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

setWindowIcon( QIcon( ":/Recursos/logo.png" ) ) ;        //Icono de la ventana
 GAME = new juego ;      //Creamos un objeto tipo juego
 setMenu();      //Ejecutamos la funcion que configura el menu

  srand(time(NULL)) ;     //Para poder generar un num aleatorio
}

void MainWindow::setMenu(){     //Funcion en la cual se inicializa y muestra el menu del juego
      //Configuracion de la escena
  GAME->escena_Menu();
  setGeometry( 0, 0 , GAME->tam_X + 2 , GAME->tam_Y + 2) ;
  setMaximumSize(GAME->tam_X + 2 , GAME->tam_Y + 2 ) ;
  setMinimumSize(GAME->tam_X + 2 , GAME->tam_Y + 2 ) ;

  ui->graphicsView->setGeometry( 0, 0 , GAME->tam_X + 2 , GAME->tam_Y + 2 ) ;
  ui->graphicsView->setScene( GAME->menu );       //Añadimos la escena menu a la pantalla

  //Configuracion de los botones principales
     ui->Jugar->setGeometry( (GAME->tam_X/2)-(GAME->btx/2) , (GAME->tam_Y/2)-(GAME->bty/2) , GAME->btx , GAME->bty );

     ui->Salir->setGeometry( (GAME->tam_X/2)-(GAME->btx/2) , ((GAME->tam_Y + 6*(GAME->bty))/2)-(GAME->bty/2) , GAME->btx , GAME->bty );
     ui->nueva_partida->setGeometry( (GAME->tam_X/2)-(GAME->btx/2) , (GAME->tam_Y/2)-(GAME->bty/2) , GAME->btx , GAME->bty );

     ui->cargar_partida->setGeometry( (GAME->tam_X/2)-(GAME->btx/2) , ((GAME->tam_Y + 3*(GAME->bty))/2)-(GAME->bty/2) , GAME->btx , GAME->bty ) ;

     //Boton Regresar
     ui->regresar->setGeometry( 20 , (GAME->tam_Y) - 70 , 50 , 50 ) ;
     ui->regresar->hide() ;
     //Boton instrucciones

       ui->instrucciones->setGeometry( 20 , (GAME->tam_Y) - 70 , 50 , 50 ) ;
      //Texto Instrucciones

         ui->texto_instrucciones->setGeometry( 190 , 190 , 400 , 250 ) ;

         ui->texto_instrucciones->hide() ;

     //Botonos cargar y nueva partida

ui->nueva_partida->hide() ;

ui->cargar_partida->hide() ;

 //Linea para Ingresar el nombre

ui->agregar_nombre->setGeometry( (GAME->tam_X/2)-(GAME->btx/2) , ((GAME->tam_Y + 6*(GAME->bty))/2)-(GAME->bty/2) , GAME->btx , GAME->bty );

ui->agregar_nombre->hide() ;

 //Boton aceptar

ui->aceptar->setGeometry( (GAME->tam_X/2)-(GAME->btx/2) , ((GAME->tam_Y + 9*(GAME->bty))/2)-(GAME->bty/2) , GAME->btx , GAME->bty );

ui->aceptar->hide() ;





 //texto pregunta, nueva partida, cargar partida

ui->texto1->setGeometry( 300 , 250 , 200 , 50 );
ui->texto1->hide() ;
ui->new_partida_txt->setGeometry( 283 , 200 , 230 , 50 ) ;
ui->new_partida_txt->hide() ;
ui->load_partida_txt->setGeometry( 283 , 200 , 230 , 50 ) ;

ui->load_partida_txt->hide() ;


//Texto GAME OVER

    ui->Game_final->setGeometry( 135 , 100 , 500 , 150 ) ;

    ui->Game_final->hide() ;

 //Texto Mission Completed

     ui->completado->setGeometry( 135 , 100 , 500 , 150 ) ;

     ui->completado->hide();










 //Configuracion de la musica de menu

    music = new QMediaPlayer() ;

    //music->setMedia( QUrl("qrc:/Recursos/Fondo-Menu.mp3") ) ;

    ui->regresar->setGeometry( 20 , (GAME->tam_Y) - 70 , 50 , 50 ) ;

    ui->regresar->hide() ;

    //music->setVolume(30) ;      //Definimos el nivel del volumen de la musica

    music->play() ;

    //Configuracion Musica del final del juego

     ending_theme = new QMediaPlayer() ;

     //ending_theme->setMedia( QUrl("qrc:/Recursos/mission-complete.mp3") ) ;

     //ending_theme->setVolume( 30 ) ;


           //Configuracion efecto cambio de nivel

     lvl_cambio = new QMediaPlayer() ;

     //lvl_cambio->setMedia( QUrl("qrc:/Recursos/powerup.mp3") ) ;


  //Configuracion de la musica del juego

  msc_2 = new QMediaPlayer() ;
  //msc_2->setMedia( QUrl("qrc:/Recursos/Fondo-Juego.mp3") ) ;
  //msc_2->setVolume( 10 ) ;

  //Configuracion sonido de los botones del menu

      efecto_boton_click = new QSoundEffect ;

      efecto_boton_click->setSource( QUrl("qrc:/Recursos/hit-01.wav") );
      efecto_boton_click->setVolume( 0.20f ) ;    //Definimos el nivel del volumen del efecto de sonido

      gameO_efecto = new QSoundEffect ;
      gameO_efecto->setSource( QUrl("qrc:/Recursos/8-bit-game-over.wav") );
      gameO_efecto->setVolume( 0.40f ) ;


       //Configuracion del sonido de disparo

       sonido_disparo = new QSoundEffect ;
       sonido_disparo->setSource( QUrl("qrc:/Recursos/gun-shot.wav") ) ;
       sonido_disparo->setVolume( 0.60f ) ;

             //configuracion botones seleccion de personaje

         ui->buttonGroup->setId( ui->avn1 , 1 ) ;        //Definimos un ID para identificar los botones de seleccion del personaje
         ui->buttonGroup->setId( ui->avn2 , 2 ) ;

         ui->avn1->hide() ;//cambiar
         ui->avn2->hide() ;

         ui->avn1->setGeometry( 470 , 322 , 80 , 20 ) ;
         ui->avn2->setGeometry( 470 , 338 , 80 , 20 ) ;


     }

void MainWindow::Guardar_nuevo_jugador(){

        //Condiciones para elegir el personaje
    if( ui->buttonGroup->button( 1 )->isChecked() ){        //Se revisa qué personaje se elegió

           GAME->select_av = 1 ;

        }else if( ui->buttonGroup->button( 2 )->isChecked() ){

           GAME->select_av = 2 ;
        }
        else{

           GAME->select_av = 1 ;     //Por defecto, pone el 1er personaje
        }



        GAME->nombre_jugador = ui->agregar_nombre->text() ;     //Obtenemos el texto Ingresado por el usuario

        if( GAME->nombre_jugador == "" ){

         int random_num = rand()%100000 ;      //Si NO se ingreso un nombre, se pone Random# y un numero aleatorio

           GAME->nombre_jugador = "Random#" + QString::number( random_num , 10 ) ;

        }

        QFile archivo( "guardado.txt" ) ;

        archivo.open( QFile::Append | QFile::Text) ;        //Se abre o Crea el archivo donde se almacenará la informacion del jugador

           QTextStream out( &archivo );
           QFile arch_2( "guardado.txt" ) ;        //Tambien se abre el msimo archivo y se revisa que el nombre ingresado no exista

               GAME->existente_name = true ;

               if( arch_2.open( QFile::ReadOnly | QFile::Text ) ){
                   QTextStream leer_name( &arch_2 ) ;
                   while( !leer_name.atEnd() ){
                       QString linea = leer_name.readLine();
                       QString comparacion ;
                       comparacion = linea.section(" " , 0 , 0 ) ;
                   }//fin while
                         arch_2.close() ;
                     }//fin if arch2
        if( GAME->existente_name ){     //Si el nombre no existe anteriormente, es creado y guardado
            out << GAME->nombre_jugador.replace( " ", "_" ) << " Avn:" << GAME->select_av << " N:" << GAME->nivel_jugador << " P:" << puntos << ";" ;

                   out << "\n" ;

               }
        else{
                msg_box = new QMessageBox ;
                msg_box->setWindowIcon( QIcon( ":/Recursos/logo.png" ) ) ;

                msg_box->setWindowTitle("ERROR") ;

                msg_box->setText( "El Nombre (" + GAME->nombre_jugador.replace("_"," ") + ") Ya Existe..." ) ;

                msg_box->exec() ;
                delete msg_box ;
                   }
                   archivo.close() ;
               }
               void MainWindow::Cargar_partida_1jugador(){
                   GAME->nombre_jugador = ui->agregar_nombre->text() ;

                   QFile archivo_leer( "guardado.txt" ) ;
                   if( archivo_leer.open( QFile::ReadOnly | QFile::Text ) ){       //Se abre el archivo en busca de la coincidencia con el nombre ingresado

                          QTextStream in( &archivo_leer ) ;

                          while( !in.atEnd() ){
                              QString linea = in.readLine();
                              QString comparacion ;
                              comparacion = linea.section(" " , 0 , 0 ) ;
                              if( comparacion == GAME->nombre_jugador.replace( " ", "_" ) ){
                                  GAME->encontrado = true ;
                                  //sacamos los datos restantes (personaje seleccionado , nivel y puntos)

                                comparacion = linea.section(" " , 1 , 1 ) ;

                                comparacion = comparacion.section(":",1,1) ;

                                GAME->select_av = comparacion.toInt() ;

                                comparacion = linea.section(" " , 2 , 2 ) ;

                                comparacion = comparacion.section(":" , 1  ,1 ) ;

                                GAME->nivel_jugador = comparacion.toInt() ;
                                if( GAME->nivel_jugador == 1 ){

                                GAME->tiempo_enemigos = 4000 ;

                                }
                                else if( GAME->nivel_jugador == 2 ){

                                GAME->tiempo_enemigos = 2500 ;

                                }
                                else{

                                GAME->tiempo_enemigos = 1000 ;

                                }


                                comparacion = linea.section(" " , 3 , 3 ) ;

                                comparacion = comparacion.section(":" , 1 , 1 ).replace( ";" , "" ) ;

                                 puntos = comparacion.toInt() ;

                                 vidas = 1 ;     //Se le asigna solamente 1 vida al cargar
                              }
                          }
                          archivo_leer.close() ;
                      }
                      else{
                          //msgBox diciendo que no hay archivo de partidas
                          msg_box = new QMessageBox ;
                          msg_box->setWindowIcon( QIcon( ":/Recursos/logo.png" ) ) ;
                          msg_box->setWindowTitle("ERROR") ;
                          msg_box->setText( "NO SE ENCONTRO ARCHIVO DE PARTIDAS GUARDADAS" ) ;
                          msg_box->exec() ;
                          delete msg_box ;
                      }
                  }
               MainWindow::~MainWindow()       //Se eliminan lo punteros de la memoria al cerrar el programa
               {
                   delete ui;

                   delete  GAME ;

                   delete  music ;

                   delete efecto_boton_click ;

                   delete  msc_2 ;

                   delete msg_box ;

                   delete ending_theme ;

                   delete lvl_cambio ;

                   delete end_game ;

                   delete timer_spawn_enemy ;

                   delete ENEmigos ;

                   }

               void MainWindow::on_Jugar_clicked(){        //Al presionar el boton de 1 jugador

                   efecto_boton_click->play() ;

                   ui->Jugar->hide() ;
                   //ui->Multijugador->hide() ;
                   ui->Salir->hide() ;
                   ui->regresar->show() ;
                   ui->nueva_partida->show() ;
                   ui->cargar_partida->show() ;
                   GAME->val_btn_presionado = 0 ;      //Se asigana 0 a la variable
                   ui->instrucciones->hide() ;

                   }
               void MainWindow::on_regresar_clicked(){     //Al presionar el boton de regresar



                   efecto_boton_click->play() ;

                   ui->Jugar->show() ;

                   ui->Salir->show() ;
                   ui->regresar->hide() ;
                   ui->nueva_partida->hide() ;
                   ui->cargar_partida->hide() ;
                   ui->agregar_nombre->hide() ;
                   ui->aceptar->hide() ;
                   ui->texto1->hide() ;
                   ui->new_partida_txt->hide() ;

                   ui->load_partida_txt->hide() ;

                   ui->avn1->hide() ;

                   ui->avn2->hide() ;

                   ui->texto_instrucciones->hide() ;

                   ui->instrucciones->show() ;

                   ui->rush_multip->hide() ;



               }
               void MainWindow::on_Salir_clicked(){        //Al presionar el boton de salir


                   efecto_boton_click->play() ;

                   msg_box = new QMessageBox ;


                       //Configuracion basica del recuadro de salida


                   msg_box->setWindowIcon( QIcon( ":/Recursos/logo.png" ) ) ;

                   msg_box->setWindowTitle("ArmagHEADon") ;
                   msg_box->setText( "Seguro que deseas Salir?" ) ;
                   msg_box->setStandardButtons( QMessageBox::Ok | QMessageBox::Cancel );
                   msg_box->setDefaultButton(QMessageBox::Cancel);
                   int opcion = msg_box->exec() ;
                   switch( opcion ){
                       case QMessageBox::Ok:
                           QApplication::quit() ;      //Comando para cerrar el juego
                       break;
                       case QMessageBox::Cancel:
                           delete msg_box ;
                       break;
                   }

               }


               void MainWindow::on_nueva_partida_clicked(){        //Al presionar el boton de nueva partida

                   efecto_boton_click->play() ;

                   ui->nueva_partida->hide() ;



                   ui->cargar_partida->hide() ;
                   switch ( GAME->val_btn_presionado ){        //Se revisa qué valor tiene la variable

                          case 0:{        //1 jugador

                              ui->agregar_nombre->show() ;
                              ui->aceptar->show() ;
                              ui->texto1->show() ;

                              ui->new_partida_txt->show() ;

                              ui->avn1->show() ;

                              ui->avn2->show() ;

                              GAME->condicion_aceptar = true ;

                          }break;
                          case 1:{        //multijugador

                            ui->rush_multip->hide() ;

                            set_interfaz_1() ;

                             delete  GAME->menu ;

                             multi_jugador() ;

                          }break;
                      }

                  }
               void MainWindow::on_cargar_partida_clicked(){       //Al presionar el boton de cargar partida

                   efecto_boton_click->play() ;

                   ui->cargar_partida->hide() ;
                   ui->nueva_partida->hide() ;
                   switch ( GAME->val_btn_presionado ){
                       case 0:{        //1 jugador
                           ui->load_partida_txt->show() ;
                           ui->texto1->show() ;
                           ui->aceptar->show() ;
                           ui->agregar_nombre->show() ;
                           GAME->condicion_aceptar = false ;
                       }break;
                   }

               }
               void MainWindow::set_interfaz_1(){      //Funcion que se ejecuta cuando el jueva va a comenzar (Esconde botones y demas)

                   ui->agregar_nombre->hide() ;

                   ui->aceptar->hide() ;

                   ui->texto1->hide() ;

                   ui->regresar->hide() ;

                   music->stop() ;

                   msc_2->play() ;

                   ui->graphicsView->setBackgroundBrush( Qt::black ) ;
                   ui->new_partida_txt->hide() ;

                   ui->load_partida_txt->hide() ;
                       ui->avn1->hide() ;

                      ui->avn2->hide() ;

                  }
               void MainWindow::on_aceptar_clicked(){      //Al presionar el boton de aceptar


                   efecto_boton_click->play() ;


                   if( GAME->condicion_aceptar ){


                     Guardar_nuevo_jugador() ;
                       if( GAME->existente_name ){     //Si se cumplen las condicones, el juego comienza en el nivel 1

                            set_interfaz_1() ;

                            delete  GAME->menu ;

                            nivel_1() ;
                               }
                           }
                           else{

                     Cargar_partida_1jugador() ;
                        if( GAME->encontrado ){     //Si se cumplen las condiciones, se cargará la partida correspondiente

                           set_interfaz_1() ;

                           delete  GAME->menu ;

                           nivel_1() ;
                                               }
                         else{
                          msg_box = new QMessageBox ;
                          msg_box->setWindowIcon( QIcon( ":/Recursos/logo.png" ) ) ;

                          msg_box->setWindowTitle("NO ENCONTRADO") ;

                          msg_box->setText( "El Nombre Ingresado (" + GAME->nombre_jugador.replace("_"," ") + ") NO Existe..."  ) ;

                          msg_box->exec() ;

                          delete msg_box ;
                                    }
                            }
                        }
               void MainWindow::perdiste(){

                   if( GAME->Fin_partida ){

                       msc_2->stop() ;

                       gameO_efecto->play() ;

                       ui->Game_final->show() ;

                       ui->Salir->show() ;

                       GAME->tecleable = false ;

                       end_game->stop() ;

                       timer_spawn_enemy->stop() ;

                       Guardar_progerso() ;

                       GAME->epic_fail = true ;

                   }

               }
               void MainWindow::nivel_1(){     //Funcion para el nivel 1
                 GAME->set_level_one() ;
                 ui->graphicsView->setScene( GAME->level_one );

                 end_game = new QTimer() ;

                 connect( end_game , SIGNAL( timeout() ) , this , SLOT( perdiste() ) ) ;

                 end_game->start( 10 ) ;

                 GAME->tecleable = true ;

                 timer_spawn_enemy = new QTimer() ;

                 connect( timer_spawn_enemy , SIGNAL( timeout() ) , this , SLOT( spawn_enemigo() ) ) ;

                 timer_spawn_enemy->start( GAME->tiempo_enemigos ) ;

                     puntuacion = new puntaje() ;

                     nombre_jugador = new puntaje() ;

                     health = new puntaje() ;

                     health->salud( 1 ) ;

                     puntuacion->aumentar_puntaje( 3 ) ;

                     nombre_jugador->whos_playing( GAME->nombre_jugador ) ;

                     GAME->level_one->addItem( puntuacion ) ;

                     GAME->level_one->addItem( nombre_jugador ) ;

                     GAME->level_one->addItem( health ) ;

                     QTimer::singleShot( 60000 , this, SLOT( update_nivel() ) );     //cada nivel dura 1 minuto


                }
               //Funcion para recibir las teclas presionadas



               void MainWindow::keyPressEvent( QKeyEvent *teclas ){


                   if( GAME->tecleable ){       //Condicion principal para teclear



                       if( teclas->key() == Qt::Key_W ){                   //Arriba

                           GAME->Main_player->movimientos_personaje( 0 ) ;
                       }
                       else if( teclas->key() == Qt::Key_S ){                  //Abajo

                           GAME->Main_player->movimientos_personaje( 1 ) ;
                       }
                       else if( teclas->key() == Qt::Key_A ){                      //Izquierda

                           GAME->Main_player->movimientos_personaje( 2 ) ;
                       }
                       else if( teclas->key() == Qt::Key_D ){                      //Derecha

                           GAME->Main_player->movimientos_personaje( 3 ) ;
                       }
                       else if( teclas->key() == Qt::Key_E ){                  //Diagonal derecha - arriba

                           GAME->Main_player->movimientos_personaje( 4 ) ;
                       }
                       else if( teclas->key() == Qt::Key_Q ){                      //Diagonal izquierda - Abajo

                           GAME->Main_player->movimientos_personaje( 5 ) ;

                       }
                       else if( teclas->key() == Qt::Key_Space ){          //Disparar

                       if( GAME->dis_paro ){

                           GAME->disparar() ;

                           sonido_disparo->play() ;

                           GAME->dis_paro = false ;

                            QTimer::singleShot( 500 , this, SLOT( barra_press() ) );
                                      }
                       }

                   }//fin condicion
               }

               void MainWindow::Guardar_progerso(){

                   QFile archivo( "guardado.txt" ) ;

                   archivo.open( QFile::ReadOnly | QFile::Text ) ;

                   QTextStream in( &archivo ) ;

                   QString todo_el_archivo ;

                   while( !in.atEnd() ){

                       QString linea = in.readLine();

                       QString comparacion ;

                       comparacion = linea.section(" " , 0 , 0 ) ;

                       if( comparacion == GAME->nombre_jugador ){

                           QString reemplazo, avn , levl , points ;

                           avn = QString::number( GAME->select_av ) ;

                           levl = QString::number( GAME->nivel_jugador ) ;

                           points = QString::number( puntos ) ;

                           reemplazo = GAME->nombre_jugador + " Avn:" + avn + " N:" + levl + " P:" + points + ";" + '\n' ;

                           todo_el_archivo.append( reemplazo ) ;

                       }
                       else{

                          linea.append( '\n' ) ;

                          todo_el_archivo.append( linea ) ;
                       }


                       archivo.close() ;



                       QFile archivo2( "guardado.txt" ) ;

                       archivo2.open( QFile::WriteOnly | QFile::Text ) ;

                       QTextStream out( &archivo2 );

                       out << todo_el_archivo ;

                       archivo2.close() ;

                   } //fin while

}
               void MainWindow::barra_press(){

                   GAME->dis_paro = true ;

               }


               void MainWindow::spawn_enemigo(){

                   int random_num1 = rand()%3 ;        //numero aleatorio entre 0 y 2

                   int random_num2 = rand()%360 ;

                   ENEmigos = new enemigos( random_num1, GAME->nivel_jugador ) ;

                   ENEmigos->set_enemigo() ;

                   if(random_num1==0)
                   {
                       random_num2= rand()%720;
                       ENEmigos->setPos(random_num2, 0);
                   }
                   else{
                       if(ENEmigos->amplitud==1 && (random_num2>345))random_num2=random_num2-18;
                       else if(ENEmigos->amplitud==2 && (random_num2>345))random_num2=random_num2-20;

                       ENEmigos->setPos( 800 , random_num2 ) ;
                   }

                   GAME->level_one->addItem( ENEmigos ) ;



               }

               void MainWindow::on_instrucciones_clicked(){
                   efecto_boton_click->play() ;

                   ui->texto_instrucciones->show() ;

                   ui->instrucciones->hide() ;

                   ui->regresar->show() ;

                   ui->Jugar->hide() ;

                   //ui->Multijugador->hide() ;

                   ui->Salir->hide() ;
               }
               void MainWindow::update_nivel(){


                   if( !GAME->epic_fail ){

                       if( GAME->nivel_jugador < 3 ){

                           GAME->tecleable = false ;

                           GAME->nivel_jugador++ ;

                           puntos = puntos + 5000 ;

                           lvl_cambio->play() ;

                           GAME->tiempo_enemigos = GAME->tiempo_enemigos - 1500 ;

                           borrar_cambio_escena() ;

                           nivel_1() ;

                       }
                       else{


                           ui->completado->show() ;

                           msc_2->stop() ;

                           ending_theme->play() ;

                           GAME->Main_player->caida_libre->stop() ;

                           GAME->Main_player->animacion->stop() ;

                           GAME->backg_screen->cambiar_frame->stop() ;

                           ui->Salir->show() ;

                           GAME->tecleable = false ;

                           end_game->stop() ;

                           timer_spawn_enemy->stop() ;

                           Guardar_progerso() ;

                       }


                   }



               }


               void MainWindow::borrar_cambio_escena(){

                   GAME->Main_player->caida_libre->stop() ;

                   GAME->Main_player->animacion->stop() ;

                   ENEmigos->timer_enemy->stop() ;

                   GAME->level_one->removeItem( GAME->Main_player ) ;

                   GAME->backg_screen->cambiar_frame->stop() ;

                   GAME->level_one->removeItem( GAME->backg_screen ) ;


                   delete GAME->backg_screen ;


                   GAME->Revisar_game_over->stop() ;


                   delete GAME->Revisar_game_over ;


                   GAME->level_one->clear() ;


                   delete GAME->level_one ;


                   end_game->stop() ;


                   delete  end_game ;


                   timer_spawn_enemy->stop() ;


                   delete timer_spawn_enemy ;


               }
               void MainWindow::multi_jugador(){

                   //Sistema de turnos, 60 segundos cada uno, el que haga más puntos

                   GAME->nombre_jugador = "player_1" ;

                   GAME->select_av = 1 + rand()%2 ;     //Un personaje aleatorio

                   GAME->nivel_jugador = 3 ;

                   GAME->tiempo_enemigos = 1000 ;

                   vidas = 1 ;     //Se juega de a 1 vida

                   //Montamos el nivel

                   GAME->set_level_one() ;

                   ui->graphicsView->setScene( GAME->level_one );

                   end_game = new QTimer() ;

                   connect( end_game , SIGNAL( timeout() ) , this , SLOT( perdiste_multiplayer() ) ) ;

                   end_game->start( 10 ) ;

                   GAME->tecleable = true ;

                   timer_spawn_enemy = new QTimer() ;

                   connect( timer_spawn_enemy , SIGNAL( timeout() ) , this , SLOT( spawn_enemigo() ) ) ;

                   timer_spawn_enemy->start( GAME->tiempo_enemigos ) ;

                   cambio_p_effect = new QSoundEffect ;

                   cambio_p_effect->setSource( QUrl("qrc:/Recursos/lushlife-levelup.wav") ) ;

                   puntuacion = new puntaje() ;

                   nombre_jugador = new puntaje() ;

                   health = new puntaje() ;

                   health->salud( 1 ) ;

                   puntuacion->aumentar_puntaje( 3 ) ;

                   nombre_jugador->whos_playing( GAME->nombre_jugador ) ;

                   GAME->level_one->addItem( puntuacion ) ;

                   GAME->level_one->addItem( nombre_jugador ) ;

                   GAME->level_one->addItem( health ) ;

                   QTimer::singleShot( 60000 , this, SLOT( change_player_multiP() ) );

               }


               void MainWindow::change_player_multiP(){

                   cambio_p_effect->play() ;

                   GAME->flag_multip = false ;

                   GAME->int_flag = 1 ;


                   if( !GAME->epic_fail ){


                       GAME->puntos_1player = puntos ;

                       delete puntuacion ;

                       delete health ;

                       delete nombre_jugador ;


                       borrar_cambio_escena() ;

                       GAME->nombre_jugador = "player_2" ;

                       GAME->select_av = 1 + rand()%2 ;     //Un personaje aleatorio

                       GAME->nivel_jugador = 3 ;

                       GAME->tiempo_enemigos = 1000 ;

                       vidas = 1 ;     //Se juega de a 1 vida

                       puntos = 0 ;

                       GAME->set_level_one() ;

                       ui->graphicsView->setScene( GAME->level_one );

                       end_game = new QTimer() ;

                       connect( end_game , SIGNAL( timeout() ) , this , SLOT( perdiste_multiplayer() ) ) ;

                       end_game->start( 10 ) ;

                       GAME->tecleable = true ;

                       timer_spawn_enemy = new QTimer() ;

                       connect( timer_spawn_enemy , SIGNAL( timeout() ) , this , SLOT( spawn_enemigo() ) ) ;

                       timer_spawn_enemy->start( GAME->tiempo_enemigos ) ;

                       puntuacion = new puntaje() ;

                       nombre_jugador = new puntaje() ;

                       health = new puntaje() ;

                       health->salud( 1 ) ;

                       puntuacion->aumentar_puntaje( 3 ) ;

                       nombre_jugador->whos_playing( GAME->nombre_jugador ) ;

                       GAME->level_one->addItem( puntuacion ) ;

                       GAME->level_one->addItem( nombre_jugador ) ;

                       GAME->level_one->addItem( health ) ;

                       QTimer::singleShot( 60000 , this, SLOT( final_multiP() ) );

                   }


               }

               void MainWindow::perdiste_multiplayer(){

                   if( GAME->Fin_partida && GAME->flag_multip ){


                       change_player_multiP() ;

                       GAME->epic_fail = true ;

                       GAME->flag_multip = false ;

                       GAME->Fin_partida = false ;

                       GAME->int_flag = 1 ;

                   }


                   if( GAME->Fin_partida && GAME->int_flag == 1 ){

                       msc_2->stop() ;

                       ui->Salir->show() ;

                       GAME->tecleable = false ;

                       end_game->stop() ;

                       timer_spawn_enemy->stop() ;

                       GAME->puntos_2player = puntos ;

                       if( GAME->puntos_1player > GAME->puntos_2player ){

                           ui->ganador_p1_txt->show() ;
                       }
                       else{

                              ui->ganador_p2_txt->show() ;
                       }

                   }


               }

               void MainWindow::final_multiP(){

                   //final del tiempo 2 player

                   GAME->Fin_partida = true ;
}
