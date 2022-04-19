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
    this->setGeometry(0,0,1200,600);
    graphicsview->setGeometry(190,25,1000,550);
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

}
