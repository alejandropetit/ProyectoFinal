#ifndef GRAFWALL_H
#define GRAFWALL_H

#include <QPainter>
#include <QGraphicsItem>
#include <QTransform>

class grafWall: public QGraphicsItem
{
public:
    grafWall(int px, int py, int width, int height, double tilt , bool bounce);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    int Px, Py, Width, Height, Tilt;
    QColor color;
    QPixmap pared;
    QTransform t;

};

#endif // GRAFWALL_H
