#ifndef BORDERS_H
#define BORDERS_H

#include "point.h"

class Borders
{
public:
    Borders();
    void takePoint(Point *);
    float getLeft();
    float getTop();
    float getRight();
    float getBottom();
private:
    float left, top, right, bottom;
};

#endif // BORDERS_H
