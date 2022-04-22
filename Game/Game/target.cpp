#include "target.h"

target::target(int px, int py, int image, int movepattern, double tilt, double enemy,  int interval)
{
    MovePattern = movepattern, Px = px, Py = py, Interval = interval;
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
    setRotation(tilt);
    setPos(Px, Py);
}

void target::move(double T)
{
    switch(MovePattern){
    case 0:{
        double Ax = 0, Ay = 9.8;
        Vx = Vx + (Ax*T);
        Vy = Vy + (Ay*T);
        Px = Px + (Vx*T);
        Py = Py + (Vy*T);
        setPos(Px,Py);

    }break;
    case 1:{
        count ++;
        if (count % Interval== 0)Vx = -Vx, Vy = -Vy;
        Px = Px +Vx;
        Py = Py +Vy;
        setPos(Px,Py);
    }break;

    case 2:{
        count+=1;
        int R = 100;
        Px = R*cos(0.1*count*M_PI/180);
        Py = R*sin(0.1*count*M_PI/180);
        setPos(Px,Py);
    }break;

    case 3:{
        count+=1;
        int R = 100;
        Px = 300+R*cos(0.1*count*M_PI/180);
        Py = 200+R*sin(0.2*count*M_PI/180);
        setPos(Px,Py);
    }break;

    case 4:{
        count+=1;
        int R = 100;
        Px = 300+R*cos(0.2*count*M_PI/180);
        Py = 200+R*sin(0.1*count*M_PI/180);
        setPos(Px,Py);
    }break;
    case 5:{
        count++;
        int R = 60, R1 = 15;
        Px = 300+R*cos(0.1*count*M_PI/180)+R1*cos(0.2*count*M_PI/180);
        Py = 200+R*sin(0.3*count*M_PI/180)+R1*sin(0.8*count*M_PI/180);
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
        int R = 60, R1 = 15;
        Px = 300+(R*cos(0.1*count*M_PI/180)+R1*cos(0.5*count*M_PI/180));
        Py = 200+R*sin(0.1*count*M_PI/180)+R1*sin(0.5*count*M_PI/180);
        setPos(Px,Py);
    }break;
    }
}


