#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ventana = new signin;
    scene = new QGraphicsScene;
    scene->setSceneRect(0,0,795,595);

    scene->addPixmap(QPixmap(":/images/1.png"));
    scene->addEllipse(30,20,10,10);
    graphicsview = new QGraphicsView(this);
    graphicsview->setGeometry(0,0,800,600);

    graphicsview->setScene(scene);

    button[0] = new QPushButton("Calcular Total", this);
    button[1] = new QPushButton("Disparar", this);
    button[2] = new QPushButton("Jugar",this);
    label[0] = new QLabel("Incliacion", this);
    label[1] = new QLabel("Potencia", this);
    label[2] = new QLabel("Masa del Proyectil", this);
    label[3] = new QLabel("Costo Total",this);
    label[4] = new QLabel("0$",this);
    for(int i = 0; i <3; i++){
        spinbox[i] = new QDoubleSpinBox(this);
    }
    button[0]->setGeometry(10,180,171,31);
    button[1]->setGeometry(10,522,171,51);
    button[2]->setGeometry(300,362,231,61);
    for(int i = 0, j = 259; i < 3; i++, j+=55){
        label[i]->setGeometry(11,j,169,18);
        spinbox[i]->setGeometry(11,j+25,169,18);
    }
    label[3]->setGeometry(11,452,109,22);
    label[4]->setGeometry(11,480,109,22);
    ui->pushButton_6->hide();
    QObject::connect(ventana, SIGNAL(back(QString)),this, SLOT(mostrar(QString)));
    connect(button[2],SIGNAL(clicked()),this,SLOT(registro()));
    ui->graphicsView->hide();
    ocultar();

}

MainWindow::~MainWindow()
{
    delete ui;
    //delete scene;
}

void MainWindow::ocultar()
{
    for(int i = 0; i < 3; i++){
        label[i]->setVisible(false);
        if(i != 2) button[i]->setVisible(false);
        spinbox[i]->setVisible(false);
    }
    label[3]->setVisible(false);
    label[4]->setVisible(false);

}

void MainWindow::registro()
{
    ventana->show();
}


void MainWindow::mostrar(QString t)
{
    ventana->hide();
    this->show();
    qDebug()<< t;
    //ui->centralwidget->setStyleSheet("background-image: url()");
    this->setGeometry(0,0,1200,600);
    scene->deleteLater();
    scene->setSceneRect(190,25,995,545);
    scene->addEllipse(50,50,20,20);
    graphicsview->setGeometry(190,25,1000,550);
    //scene->removeItem();
    //scene->addPixmap();
    for(int i = 0; i < 3; i++){
        label[i]->setVisible(true);
        button[i]->setVisible(true);
        if(i == 2)button[i]->setVisible(false);
        spinbox[i]->setVisible(true);
    }
    label[3]->setVisible(true);
    label[4]->setVisible(true);

}






