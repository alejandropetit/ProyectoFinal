#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    graphicsview = new QGraphicsView(this);
    scene = new QGraphicsScene;
    this->setGeometry(0,0,1200,600);
    graphicsview->setGeometry(190,25,1000,550);
    muro = new wall(50,50,30,80,60,0);
    scene->addItem(muro);
    scene->addLine(50,50,50,100);


    graphicsview->setScene(scene);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *press){
    switch (press->key()){
        case Qt::Key_D: {
            muro->setTransformOriginPoint(0,0);
            muro->setRotation(t);
            t++;
         }break;
    }
}

