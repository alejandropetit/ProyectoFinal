#ifndef GRAFWALL_H
#define GRAFWALL_H

#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsRectItem>

class grafWall: public QGraphicsRectItem
{
public:
    grafWall(int px, int py, int width, int height, double tilt , bool bounce);

private:
    QColor color;
    QPixmap pared;
};

#endif // GRAFWALL_H
