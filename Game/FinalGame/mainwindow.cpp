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
    graphicsview->setScene(scene);
    //
    turret = new grafTurret(100,100,1);

    //timers
    time = new QTimer();//bala
    time1 =new QTimer;//enemigos
    //botones
    button[0] = new QPushButton("Calcular Total", this);
    button[1] = new QPushButton("Disparar", this);
    button[2] = new QPushButton("Jugar",this);
    button[3] = new QPushButton("continuar",this);
    button[0]->setGeometry(10,180,171,31);
    button[1]->setGeometry(10,522,171,51);
    button[2]->setGeometry(300,362,231,61);
    button[3]->setGeometry(300,362,231,61);

    //labels y spinbox

    label[0] = new QLabel("Incliacion", this);
    label[1] = new QLabel("Velocidad", this);
    label[2] = new QLabel("Pasos Restantes",this);
    label[3] = new QLabel("0",this);
    for(int i = 0; i <2; i++){
        spinbox[i] = new QDoubleSpinBox(this);
    }
    for(int i = 0, j = 259; i < 2; i++, j+=55){
        label[i]->setGeometry(11,j,169,18);
        spinbox[i]->setGeometry(11,j+25,169,18);
    }
    label[2]->setGeometry(11,452,109,22);
    label[3]->setGeometry(11,480,109,22);
    spinbox[0]->setMaximum(90);
    spinbox[0]->setMinimum(-45);
    spinbox[1]->setMaximum(9000000);

    //

    T = 0.0001;

    //caja

    box = new QGroupBox("alejandro", this);
    box->setGeometry(10,20,171,141);


    //escena y graphicsview


    //signals

    QObject::connect(ventana, SIGNAL(back(QString)),this, SLOT(mostrar(QString)));

    connect(spinbox[0], SIGNAL(editingFinished()), this, SLOT(rotate()));
    connect(button[0],SIGNAL(clicked()), this ,SLOT(total()));
    connect(button[1],SIGNAL(clicked()),this,SLOT(disparar()));
    connect(button[2],SIGNAL(clicked()),this,SLOT(registro()));
    connect(button[3],SIGNAL(clicked()), this, SLOT(change()));
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
    for(int i = 0; i < 2; i++) delete spinbox[i];
    for(auto i : enemies ) delete i;
    for(auto i : murosb ) delete i;
    for(auto i : murosg ) delete i;
}

//Niveles
void MainWindow::dresden()
{
    nivel = "Dresden";
    scene->addPixmap(QPixmap(":/images/dresden.png"));
    turret->add(scene);
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


}

void MainWindow::sarajevo()
{
    nivel = "Sarajevo";
    scene->addPixmap(QPixmap(":/images/sarajevo.png"));
    turret->add(scene);
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
    enemies.push_back(new grafTarget(375,400,0,1,20,0,50));
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
    nivel = "Grozni";
    scene->addPixmap(QPixmap(":/images/grozni.png"));
    turret->add(scene);
    turret->Actualizar(80,200,0,1);


    //muros negros

    murosb.push_back(new grafWall(400,80, 400, 30,0,1));
    murosb.push_back(new grafWall(800,300, 169, 30,0,1));
    murosb.push_back(new grafWall(400,150, 30, 100,0,1));
    murosb.push_back(new grafWall(500, 400, 169, 30,30,1));
    murosb.push_back(new grafWall(600, 200, 40, 40,30,1));

    //muros grices

    murosg.push_back(new grafWall(400,110, 30, 40,0,0));

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
    nivel = "Aleppo";
    scene->addPixmap(QPixmap(":/images/aleppo.png"));
    turret->add(scene);
    turret->Actualizar(80,200,0,1);

    //muros negros
    murosb.push_back(new grafWall(500,150,40,40,0,1));
    murosb.push_back(new grafWall(350,150,40,40,45,1));
    murosb.push_back(new grafWall(300,150,100,40,0,1));
    murosb.push_back(new grafWall(500,150,40,40,45,1));
    murosb.push_back(new grafWall(720,150,400,40,0,1));
    murosb.push_back(new grafWall(430,365,40,60,45,1));


    //muros grices
    murosg.push_back(new grafWall(680,324,40,40,0,0));
    murosg.push_back(new grafWall(350,400,40,80,0,0));
    murosg.push_back(new grafWall(422,328,80,40,0,0));
    murosg.push_back(new grafWall(350,400,100,40,-45,0));


    //enemigos
    enemies.push_back(new grafTarget(650,304,2,7,0,0,80));
    enemies.push_back(new grafTarget(450,440,2,5,0,0,50));
    enemies.push_back(new grafTarget(530,320,2,6,0,0,40));

    //friends
    friends.push_back(new grafTarget(720,90,1,1,0,0,0));
    friends.push_back(new grafTarget(720,488,1,1,0,0,0));

    for(auto i : murosb) scene->addItem(i);
    for(auto i : murosg) scene->addItem(i);
    for(auto i : friends) scene->addItem(i);
    for(auto i : enemies) scene->addItem(i);


    time1->start(1);


}
//ventanas
void MainWindow::ocultar()
{
    this->setGeometry(0,22,800,556);
    graphicsview->setGeometry(0,0,800,600);
    for(int i = 0; i < 2; i++){
        label[i]->setVisible(false);
        button[i]->setVisible(false);
        spinbox[i]->hide();
    }
    button[3]->setVisible(false);
    label[2]->setVisible(false);
    label[3]->setVisible(false);
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
    box->setTitle(t);
    this->setGeometry(0,0,1200,600);
    graphicsview->setGeometry(190,25,1000,550);
    scene->setSceneRect(0,0,995,545);
    for(int i = 0; i < 3; i++){
        if(i != 2)label[i]->setVisible(true);
        button[i]->setVisible(true);
        if(i == 2)button[i]->setVisible(false);
        if(i != 2)spinbox[i]->setVisible(true);
    }
    label[2]->setVisible(true);
    label[3]->setVisible(true);
    box->setVisible(true);
    scene->clear();

    //label[4]->setGeometry(0,0, 200,100);
    fstream file;
    string letter, word;
    int space = 0, count = 0;
    bool k = 0;
    file.open("/home/jose/Documentos/GitHub/ProyectoFinal/Game/FinalGame/Registro.txt",fstream::in);
    if(file.is_open()){
        file.seekg (0, file.end);
        unsigned long long length = file.tellg();
        file.seekg (0, file.beg);
        for(unsigned long long i = 0; i < length; i++){
            letter = file.get();
            if(letter == " "  || letter == "\n"){
                if(space == 0) {
                    if(word == t.toStdString())k = 1;
                    else word = "";
                }
                space++;
            }
            else if(k){
                if(count == 1){
                    if(letter == "0")ui->actionSarajevo->setVisible(false);
                }
                else if(count == 2){
                    if(letter == "0")ui->actionGrozni->setVisible(false);
                }
                else if(count == 3){
                    if(letter == "0")ui->actionAleppo->setVisible(false);
                }
                count++;
            }
            else word.append(letter);
        }
    }
    file.close();
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
    turret->Howitzer->bullet->Velocities(spinbox[1]->value());
    time->start(100);
}

void MainWindow::Actualizar()
{
    turret->Howitzer->bullet->move(0.1);
    for(auto i : murosb){
        if(turret->Howitzer->bullet->collidesWithItem(i)){
            if(turret->Howitzer->bullet->Vx > turret->Howitzer->bullet->Vy){
                turret->Howitzer->bullet->Vx =  -turret->Howitzer->bullet->Vx;
                turret->Howitzer->bullet->Vy  = turret->Howitzer->bullet->Vy;
            }
            else{
                turret->Howitzer->bullet->Vx =  turret->Howitzer->bullet->Vx;
                turret->Howitzer->bullet->Vy  = -turret->Howitzer->bullet->Vy;
            }
        }
    }
    for(auto iter = murosg.begin(); iter != murosg.end(); iter++){
        if(turret->Howitzer->bullet->collidesWithItem(*iter)){
            qDebug("Genial");
            scene->removeItem(*iter);
            murosg.erase(iter);
            time->stop();
            turret->Actualizar(turret->Px,turret->Py,spinbox[0]->value(),turret->Spin);
            break;
        }
    }
    for(auto iter = enemies.begin(); iter != enemies.end(); iter++){
        if(turret->Howitzer->bullet->collidesWithItem(*iter)){
            scene->removeItem(*iter);
            enemies.erase(iter);
            time->stop();
            turret->Actualizar(turret->Px,turret->Py,spinbox[0]->value(),turret->Spin);
            break;
        }
    }
    for(auto iter = friends.begin(); iter != friends.end(); iter++){
        if(turret->Howitzer->bullet->collidesWithItem(*iter)){
            scene->removeItem(*iter);
            friends.erase(iter);
            time->stop();
            turret->Actualizar(turret->Px,turret->Py,spinbox[0]->value(),turret->Spin);
            break;
        }
    }
    if(turret->Howitzer->bullet->Py > 550 || turret->Howitzer->bullet->Px > 1000 || turret->Howitzer->bullet->Px < 0){
        time->stop();
        turret->Actualizar(turret->Px,turret->Py,spinbox[0]->value(),turret->Spin);
    }
    if(enemies.empty()){
        win = 1;
        scene->setBackgroundBrush(QBrush(Qt::blue));
        button[3]->setVisible(true);//hay que ocultarlo

    }
}
//movimientos de los enemigos
void MainWindow::mover()
{
    for(auto i : enemies) i->move(0.1);
}

void MainWindow::change()
{
    enemies.clear();
    friends.clear();
    murosb.clear();
    murosg.clear();
    scene->clear();
    button[3]->setVisible(false);
    if(nivel == "Dresden"){
        if(win) sarajevo();
        else dresden();
    }
    else if (nivel == "Sarajevo"){
        if(win) grozni();
        else sarajevo();
    }
    else if (nivel == "Grozni"){
        if(win) aleppo();
        else grozni();
    }
    else if (nivel == "Aleppo"){
        if(win) ;//ver que se hace
        else aleppo();
    }
}


void MainWindow::on_actionDresden_triggered()
{
    enemies.clear();
    friends.clear();
    murosb.clear();
    murosg.clear();
    scene->removeItem(turret);
    scene->removeItem(turret->Howitzer);
    scene->removeItem(turret->Howitzer->bullet);
    dresden();
}


void MainWindow::on_actionSarajevo_triggered()
{
    enemies.clear();
    friends.clear();
    murosb.clear();
    murosg.clear();
    scene->removeItem(turret);
    scene->removeItem(turret->Howitzer);
    scene->removeItem(turret->Howitzer->bullet);
    sarajevo();
}


void MainWindow::on_actionGrozni_triggered()
{
    enemies.clear();
    friends.clear();
    murosb.clear();
    murosg.clear();
    scene->removeItem(turret);
    scene->removeItem(turret->Howitzer);
    scene->removeItem(turret->Howitzer->bullet);
    grozni();
}


void MainWindow::on_actionAleppo_triggered()
{
    enemies.clear();
    friends.clear();
    murosb.clear();
    murosg.clear();
    scene->removeItem(turret);
    scene->removeItem(turret->Howitzer);
    scene->removeItem(turret->Howitzer->bullet);
    aleppo();
}


void MainWindow::on_actionSalir_triggered()
{
    enemies.clear();
    friends.clear();
    murosb.clear();
    murosg.clear();
    ocultar();
}

