#include "ShapeTwoD.h"

// default constructor
ShapeTwoD::ShapeTwoD(){
    this->name = "";
    this->containsWarpSpace = true;
    countnum = countObj++;
    area = 0;
}

// copy constructor
ShapeTwoD::ShapeTwoD(const ShapeTwoD & shape){
    this->name = shape.name;
    this->containsWarpSpace = shape.containsWarpSpace;
    countnum = countObj++;
    area = 0;
}

// constructor with variables
ShapeTwoD::ShapeTwoD(string name, bool containsWarpSpace){
    this->name = name;
    this->containsWarpSpace = containsWarpSpace;
    countnum = countObj++;
    area = 0;
}

// destructor
ShapeTwoD::~ShapeTwoD() {
--countObj;

}

// getter
string ShapeTwoD::getName(){
    return this->name;
}

// getter
bool ShapeTwoD::getContainsWarpSpace(){
    return this->containsWarpSpace;
}

// getter
int ShapeTwoD::getCount(){
    return this->countnum;
}

// to string method
string ShapeTwoD::toString(){
    ostringstream oos;
    oos << "";

    return oos.str();
}

// declaring function
double ShapeTwoD::computeArea(){
    return area;
}

// declaring function
bool ShapeTwoD::isPointInShape(int x, int y){
    bool check;
    return check;
}

// declaring function
bool ShapeTwoD::isPointOnShape(int x, int y){
    bool check;
    return check;
}

// setter
void ShapeTwoD::setName(string name){
    this->name = name;
}

// setter
void ShapeTwoD::setContainsWarpSpace(bool containsWarpSpace){
    this->containsWarpSpace = containsWarpSpace;
}

// setter
void ShapeTwoD::setArea(double area) {
    this->area = area;
}

// getter
string ShapeTwoD::getWarpSpace() {
    string ws = (this->containsWarpSpace) ? "WS" : "NS";
    return ws;
}

// declaring to string method
string coordinates::toString() {
    ostringstream oss;
    oss << "(" << x << ", " << y << ")";
    return oss.str();
}

// declaring a static variable for counting of the number of shape2d created
int ShapeTwoD::countObj;
