#ifndef SHAPETWOD_H
#define SHAPETWOD_H

#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>
#include "iomanip"
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct coordinates{
    int x;
    int y;

    string toString();
};

class ShapeTwoD {
    private:
        static int countObj;

    protected:
        string name;
        bool containsWarpSpace;
        double area = 0;
        int countnum;

    public:
        ShapeTwoD();
        ShapeTwoD(string name, bool containsWarpSpace);
        ShapeTwoD(const ShapeTwoD & shape);
        ~ShapeTwoD();
        string getName();
        bool getContainsWarpSpace();
        virtual string toString();

        virtual void setArea(double area);
        virtual double computeArea();
        virtual bool isPointInShape(int x, int y);
        virtual bool isPointOnShape(int x, int y);

        int getCount();

        string getWarpSpace();

        void setName(string name);
        void setContainsWarpSpace(bool containsWarpSpace);

};

#endif