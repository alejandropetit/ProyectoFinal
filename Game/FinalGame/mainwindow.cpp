#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //scene y graphicsview
    graphicsview = new QGraphicsView(this);
    ventana = new signin;
    scene = new QGraphicsScene;
    //scene->setSceneRect(0,0,795,595);
    //scene->addPixmap(QPixmap(":/images/1.png"));
    //scene->addEllipse(30,20,10,10);
    graphicsview->setScene(scene);
    //
    turret = new grafTurret(100,100,1);
    //muro[0] = new grafWall(400,200,40,100,45,1);
    //school = new grafTarget(300, 400, 1, 1, 0, 0,0);
    //tank = new grafTarget(600, 450, 0, 1, 0, 0,0);
    //shell = new grafShell(70,70,0,1);
    //timers
    time = new QTimer();//bala
    time1 =new QTimer;//enemigos
    //botones
    button[0] = new QPushButton("Calcular Total", this);
    button[1] = new QPushButton("Disparar", this);
    button[2] = new QPushButton("Jugar",this);
    button[0]->setGeometry(10,180,171,31);
    button[1]->setGeometry(10,522,171,51);
    button[2]->setGeometry(300,362,231,61);
    //labels y spinbox

    label[0] = new QLabel("Incliacion", this);
    label[1] = new QLabel("Potencia", this);
    label[2] = new QLabel("Masa del Proyectil", this);
    label[3] = new QLabel("Costo Total",this);
    label[4] = new QLabel("0$",this);
    for(int i = 0; i <3; i++){
        spinbox[i] = new QDoubleSpinBox(this);
    }
    for(int i = 0, j = 259; i < 3; i++, j+=55){
        label[i]->setGeometry(11,j,169,18);
        spinbox[i]->setGeometry(11,j+25,169,18);
    }
    label[3]->setGeometry(11,452,109,22);
    label[4]->setGeometry(11,480,109,22);
    spinbox[0]->setMaximum(90);
    spinbox[0]->setMinimum(-15);
    spinbox[1]->setMaximum(9000000);

    //

    T = 0.0001;

    //caja

    box = new QGroupBox("alejandro", this);
    box->setGeometry(10,20,171,141);


    //escena y graphicsview


    //signals

    QObject::connect(ventana, SIGNAL(back(QString)),this, SLOT(mostrar(QString)));
    connect(button[2],SIGNAL(clicked()),this,SLOT(registro()));
    connect(spinbox[0], SIGNAL(editingFinished()), this, SLOT(rotate()));
    connect(button[0],SIGNAL(clicked()), this ,SLOT(total()));
    connect(button[1],SIGNAL(clicked()),this,SLOT(disparar()));
    connect(time, SIGNAL(timeout()), this, SLOT(Actualizar()));
    connect(time1, SIGNAL(timeout()), this, SLOT(mover()));

    //


    ocultar();


}

MainWindow::~MainWindow()
{
    delete ui;
    delete graphicsview;
    delete ventana;
    delete time;
    delete scene;
    delete box;
    delete turret;
    for(int i = 0; i < 3; i++) delete button[i];
    for(int i = 0; i < 5; i++) delete label[i];
    for(int i = 0; i < 3; i++) delete spinbox[i];
    for(auto i : enemies ) delete i;
    for(auto i : murosb ) delete i;
    for(auto i : murosg ) delete i;
}

void MainWindow::nivel()
{
 aleppo();
 //dresden();
 //grozni();
 //sarajevo();
 turret->add(scene);
 //scene->addLine(120,137,120,228);//211,137);
 //scene->addLine(211,135,225,135);
 //scene->addLine(211,138,225,138);
 //scene->addItem(shell);
 //scene->addEllipse(29,39,182,182);
 //scene->addRect(300,300,50,50);
 //scene->addRect(330,340,40,10);

}

//Niveles
void MainWindow::dresden()
{
    scene->addPixmap(QPixmap(":/images/dresden.png"));
    scene->addItem(muro[0]);
    turret->Actualizar(80,200,0,1);
    //muros negros
    murosb.push_back(new grafWall(80,293,120,40,0,1));//turret
    murosb.push_back(new grafWall(980,0,20,550,0,1));//pared del fondo
    murosb.push_back(new grafWall(300,520,680,30,0,1));//piso
    murosb.push_back(new grafWall(500,400,449,30,0,1));//segundo piso//479
    murosb.push_back(new grafWall(500,260,30,140,0,1));//pared izquierda
    murosb.push_back(new grafWall(500,230,449,30,0,1));//tercer piso

    //muros grices
    murosg.push_back(new grafWall(950,0,30,520,0,0));
    murosg.push_back(new grafWall(300,493,210,30,-30,0));

    //enemigos
    enemies.push_back(new grafTarget(400,440,0,1,0,0,100));
    enemies.push_back(new grafTarget(650,440,0,1,0,0,44));
    enemies.push_back(new grafTarget(530,320,0,1,0,0,60));
    enemies.push_back(new grafTarget(700,150,0,1,0,0,30));

    for(auto i : murosb) scene->addItem(i);
    for(auto i : murosg) scene->addItem(i);
    for(auto i : enemies) scene->addItem(i);

    time1->start(100);
    //for(auto i : enemies ) delete i;
    //for(auto i : murosb ) delete i;
    //for(auto i : murosg ) delete i;
    //turret->Actualizar();
}

void MainWindow::sarajevo()
{
    scene->addPixmap(QPixmap(":/images/sarajevo.png"));
    turret->Actualizar(80,200,0,1);
    //muros negros
    murosb.push_back(new grafWall(80,293,120,40,0,1));//turret
    murosb.push_back(new grafWall(250,420,300,30,20,1));
    murosb.push_back(new grafWall(700,520,300,30,-20,1));
    murosb.push_back(new grafWall(510,515,200,30,0,1));

    //muros grices
    murosg.push_back(new grafWall(510,415,15,100,0,0));
    murosg.push_back(new grafWall(695,415,15,100,0,0));
    murosg.push_back(new grafWall(510,400,200,15,0,0));

    //enemies
    enemies.push_back(new grafTarget(650,40,3,1,0,0,7));
    enemies.push_back(new grafTarget(750,160,3,1,0,0,8));
    enemies.push_back(new grafTarget(350,375,0,1,20,0,50));
    enemies.push_back(new grafTarget(740,425,0,1,-20,0,50));
    //friends
    friends.push_back(new grafTarget(525,455,1,0,0,1,0));



    //
    for(auto i : murosb) scene->addItem(i);
    for(auto i : murosg) scene->addItem(i);
    for(auto i : friends) scene->addItem(i);
    for(auto i : enemies) scene->addItem(i);

    time1->start(100);




}

void MainWindow::grozni()
{
    scene->addPixmap(QPixmap(":/images/grozni.png"));
    //muros negros
    //turret falta
    murosb.push_back(new grafWall(400,80, 400, 30,0,1));
    murosb.push_back(new grafWall(800,300, 169, 30,0,1));
    murosb.push_back(new grafWall(400,150, 30, 100,0,1));
    murosb.push_back(new grafWall(500, 400, 169, 30,30,1));
    murosb.push_back(new grafWall(600, 200, 40, 40,30,1));

    //muros grices
    murosg.push_back(new grafWall(400,110, 30, 40,0,0));
    //murosg.push_back(new grafWall(300,300,10,10,35,1));

    //enemigos
    enemies.push_back(new grafTarget(700,40,2,4,0,0,75));
    enemies.push_back(new grafTarget(550,180,2,2,0,0,75));
    enemies.push_back(new grafTarget(550,470,0,1,0,0,75));

    //amigos
    friends.push_back(new grafTarget(800,240,1,1,0,0,7));

    for(auto i : murosb) scene->addItem(i);
    for(auto i : murosg) scene->addItem(i);
    for(auto i : friends) scene->addItem(i);
    for(auto i : enemies) scene->addItem(i);

    time1->start(1);

}

void MainWindow::aleppo()
{

    scene->addPixmap(QPixmap(":/images/aleppo.png"));
    turret->Actualizar(80,200,0,1);

    //muros negros
    murosb.push_back(new grafWall(750,150,40,40,0,1));
    murosb.push_back(new grafWall(500,150,40,40,45,1));
    murosb.push_back(new grafWall(850,150,40,40,0,1));
    murosb.push_back(new grafWall(400,150,40,40,45,1));
    murosb.push_back(new grafWall(750,350,40,40,0,1));
    murosb.push_back(new grafWall(500,250,40,40,45,1));
    murosb.push_back(new grafWall(850,450,40,40,0,1));
    murosb.push_back(new grafWall(400,350,40,40,45,1));


    //muros grices
    murosb.push_back(new grafWall(720,150,40,40,0,0));
    murosb.push_back(new grafWall(320,150,40,40,45,0));
    murosb.push_back(new grafWall(500,300,40,40,0,0));
    murosb.push_back(new grafWall(420,400,40,40,45,0));
    murosb.push_back(new grafWall(700,350,40,40,0,0));


    //enemigos
    enemies.push_back(new grafTarget(650,440,2,7,0,0,80));
    enemies.push_back(new grafTarget(750,440,2,5,0,0,30));
    enemies.push_back(new grafTarget(530,320,2,6,0,0,40));
    //enemies.push_back(new grafTarget(700,150,2,2,0,0,100));
    //enemies.push_back(new grafTarget(700,150,2,7,0,0,60));

    //friends

    for(auto i : murosb) scene->addItem(i);
    for(auto i : murosg) scene->addItem(i);
    for(auto i : friends) scene->addItem(i);
    for(auto i : enemies) scene->addItem(i);


    time1->start(1);
    //scene->addItem(shell);
    //scene->addItem(school);
    //scene->addItem(tank);
    //scene->addItem(muro[0]);
}
//ventanas
void MainWindow::ocultar()
{
    this->setGeometry(0,22,800,556);
    graphicsview->setGeometry(0,0,800,600);
    for(int i = 0; i < 3; i++){
        label[i]->setVisible(false);
        if(i != 2) button[i]->setVisible(false);
        spinbox[i]->setVisible(false);
    }
    label[3]->setVisible(false);
    label[4]->setVisible(false);
    box->setVisible(false);
    scene->setSceneRect(0,0,795,595);
    scene->addPixmap(QPixmap(":/images/1.png"));
    scene->addEllipse(30,20,10,10);
    button[2]->setVisible(true);

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
//rotacion del canon
void MainWindow::rotate()
{

    turret->Actualizar(turret->Px,turret->Py,spinbox[0]->value(),turret->Spin);
}
//calculo de precio
void MainWindow::total()
{
    //turret->howitzer->bullet->Actualizar(turret->Px,turret->Py,spinbox[0]->value(),turret->Spin,spinbox[0]->value(),0);

    //turret->Actualizar(100,100,0,0);
    //i++;

}
//movimiento de la bala
void MainWindow::disparar()
{
    time->stop();
    turret->Actualizar(turret->Px,turret->Py,spinbox[0]->value(),turret->Spin);
    turret->Howitzer->bullet->values(spinbox[1]->value(),spinbox[2]->value(),spinbox[0]->value());
    time->start(T);
}

void MainWindow::Actualizar()
{
    if(k)
    turret->Howitzer->bullet->move(0.1);
    for(auto i : murosb){
        if(turret->Howitzer->bullet->collidesWithItem(i)){
           //turret->Howitzer->bullet->Vx = - turret->Howitzer->bullet->Vx;
          // turret->Howitzer->bullet->Vy  = -turret->Howitzer->bullet->Vy;
            //turret->Howitzer->bullet->explosion();
            //k = 0;
        }
    }
    for(auto i : murosg){
        if(turret->Howitzer->bullet->collidesWithItem(i)){

        }
    }
    for(auto i : enemies){
        if(turret->Howitzer->bullet->collidesWithItem(i)){
            qDebug("anestecia");
        }
    }
    for(auto i : friends){
        if(turret->Howitzer->bullet->collidesWithItem(i)){
            qDebug("que pasa");
        }
    }
}
//movimientos de los enemigos
void MainWindow::mover()
{
    for(auto i : enemies) i->move(0.1);
}



void MainWindow::on_actionMenu_Principal_triggered()
{
    //scene->clear();
    //for(auto i : enemies ) delete i;
    //for(auto i : murosb ) delete i;
    //for(auto i : murosg ) delete i;
    //for(auto i : friends) delete i;
    ocultar();
}

