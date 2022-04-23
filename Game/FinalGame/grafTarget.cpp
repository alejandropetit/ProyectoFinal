#include "grafTarget.h"

grafTarget::grafTarget(int px, int py, int image, int movepattern, double tilt, double enemy,  int interval)
{
    MovePattern = movepattern, Px = px, Px_ = px, Py = py, Py_ = py, Interval = interval, Tilt = tilt;
    if(image == 0){
    Target.load(":/images/tank.png");
    setPixmap(Target.scaled(128,80));
    }
    else if(image == 1){
    Target.load(":/images/school.png");
    setPixmap(Target.scaled(169,60));
    }
    else if(image == 2){
    Target.load(":/images/helicopter.png");
    setPixmap(Target.scaled(169,60));
    }
    else if(image == 3){
    Target.load(":/images/plane.png");
    setPixmap(Target.scaled(169,60));
    }
    Vx = V*cos(Tilt*M_PI/180), Vy = V*sin(Tilt*M_PI/180);
    setRotation(tilt);
    setPos(Px, Py);
}

void grafTarget::move(double T)
{
    switch(MovePattern){
    case 0:{

        double Ax = 0, Ay = 9.8;
        if(Py <470){
            Vx = Vx + (Ax*T);
            Vy = Vy + (Ay*T);
            Px = Px + (Vx*T);
            Py = Py + (Vy*T);
        }
        setPos(Px,Py);


    }break;
    case 1:{
        count ++;
        //if(count % 100 == 0) count1 ++;
        //if (count % Interval== 0)Vx = -Vx, Vy = -Vy;
        if(count % Interval == 0) Vx = -Vx, Vy = -Vy;
        Px = Px +Vx*T;
        Py = Py +Vy*T;

        setPos(Px,Py);
    }break;

    case 2:{
        count+=1;
        //int R = 100;
        Px = Px_+Interval*cos(0.1*count*M_PI/180);
        Py = Py_+Interval*sin(0.1*count*M_PI/180);
        setPos(Px,Py);
    }break;

    case 3:{
        count+=1;
        //int R = 100;
        Px = Px_+Interval*cos(0.1*count*M_PI/180);
        Py = Py_+Interval*sin(0.2*count*M_PI/180);
        setPos(Px,Py);
    }break;

    case 4:{
        count+=1;
        //int R = 100;
        Px = Px_+Interval*cos(0.2*count*M_PI/180);
        Py = Py_+Interval*sin(0.1*count*M_PI/180);
        setPos(Px,Py);
    }break;
    case 5:{
        count++;
        //int R = 60, R1 = 15;
        Px = Px_+Interval*cos(0.1*count*M_PI/180)+(Interval/4)*cos(0.2*count*M_PI/180);
        Py = Py_+Interval*sin(0.3*count*M_PI/180)+(Interval/4)*sin(0.8*count*M_PI/180);
        setPos(Px,Py);
    }break;

    case 6:{
        count++;
        int A =100;
        Py = A*cos(0.5*count*M_PI/180+3);
        setPos(Px,Py);
    }break;

    case 7:{
        count++;
        //int R = 60, R1 = 15;
        Px = Px_+Interval*cos(0.1*count*M_PI/180)+(Interval/4)*cos(0.5*count*M_PI/180);
        Py = Py_+Interval*sin(0.1*count*M_PI/180)+(Interval/4)*sin(0.5*count*M_PI/180);
        setPos(Px,Py);
    }break;
    case 8:{

    };
    }
}

/*
grafTarget::grafTarget(int px, int py, int image, int movepattern, double tilt, double enemy)
{
    movePattern = movepattern;
    if(image == 0){
    target.load(":/images/tank.png");
    setPixmap(target.scaled(128,80));
    }
    else if(image == 1){
    target.load(":/images/school.png");
    setPixmap(target.scaled(169,60));
    }
    setPos(px, py);

    time = new QTimer();
    connect(time, SIGNAL(timeout()), this, SLOT(move()));
    time->start(100);


}

void grafTarget::move()
{
    this->setPos(this->x()+1,this->y()+1);
}
*/
