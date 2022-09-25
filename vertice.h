#ifndef VERTICE_H
#define VERTICE_H

#include "point.h"

class Vertice : public Point
{
public:
    bool isBottom;
    bool isLeft;
    bool isTop;
    bool isRight;

    Vertice(float, float);
};

#endif // VERTICE_H
