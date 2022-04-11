#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene;
    scene->setSceneRect(0,0,800,800);
    int px = 50, py = 50,width = 100, height = 200;
    bool bounce = 0;
    double tilt = 20;
    muro = new grafWall(400, py,width, height, tilt,bounce);
    turret = new grafTurret(px,py,true);
    scene->addItem(turret);
    scene->addItem(muro);
    ui->graphicsView->setScene(scene);

}

MainWindow::~MainWindow()
{
    delete ui;
}

