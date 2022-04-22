#include "grafWall.h"

grafWall::grafWall(int px, int py, int width, int height, double tilt , bool bounce)
{
    if(bounce) pared.load(":/images/black.jpeg"), color = Qt::black;
    else pared.load(":/images/gray.jpeg"), color = Qt::gray;
    QBrush textura(pared);
    QPen pen(Qt::black,2);
    setRect(0,0,width,height);
    setPos(px,py);
    setRotation(tilt);
    setPen(pen);
    setBrush(textura);
}
