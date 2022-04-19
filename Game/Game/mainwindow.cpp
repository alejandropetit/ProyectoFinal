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
    Turret = new turret(90,90,0);
    //Howitzer = new howitzer(90,90,45,1,3);
    this->setGeometry(0,0,1200,600);
    graphicsview->setGeometry(190,25,1000,550);
    Turret->add(scene);
    scene->addLine(90,90,90,200);
    graphicsview->setScene(scene);
    connect(time, SIGNAL(timeout()),this,SLOT(move()));
    time->start(100);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::move()
{
    t++;
    Turret->Actualizar(90,90,t,0);
}
