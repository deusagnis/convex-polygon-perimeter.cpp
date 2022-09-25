#include "figureextremelypoints.h"

FigureExtremelyPoints::FigureExtremelyPoints()
{
    this->bottomRight = nullptr;
    this->bottomLeft = nullptr;
    this->leftBottom = nullptr;
    this->leftTop = nullptr;
    this->topLeft = nullptr;
    this->topRight = nullptr;
    this->rightTop = nullptr;
    this->rightBottom = nullptr;
}

void FigureExtremelyPoints::takePoint(Point* p) {
    this->takeBottomRight(p);
    this->takeBottomLeft(p);
    this->takeLeftBottom(p);
    this->takeLeftTop(p);
    this->takeTopLeft(p);
    this->takeTopRight(p);
    this->takeRightTop(p);
    this->takeRightBottom(p);
}

void FigureExtremelyPoints::takeBottomRight(Point* p) {
    if (this->bottomRight == nullptr
            || p->getY() < this->bottomRight->getY()
            || (p->getY() == this->bottomRight->getY()
                && p->getX() > this->bottomRight->getX())
        ) {
        this->bottomRight = p;
    }
}

void FigureExtremelyPoints::takeBottomLeft(Point* p) {
    if (this->bottomLeft == nullptr
            || p->getY() < this->bottomRight->getY()
            || (p->getY() == this->bottomLeft->getY()
                && p->getX() < this->bottomLeft->getX())
        ) {
        this->bottomLeft = p;
    }
}

void FigureExtremelyPoints::takeLeftBottom(Point* p) {
    if (this->leftBottom == nullptr
            || p->getX() < this->leftBottom->getX()
            || (p->getX() == this->leftBottom->getX()
                && p->getY() < this->leftBottom->getY())
        ) {
        this->leftBottom = p;
    }
}

void FigureExtremelyPoints::takeLeftTop(Point* p) {
    if (this->leftTop == nullptr
            || p->getX() < this->leftTop->getX()
            || (p->getX() == this->leftTop->getX()
                && p->getY() > this->leftTop->getY())
        ) {
        this->leftTop = p;
    }
}

void FigureExtremelyPoints::takeTopLeft(Point* p) {
    if (this->topLeft == nullptr
            || p->getY() > this->topLeft->getY()
            || (p->getY() == this->topLeft->getY()
                && p->getX() < this->topLeft->getX())
        ) {
        this->topLeft = p;
    }
}

void FigureExtremelyPoints::takeTopRight(Point* p) {
    if (this->topRight == nullptr
            || p->getY() > this->topRight->getY()
            || (p->getY() == this->topRight->getY()
                && p->getX() > this->topRight->getX())
        ) {
        this->topRight = p;
    }
}

void FigureExtremelyPoints::takeRightTop(Point* p) {
    if (this->rightTop == nullptr
            || p->getX() > this->rightTop->getX()
            || (p->getX() == this->rightTop->getX()
                && p->getY() > this->rightTop->getY())
        ) {
        this->rightTop = p;
    }
}

void FigureExtremelyPoints::takeRightBottom(Point* p) {
    if (this->rightBottom == nullptr
            || p->getX() > this->rightBottom->getX()
            || (p->getX() == this->rightBottom->getX()
                && p->getY() < this->rightBottom->getY())
        ) {
        this->rightBottom = p;
    }
}
