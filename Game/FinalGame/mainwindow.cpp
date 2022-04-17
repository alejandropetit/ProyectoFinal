#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //objetos
    graphicsview = new QGraphicsView(this);
    ventana = new signin;
    time = new QTimer();
    scene = new QGraphicsScene;
    //shell = new grafShell(0,0,0,0);
    box = new QGroupBox("alejandro", this);
    //howitzer = new grafHowitzer(120,130,0,1);
    turret = new grafTurret(100,100,1);
    //shell = new grafShell(turret->Px+91, turret->Py+37, 0, 0, 0);
    //shell = new grafShell();
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
    T = 0.0001;
    //

    //geometria
    scene->setSceneRect(0,0,795,595);
    button[0]->setGeometry(10,180,171,31);
    button[1]->setGeometry(10,522,171,51);
    button[2]->setGeometry(300,362,231,61);
    for(int i = 0, j = 259; i < 3; i++, j+=55){
        label[i]->setGeometry(11,j,169,18);
        spinbox[i]->setGeometry(11,j+25,169,18);
    }
    label[3]->setGeometry(11,452,109,22);
    label[4]->setGeometry(11,480,109,22);
    box->setGeometry(10,20,171,141);
    scene->addPixmap(QPixmap(":/images/1.png"));
    scene->addEllipse(30,20,10,10);
    graphicsview->setGeometry(0,0,800,600);
    graphicsview->setScene(scene);
    spinbox[0]->setMaximum(90);
    spinbox[0]->setMinimum(-15);
    //

    //signals

    QObject::connect(ventana, SIGNAL(back(QString)),this, SLOT(mostrar(QString)));
    connect(button[2],SIGNAL(clicked()),this,SLOT(registro()));
    connect(spinbox[0], SIGNAL(editingFinished()), this, SLOT(rotate()));
    connect(button[0],SIGNAL(clicked()), this ,SLOT(total()));
    connect(button[1],SIGNAL(clicked()),this,SLOT(disparar()));
    connect(time, SIGNAL(timeout()), this, SLOT(Actualizar()));
    //

    ui->pushButton_6->hide();
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
    box->setVisible(false);

}

void MainWindow::nivel()
{
 turret->add(scene);
 //scene->addLine(120,137,120,228);//211,137);
 scene->addLine(211,135,225,135);
 scene->addLine(211,138,225,138);
 //scene->addItem(shell);
 scene->addEllipse(29,39,182,182);
 scene->addRect(300,300,50,50);
 scene->addRect(330,340,40,10);
}

void MainWindow::registro()
{
    ventana->show();
    ventana->setGeometry(this->x()+200,this->y()+150,400,300);
}


void MainWindow::mostrar(QString t)
{
    ventana->hide();
    this->show();
    qDebug()<< t;
    //ui->centralwidget->setStyleSheet("background-image: url()");
    box->setTitle(t);
    this->setGeometry(0,0,1200,600);
    scene->clear();
    graphicsview->setGeometry(190,25,1000,550);
    scene->setSceneRect(0,0,995,545);
    scene->addLine(0,0,100,100);
    scene->addEllipse(0,0,200,200);
    //scene->addPixmap();
    for(int i = 0; i < 3; i++){
        label[i]->setVisible(true);
        button[i]->setVisible(true);
        if(i == 2)button[i]->setVisible(false);
        spinbox[i]->setVisible(true);
    }
    label[3]->setVisible(true);
    label[4]->setVisible(true);
    box->setVisible(true);
    nivel();

}

void MainWindow::rotate()
{

    turret->Actualizar(turret->Px,turret->Py,spinbox[0]->value(),turret->Spin);

    //turret->howitzer->bullet->Actualizar(turret->Px,turret->Py,spinbox[0]->value(),turret->Spin);
}

void MainWindow::total()
{
    //turret->howitzer->bullet->Actualizar(turret->Px,turret->Py,spinbox[0]->value(),turret->Spin,spinbox[0]->value(),0);

    turret->Actualizar(100,100,0,0);
    i++;
}

void MainWindow::disparar()
{
    time->start(T);
}

void MainWindow::Actualizar()
{
    //ti +=T;
    turret->howitzer->bullet->move(T);
}








