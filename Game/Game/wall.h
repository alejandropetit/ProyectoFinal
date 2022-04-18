#ifndef WALL_H
#define WALL_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QPaintEvent>
#include <QWidget>

class wall: public QGraphicsPixmapItem, public QWidget
{
public:
    wall(int px, int py, int width, int height, double tilt , bool bounce);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected:
    //
    //void paintEvent(QPaintEvent *);
    //QRectF boundingRect() const;
    //void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
private:
    int Px, Py, Width, Height, Tilt;
    QColor color;
    QPixmap pared;
};

#endif // WALL_H
