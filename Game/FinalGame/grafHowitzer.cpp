#include "grafHowitzer.h"

grafHowitzer::grafHowitzer(int px, int py, double tilt, bool spin)
{
    Px = px, Py = py, Tilt = tilt, Spin = spin;
    howitzer.load(":/images/howitz_0r.png");
    this->setPos(px,py);
    setPixmap(howitzer.scaled(91,20));

}


void grafHowitzer::Actualizar(int px, int py, double tilt, bool spin)
{
    qDebug() << "PIPO";
    double tilt1 = tilt;
    tilt =  tilt - Tilt , Tilt = tilt1;
    if(tilt1 != tilt){

        tilt = tilt * M_PI/180;
        this->setTransform(QTransform(cos(tilt), sin(tilt), -sin(tilt), cos(tilt), 0, 0),true);
    }
    //Tilt = tilt;
}

void grafHowitzer::mejorar()
{

}

void grafHowitzer::rotate(double tilt)
{


}
