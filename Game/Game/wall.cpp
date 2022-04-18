#include "wall.h"

wall::wall(int px, int py, int width, int height, double tilt , bool bounce)
{
    Px = px, Py = py, Width = width, Height = height, Tilt = tilt;
    if(bounce) pared.load(":/images/black.jpeg"), color = Qt::black;
    else pared.load(":/images/gray.jpeg"), color = Qt::gray;
    //setPixmap(pared.scaled(width,height));
    //this->setRotation(45);

}
/*
void wall::paintEvent(QPaintEvent *)
{
    //QPainter painter(this);
    //painter.drawRect(90,90,40,50);
    //painter.setPen(Qt::blue);
    //painter.setFont(QFont("Arial", 30));
    //painter.drawText(rect(), Qt::AlignCenter, "Qt");

}
*/

QRectF wall::boundingRect() const
{
    return QRectF(-Px/2,-Py/2,Width,Height);
}

void wall::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(color, 2));
    painter->setBrush(QBrush(pared));
    painter->drawRect(boundingRect());
    //this->setRotation(Tilt);

}

