#include "vertice.h"

Vertice::Vertice(float X, float Y): Point(X, Y) {
    this->isBottom = false;
    this->isLeft = false;
    this->isTop = false;
    this->isRight = false;
}
