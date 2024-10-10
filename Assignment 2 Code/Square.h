#ifndef SQUARE_H
#define SQUARE_H
#include "ShapeTwoD.h"

class Square : public ShapeTwoD{
private:
    coordinates fourP [4]{};
    double area;
    int maxY,maxX,minY,minX;
public:
    Square();
    Square(string name, bool containsWarpSpace, coordinates fourP[4]);
    Square(const Square & sq);
    ~Square();
    string toString() override;

    double computeArea() override;
    bool isPointInShape(int x, int y) override;
    bool isPointOnShape(int x, int y) override;
    void getMinMax(int & maxY, int & maxX, int & minY, int & minX);
    void setArea(double area);
};

#endif