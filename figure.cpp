#include "iostream"
#include "math.h"
#include "figure.h"

Figure::Figure()
{
    this->commonConstruct();
    this->randomVerticeInput();
}

Figure::Figure(bool manual) {
    this->commonConstruct();

    if (manual) {
        this->manualVerticeInput();
    }else{
        this->randomVerticeInput();
    }
}

Figure::~Figure() {
    delete this->extremelyPoints;
    delete[] this->vertices;
}

void Figure::commonConstruct() {
    this->inputVerticeAmount();
    this->initProperties();
}

void Figure::randomVerticeInput() {
    for (int i = 0; i < this->verticeAmount; i++) {
        this->addVertice(this->genRandomVertice(), i);
    }
}

void Figure::manualVerticeInput() {
    for (int i = 0; i < this->verticeAmount; i++) {
        this->addVertice(this->getInputVertice(), i);
    }
}

float Figure::calcPerimeter() {
    this->showVertices();
    this->orientateVertices();
    this->orderVertices();
    this->showVertices();
    this->calcVerticeDistancesSum();

    return this->verticeDistancesSum;
}

void Figure::addVertice(Vertice* vert, int pos) {
    this->setVertice(vert, pos);
    this->extremelyPoints->takePoint(vert);
}

void Figure::orientateVertices() {
    for (int i = 0; i < this->verticeAmount; i++){
        if (this->vertices[i]->getY() <= this->extremelyPoints->leftBottom->getY()
                || this->vertices[i]->getY() <= this->extremelyPoints->rightBottom->getY()) {
            this->vertices[i]->isBottom = true;
        }
        if (this->vertices[i]->getX() <= this->extremelyPoints->bottomLeft->getY()
                || this->vertices[i]->getY() <= this->extremelyPoints->topLeft->getY()) {
            this->vertices[i]->isLeft = true;
        }
        if (this->vertices[i]->getY() >= this->extremelyPoints->leftTop->getY()
                || this->vertices[i]->getY() >= this->extremelyPoints->rightTop->getY()) {
            this->vertices[i]->isTop = true;
        }
        if (this->vertices[i]->getX() >= this->extremelyPoints->topRight->getX()
                || this->vertices[i]->getX() >= this->extremelyPoints->bottomRight->getX()) {
            this->vertices[i]->isRight = true;
        }
    }
}

void Figure::orderVertices() {
    for (int i = 0; i < this->verticeAmount - 1; i++){
        this->swapVertices(i+1, this->findNextPos(i));
    }
}

int Figure::findNextPos(int pos){
    int nextPos = pos+1;
    float delta = abs(this->vertices[pos]->getX()) + abs(this->vertices[pos]->getY());
    for (int j = pos + 1; j < this->verticeAmount - 1; j++){
        if (this->vertices[pos]->isBottom && this->vertices[j]->isBottom
                && this->vertices[pos]->getX() >= this->vertices[j]->getX()
                && (abs(this->vertices[pos]->getX() - this->vertices[j]->getX()) < delta)){
            nextPos = j;
            delta = abs(this->vertices[pos]->getX() - this->vertices[j]->getX());
        } else if (this->vertices[pos]->isLeft && this->vertices[j]->isLeft
               && this->vertices[pos]->getY() <= this->vertices[j]->getX()
               && (abs(this->vertices[pos]->getY() - this->vertices[j]->getY()) < delta)){
            nextPos = j;
            delta = abs(this->vertices[pos]->getY() - this->vertices[j]->getY());
        } else if (this->vertices[pos]->isTop && this->vertices[j]->isTop
               && this->vertices[pos]->getX() <= this->vertices[j]->getX()
               && (abs(this->vertices[pos]->getX() - this->vertices[j]->getX()) < delta)){
            nextPos = j;
            delta = abs(this->vertices[pos]->getX() - this->vertices[j]->getX());
        } else if (this->vertices[pos]->isRight && this->vertices[j]->isRight
               && this->vertices[pos]->getY() >= this->vertices[j]->getY()
               && (abs(this->vertices[pos]->getY() - this->vertices[j]->getY()) < delta)){
            nextPos = j;
            delta = abs(this->vertices[pos]->getY() - this->vertices[j]->getY());
        }
    }
    return nextPos;
}

void Figure::showVertices(){
    std::cout << "Vertices\n";
    for (int i = 0; i < this->verticeAmount; i++){
        this->showVertice(this->vertices[i]);
    }
    std::cout << std::endl;
}

void Figure::showVertice(Vertice* vert) {
    std::cout << "X: " << vert->getX() << " Y: " << vert->getY() << "\t";
}

void Figure::calcVerticeDistancesSum() {
    for (int i = 0; i < this->verticeAmount; i++) {
        if (i == this->verticeAmount - 1) {
            this->verticeDistancesSum += this->calcPointDistance(this->vertices[i], this->vertices[0]);
        }else {
            this->verticeDistancesSum += this->calcPointDistance(this->vertices[i], this->vertices[i + 1]);
        }
    }
}

float Figure::calcPointDistance(Point* p1, Point* p2) {
    return sqrt(pow(p1->getX() - p2->getX(), 2) + pow(p1->getY() - p2->getY(), 2));
}

void Figure::swapVertices(int pos1, int pos2){
    Vertice* tempV;
    tempV = this->vertices[pos1];
    this->vertices[pos1] = this->vertices[pos2];
    this->vertices[pos2] = tempV;
}


void Figure::inputVerticeAmount() {
    std::cout << "Input number of vertices:\n";
    std::cin >> this->verticeAmount;
}

void Figure::initProperties() {
    this->vertices = new Vertice*[this->verticeAmount];
    this->verticeDistancesSum = 0.0;
    this->extremelyPoints = new FigureExtremelyPoints();
}

Vertice* Figure::genRandomVertice() {
    return new Vertice(static_cast<float>(rand()), static_cast<float>(rand()));
}

Vertice* Figure::getInputVertice() {
    float tempX;
    float tempY;

    std::cout << "Input vertice coordinates\n";
    std::cout << "X:\t";
    std::cin >> tempX;
    std::cout << "Y:\t";
    std::cin >> tempY;

    return new Vertice(tempX, tempY);
}

void Figure::setVertice(Vertice* vert, int pos) {
    this->vertices[pos] = vert;
}
