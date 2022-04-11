#ifndef GRAFHOWITZER_H
#define GRAFHOWITZER_H

#include <QGraphicsItem>

class grafHowitzer
{
public:
    grafHowitzer(int px, int py, double tilt, bool spin);

    void Actualizar(int px, int py, bool spin);


};

#endif // GRAFHOWITZER_H
