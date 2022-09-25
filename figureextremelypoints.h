#ifndef FIGUREEXTREMELYPOINTS_H
#define FIGUREEXTREMELYPOINTS_H

#include "point.h"


class FigureExtremelyPoints
{
public:
    FigureExtremelyPoints();

    Point* bottomRight;
    Point* bottomLeft;
    Point* leftBottom;
    Point* leftTop;
    Point* topLeft;
    Point* topRight;
    Point* rightTop;
    Point* rightBottom;

    void takePoint(Point*);
private:
    void takeBottomRight(Point*);
    void takeBottomLeft(Point*);
    void takeLeftBottom(Point*);
    void takeLeftTop(Point*);
    void takeTopLeft(Point*);
    void takeTopRight(Point*);
    void takeRightTop(Point*);
    void takeRightBottom(Point*);
};

#endif // FIGUREEXTREMELYPOINTS_H
