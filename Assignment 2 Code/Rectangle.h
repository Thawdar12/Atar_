#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "ShapeTwoD.h"

class Rectangle : public ShapeTwoD{
private:
    coordinates fourP [4]{};
    double area;
    int maxY,maxX,minY,minX;
public:
    Rectangle();
    Rectangle(string name, bool containsWarpSpace, coordinates fourP[4]);
    Rectangle(const Rectangle & rec);
    string toString() override;
    ~Rectangle();

    double computeArea() override;
    bool isPointInShape(int x, int y) override;
    bool isPointOnShape(int x, int y) override;
    void getMinMax(int & maxY, int & maxX, int & minY, int & minX);
    void setArea(double area);

};

#endif