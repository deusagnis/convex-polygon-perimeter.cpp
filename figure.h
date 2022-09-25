#ifndef FIGURE_H
#define FIGURE_H

#include "vertice.h"
#include "figureextremelypoints.h"

class Figure
{
public:
    Figure();
    Figure(bool);
    ~Figure();
    float calcPerimeter();
private:
    int verticeAmount;
    Vertice** vertices;
    float verticeDistancesSum;
    FigureExtremelyPoints* extremelyPoints;

    void commonConstruct();

    void inputVerticeAmount();
    void initProperties();
    void manualVerticeInput();
    void randomVerticeInput();
    void calcVerticeDistancesSum();

    void orientateVertices();
    void orderVertices();
    void showVertices();

    Vertice* getInputVertice();
    Vertice* genRandomVertice();
    void addVertice(Vertice*, int);
    int findNextPos(int);
    float calcPointDistance(Point*, Point*);
    void swapVertices(int, int);
    void showVertice(Vertice*);

    void setVertice(Vertice*, int);
};

#endif // FIGURE_H
