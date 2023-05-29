#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/recursos/logo.png"));
    GAME = new juego;
    QString val;
    val += "\n Presiona en OK para continuar con el menú del juego ";
    val += "\n de lo contrario, dale en X. ";
    QMessageBox::about (this,"Bienvenid@" , val);

    setMenu();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setMenu(){     //Funcion en la cual se inicializa y muestra el menu del juego
    //Configuracion de la escena

    GAME->escena_Menu();
    setGeometry( 0, 0 , GAME->getTam_X() + 2 , GAME->getTam_Y()+ 2) ;
    setMaximumSize(GAME->getTam_X() + 2 , GAME->getTam_Y() + 2 ) ;
    setMinimumSize(GAME->getTam_X() + 2 , GAME->getTam_Y() + 2 ) ;

    ui->graphicsView->setGeometry( 0, 0 , GAME->getTam_X() + 2 , GAME->getTam_Y() + 2 ) ;
    ui->graphicsView->setScene( GAME->getMenu() );

}
