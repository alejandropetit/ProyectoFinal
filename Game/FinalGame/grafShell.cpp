#include "grafShell.h"

grafShell::grafShell(int px, int py, double tilt, bool spin)
{
    kugeln.load(":/images/shell.png");
    setPixmap(kugeln.scaled(7,8));
    this->setPos(200,200);
}
