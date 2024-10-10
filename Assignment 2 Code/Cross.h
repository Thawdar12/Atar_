
#ifndef CROSS_H
#define CROSS_H
#include "ShapeTwoD.h"

class Cross : public ShapeTwoD{
private:
    coordinates twelveP [12];
    int maxY, maxX, minY, minX;
    int ** crossArrayUse;
    double area;
public:
    Cross();
    Cross(string name, bool containsWarpSpace, coordinates twelveP [12]);
    Cross(const Cross & cross);
    string toString() override;
    ~Cross();

    double computeArea() override;
    bool isPointInShape(int x, int y) override;
    bool isPointOnShape(int x, int y) override;
    void setArea(double area);

};

#endif