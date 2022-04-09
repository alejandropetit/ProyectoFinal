#include "wall.h"

wall::wall(int px, int py, int width, int height, double tilt , bool bounce)
{
    pared = new grafWall(px, py, width, height, tilt, bounce);
}
