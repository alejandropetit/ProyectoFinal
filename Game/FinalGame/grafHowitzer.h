#ifndef GRAFHOWITZER_H
#define GRAFHOWITZER_H

#include <QGraphicsItem>

class grafHowitzer
{
public:
    grafHowitzer(int px, int py, double tilt, bool spin);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void Actualizar(int px, int py, bool spin);
    void mejorar();

private:
    QPixmap howitzer = QPixmap(":/imagenes/howitz_0.png");


};

#endif // GRAFHOWITZER_H
