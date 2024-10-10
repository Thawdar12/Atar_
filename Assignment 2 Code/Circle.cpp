
#include "Circle.h"

// declaring default constructor that inherits Shape2D
Circle::Circle() : ShapeTwoD(){
    this->radius = 0;
    this->coords[0].x = 0;
    this->coords[0].y = 0;
    area = 0;
}

// declaring constructor with variables that inherits Shape2D
Circle::Circle(string name, bool containsWarpSpace, coordinates *coords, int radius) :ShapeTwoD(name, containsWarpSpace) {
    this->coords[0] = coords[0];
    this->radius = radius;
    getMinMax(maxY,maxX,minY,minX);
    getSides(coords,radius);
    area = 0;
}

// declaring copy constructor
Circle::Circle(const Circle & cir) :ShapeTwoD(cir.name,cir.containsWarpSpace) {
    this->coords[0] = cir.coords[0];
    this->radius = cir.radius;
    this->maxX = cir.maxX;
    this->maxY = cir.maxY;
    this->minX = cir.minX;
    this->minY = cir.minY;
    area = 0;
}

// declaring to string method
string Circle::toString() {
    ostringstream oss;
    oss << "Name : " << name << endl;
    oss << "Special Type : " << getWarpSpace() << endl;
    oss << "Area : " << fixed << setprecision(2) << area << " units square\n";
    oss << "Vertices: \n";
    oss << "Center: " << coords[0].toString() << endl;

    oss << "Points on perimeter: ";
    for(int i = 0; i < 4; i++){
        if(i == 3){
            oss << ends[i].toString() << endl;
        }
        else{
            oss << ends[i].toString() << ", ";
        }
    }

    vector <coordinates> inshape;

    for(int y = minY; y <= maxY; y++){
        for(int x = minX; x <= maxX; x++){
            coordinates ins{};
            ins.x = x;
            ins.y = y;
            if(isPointInShape(x,y)){
                inshape.push_back(ins);
            }
        }
    }

    oss << "Points within shape: ";
    if(!inshape.empty()) {
        for (int i = 0; i < inshape.size(); i++) {
            if (i == inshape.size() - 1) {
                oss << inshape[i].toString() << endl;
            } else {
                oss << inshape[i].toString() << ", ";
            }
        }
    }
    else{
        oss << "None!" << endl;
    }
    return oss.str();
}

// compute area function
double Circle::computeArea() {
    return pi * radius * radius;
}

// checking if point is in shape
bool Circle::isPointInShape(int x, int y) {
    bool test = true;
    // check x and y distance to coords[0] and if it is bigger than radius return false.
    double distance = sqrt(pow((x-coords[0].x),2) + pow((y-coords[0].y),2));
    if(distance < radius){
        test = true;
    }
    else{
        test = false;
    }
    return test;
}

// checking if point is on shape
bool Circle::isPointOnShape(int x, int y) {
    bool test;
    double distance = sqrt(pow((x-coords[0].x),2) + pow((y-coords[0].y),2));
    if(distance == radius){
        test = true;
    }
    else{
        test = false;
    }
    return test;
}

void Circle::getMinMax(int & maxY, int & maxX, int & minY, int & minX) {
    minX = this->coords[0].x - this->radius;
    minY = this->coords[0].y - this->radius;
    maxX = this->coords[0].x + this->radius;
    maxY = this->coords[0].y + this->radius;
}

void Circle::getSides(coordinates coords[1], int radius){


    //top maxY
    ends[0].y = maxY;
    ends[0].x = coords[0].x;

    //right maxX
    ends[1].y = coords[0].y;
    ends[1].x = maxX;

    //bottom minY
    ends[2].y = minY;
    ends[2].x = coords[0].x;

    //left minX
    ends[3].y = coords[0].y;
    ends[3].x = minX;
}

Circle::~Circle() {

}

void Circle::setArea(double area) {
    this->area = area;
}
