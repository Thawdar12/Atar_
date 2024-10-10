#include "Square.h"
// default constructor that inhrits shape2d
Square::Square() : ShapeTwoD() {
    for(int i = 0; i < 4; i++){
        this->fourP[i].x = 0;
        this->fourP[i].y = 0;
    }
    area = 0;
    maxY = maxX = minY = minX = 0;

}

// constructor with variables that inherits shape2d
Square::Square(string name, bool containsWarpSpace, coordinates *fourP) : ShapeTwoD(name,containsWarpSpace){
    for(int i = 0; i < 4; i++){
        this->fourP[i] = fourP[i];
    }
    area = 0;
    getMinMax(maxY,maxX,minY,minX);
}

// copy constructor
Square::Square(const Square &sq) : ShapeTwoD(sq.name,sq.containsWarpSpace) {
    for(int i = 0; i < 4; i++){
        this->fourP[i] = sq.fourP[i];
    }

    this->maxY = sq.maxY;
    this->maxX = sq.maxX;
    this->minY = sq.minY;
    this->minX = sq.minX;
    area = 0;
}

// to string method
string Square::toString() {

    ostringstream oss;
    oss << "Name : " << name << endl;
    oss << "Special Type : " << getWarpSpace() << endl;
    oss << "Area : " << area << " units square\n";
    oss << "Vertices: \n";
    for(int i = 0; i < 4; i++){
        oss << "Point [" << i << "] : " << fourP[i].toString() << endl;
    }


    vector <coordinates> onshape;
    for(int y = minY; y <= maxY; y++){
        for(int x = minX; x <= maxX; x++){
            coordinates ins{};
            ins.x = x;
            ins.y = y;
            if(isPointOnShape(x,y)){
                onshape.push_back(ins);
            }
        }
    }
    oss << "Points on perimeter: ";
    if(!onshape.empty()) {
        for (int i = 0; i < onshape.size(); i++) {
            if (i == onshape.size() - 1) {
                oss << onshape[i].toString() << endl;
            } else {
                oss << onshape[i].toString() << ", ";
            }
        }
    }
    else {
        oss << "None!" << endl;
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
double Square::computeArea() {
    double height,length,area;
    for(int i = 0; i < 4;i++){
        for(int o = 0; o < 4;o++) {
            if(fourP[i].x == fourP[o].x && i != o && fourP[i].y > fourP[o].y){
                height = fourP[i].y-fourP[o].y;
            }
            else if(fourP[i].y == fourP[o].y && i != o && fourP[i].x > fourP[o].x){
                length = fourP[i].x-fourP[o].x;
            }
        }
    }
    area = double(length) * double(height);
    return area;
}

// function to test if point is in shape
bool Square::isPointInShape(int x, int y) {
    bool test = true;
    if(minY < y && maxY > y && minX < x && maxX > x){
        test = true;
    }
    else{
        test = false;
    }

    return test;
}

// function to test if point is on shape
bool Square::isPointOnShape(int x, int y) {
    bool test;
    if((minY == y || maxY == y) && (minX < x && maxX > x)){
        test = true;
    }
    else if((minY < y && maxY > y) && (minX == x || maxX == x)){
        test = true;
    }
    else{
        test = false;
    }
    return test;
}

// getting the min and max value for x and y
void Square::getMinMax(int & maxY, int & maxX, int & minY, int & minX) {
    for(int i = 0; i < 4; i ++){
        if(i == 1){
            maxY = minY = fourP[i].y;
            maxX = minX = fourP[i].x;
        }
        else{
            if(fourP[i].x > maxX){
                maxX = fourP[i].x;
            }
            if(fourP[i].y > maxY){
                maxY = fourP[i].y;
            }

            if(fourP[i].x < minX){
                minX = fourP[i].x;
            }
            if(fourP[i].y < minY){
                minY = fourP[i].y;
            }
        }
    }
}

// destructor
Square::~Square() {

}

// setter
void Square::setArea(double area) {
    this->area = area;
}




