#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    graphicsview = new QGraphicsView(this);
    scene = new QGraphicsScene;
    time = new QTimer;
    Shell = new shell(90,90,0,1);
    Turret = new turret(20,200,1);
    this->setGeometry(0,0,1200,600);
    graphicsview->setGeometry(190,25,1005,555);
    scene->setSceneRect(0,0,1000,550);
    graphicsview->setScene(scene);
    connect(time, SIGNAL(timeout()),this,SLOT(move()));
    //time->start(1);
    dresden();

    //buttons
    button[0] = new QPushButton("Disparar", this);

    //connections
    connect(button[0], SIGNAL(clicked()), this, SLOT(shoot()));


}

MainWindow::~MainWindow()
{
    delete ui;
    delete Shell;
}

void MainWindow::dresden()
{
    scene->addPixmap(QPixmap(":/images/dresden.png"));
    scene->addItem(Shell);
    Turret->add(scene);
    scene->addRect(0,0,995,545);
    //murosg.push_back(new wall(90,90,30,70,45,0));
    muros.push_back(new wall(10,150,130,30,0,0));
    muros.push_back(new wall(200,140,200,30,45,1));
    muros.push_back(new wall(200,257,450,30,0,1));
    enemies.push_back(new target(300,120,2,0,0,0,0));
    //for(list<wall*>::iterator I = murosb.begin(); I != murosb.end(); I++){
    //    scene->addItem(*I);
    //}
    for(list<wall*>::iterator I = muros.begin(); I != muros.end(); I++){
        scene->addItem(*I);
    }
    for(list<target*>::iterator I = enemies.begin(); I != enemies.end(); I++){
        scene->addItem(*I);
    }

}

void MainWindow::shoot()
{

    time->start(10);
}


void MainWindow::move()
{

    Turret->Howitzer->bullet->move(0.1);

    for(list<wall*>::iterator I = muros.begin(); I != muros.end(); I++){
        if(Shell->collidesWithItem(*I)){
            qDebug() << "qutald";
           Turret->Howitzer->bullet->Vx = - Turret->Howitzer->bullet->Vx;
           Turret->Howitzer->bullet->Vy  = -Turret->Howitzer->bullet->Vy;
        }
    }


    for(list<target*>::iterator I = enemies.begin(); I != enemies.end(); I++){
        if(Shell->collidesWithItem(*I)){
            qDebug() << "lola";
           //Turret->Howitzer->bullet->Vx = - Turret->Howitzer->bullet->Vx;
           //Turret->Howitzer->bullet->Vy  = -Turret->Howitzer->bullet->Vy;
        }
    }

    //for(list<target*>::iterator I = enemies.begin(); I != enemies.end(); I++){
    //    (*I)->move(1);
    //}
}

void MainWindow::keyPressEvent(QKeyEvent *press)
{
    switch (press->key()){
    case Qt::Key_D: {
        Shell->setPos(Shell->x()+1,Shell->y());
        /*
        if(shell->collidesWithItem()){
            qDebug() << "si choco mi perrito";
        }
        if(shell->collidesWithItem(school)){
            qDebug() << "que te pasa es una escuela";
        }
        if(shell->collidesWithItem(tank)){
            qDebug() << "plomo";
        }
        */
     }break;
    case Qt::Key_A: {
        Shell->setPos(Shell->x()-1,Shell->y());
    }break;
    case Qt::Key_S: {
        Shell->setPos(Shell->x(),Shell->y()+1);
    }break;
    case Qt::Key_W: {
        Shell->setPos(Shell->x(),Shell->y()-1);
    }break;

    }
}
