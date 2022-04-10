#ifndef WALL_H
#define WALL_H

#include "grafWall.h"

class wall
{
public:
    wall(int px, int py, int width, int height, double tilt , bool bounce);
    void Actualizar();

private:
    grafWall *pared;
};

#endif // WALL_H
