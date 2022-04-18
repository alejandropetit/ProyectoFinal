#include "grafTarget.h"

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

