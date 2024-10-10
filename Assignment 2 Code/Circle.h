#ifndef CIRCLE_H
#define CIRCLE_H
#include "ShapeTwoD.h"

class Circle : public ShapeTwoD{
private:
    int radius;
    double const pi = 3.14159265359;
    coordinates coords[1];
    coordinates ends[4];
    double area;
    int maxY,maxX,minY,minX;
public:
    Circle();
    Circle(string name, bool containsWarpSpace, coordinates coords[1], int radius);
    Circle(const Circle & cir);
    string toString() override;
    ~Circle();

    double computeArea() override;
    bool isPointInShape(int x, int y) override;
    bool isPointOnShape(int x, int y) override;
    void getMinMax(int & maxY, int & maxX, int & minY, int & minX);
    void getSides(coordinates coords[1], int radius);
    void setArea(double area);

};

#endif