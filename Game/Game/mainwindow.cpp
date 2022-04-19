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
    Turret = new turret(90,90,1);
    this->setGeometry(0,0,1200,600);
    graphicsview->setGeometry(190,25,1000,550);
    scene->addItem(Turret);
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
    if (i)
    Turret->Actualizar(90,90,0,0), i = 0;
    else
        Turret->Actualizar(90,90,0,1), i = 1;
}
