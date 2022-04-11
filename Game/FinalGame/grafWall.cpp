#include "grafWall.h"

grafWall::grafWall(int px, int py, int width, int height, double tilt , bool bounce)
{
    Px = px, Py = py, Width = width, Height = height, Tilt = tilt;
    if(bounce) pared.load(":/images/black.png"), color = Qt::black;
    else pared.load(":/images/gray.png"), color = Qt::gray;

}




QRectF grafWall::boundingRect() const
{
    return QRectF(Px,Py,Width,Height);
}



void grafWall::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(color, 1));
    painter->setBrush(QBrush(pared));
    painter->rotate(45);
    painter->drawRect(boundingRect());
}

