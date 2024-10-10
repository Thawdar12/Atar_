
#include "Cross.h"

// declaring default constructor that inherits Shape2D
Cross::Cross() :ShapeTwoD() {
    for(int i = 0; i < 12; i++){
        this->twelveP[i].x = 0;
        this->twelveP[i].y = 0;
    }
    area = 0;
    maxY = maxX = minY = minX = 0;
}

// declaring constructor with variables that inherits Shape2D
Cross::Cross(string name, bool containsWarpSpace, coordinates *twelveP) : ShapeTwoD(name,containsWarpSpace){
    for(int i = 0; i < 12; i++){
        this->twelveP[i] = twelveP[i];
    }
    area = 0;
    // get min max val from array of coords
    // construct 2d array of size max-min for x and y

    for(int i = 0; i < 12; i ++){
        if(i == 0){
            maxY = minY = twelveP[i].y;
            maxX = minX = twelveP[i].x;
        }
        else{
            if(twelveP[i].x < minX){
                minX = twelveP[i].x;
            }
            if(twelveP[i].x > maxX){
                maxX = twelveP[i].x;
            }
            if(twelveP[i].y < minY){
                minY = twelveP[i].y;
            }
            if(twelveP[i].y > maxY){
                maxY = twelveP[i].y;
            }
        }
    }
    // creating a 2d array
    crossArrayUse = new int * [maxY-minY+1];
    for(int i = 0; i <= (maxY-minY+1); i ++){
        crossArrayUse[i] = new int [maxX-minX+1];
    }

    // -1 is outside the cross
    // 0 is on the cross
    // 1 is in the cross
    // 2 is the given vertex
    for(int y = 0; y <= (maxY-minY);y++){
        for(int x = 0; x <= (maxX-minX);x++){
            crossArrayUse[y][x] = -1;
        }
    }
    // setting a default value for the 2d array
    for(int i = 0; i < 12; i++){
        crossArrayUse[twelveP[i].y-minY][twelveP[i].x-minX] = 2;
    }

    // setting border to 0
    for(int i = 0; i <12; i++){
        int val;
        if(i == 11){
            val = 0;
        }
        else{
            val = i+1;
        }

        // finding all the values that are either in max x, min x, max y, min y and setting them to 0
        if(twelveP[i].x-minX == twelveP[val].x-minX){
            if(twelveP[i].y-minY < twelveP[val].y-minY){
                for(int y = twelveP[i].y+1; y < twelveP[val].y; y++){
                    crossArrayUse[y-minY][twelveP[i].x-minX] = 0;
                    }
            }
            else if(twelveP[i].y-minY > twelveP[val].y-minY){
                for(int y = twelveP[val].y+1; y < twelveP[i].y; y++){
                    crossArrayUse[y-minY][twelveP[i].x-minX] = 0;
                }
            }
        }

        if(twelveP[i].y-minY == twelveP[val].y-minY){
            if(twelveP[i].x-minX < twelveP[val].x-minX){
                for(int x = twelveP[i].x+1; x < twelveP[val].x; x++){
                    crossArrayUse[twelveP[i].y-minY][x-minX] = 0;
                }
            }
            else if(twelveP[i].x-minX > twelveP[val].x-minX){
                for(int x = twelveP[val].x+1; x < twelveP[i].x; x++){
                    crossArrayUse[twelveP[i].y-minY][x-minX] = 0;
                }
            }
        }



    }
    //setting inside to 1
    for(int y = 0;y <= (maxY-minY);y++){
        int start = 0;
        int done = 0;
        for(int x = 0;x <= (maxX-minX);x++){
            if(x<=(maxX-minX-1)){
                if((crossArrayUse[y][x] == 0 || crossArrayUse[y][x] == 2) && crossArrayUse[y][x+1] == -1 && (y != maxY-minY && y != 0)){
                    start = 1;
                }
                if(start == 1 && (crossArrayUse[y][x+1] == 0 || crossArrayUse[y][x+1] == 2)&& crossArrayUse[y][x] == -1){
                    crossArrayUse[y][x] = 1;
                    start = 0;
                    done = 1;
                }
            }

            if(start == 1 && crossArrayUse[y][x] == -1 && done == 0  && x != maxX-minX){
                crossArrayUse[y][x] = 1;
            }
        }
    }
}

Cross::Cross(const Cross & cross) : ShapeTwoD(cross.name,cross.containsWarpSpace){
    for(int i = 0; i < 4; i++){
        this->twelveP[i] = cross.twelveP[i];
    }
    this->maxY = cross.maxY;
    this->maxX = cross.maxX;
    this->minY = cross.minY;
    this->minX = cross.minX;
    this->crossArrayUse = cross.crossArrayUse;
    area = 0;

}

Cross::~Cross() {
    for(int i = 0; i < maxY; i ++){
        delete [] crossArrayUse[i];
    }
    delete [] crossArrayUse;
}

string Cross::toString() {
    // displaying of coordinates needs to + the minX and minY respectively
    ostringstream oss;
    oss << "Name : " << name << endl;
    oss << "Special Type : " << getWarpSpace() << endl;
    oss << "Area : " << area << " units square\n";
    oss << "Vertices: \n";
    for(int i = 0; i < 12; i++){
        oss << "Point [" << i << "] : " << twelveP[i].toString() << endl;
    }
    // -1 is outside the cross
    // 0 is on the cross
    // 1 is in the cross
    vector<coordinates>onshape;
    vector<coordinates>inshape;
    for(int y = 0;y <= (maxY-minY);y++){
        for(int x = 0;x <= (maxX-minX);x++) {
            coordinates ons{};
            ons.x = x+minX;
            ons.y = y+minY;
            if(crossArrayUse[y][x] == 0){
                onshape.push_back(ons);
            }
            else if(crossArrayUse[y][x] == 1){
                inshape.push_back(ons);
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
    else{
        oss << "None!" << endl;
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
    else {
        oss << "None!" << endl;
    }
    return oss.str();
}

// compute area function
double Cross::computeArea() {
     int counter, area;
    counter = area = 0;
    area = (maxY-minY)*(maxX-minX);
    for(int y = 0; y <= (maxY-minY); y++){
        for(int x = 0; x <= (maxX-minX); x++){
            if(crossArrayUse[y][x] == -1){
                counter++;
            }
        }
    }
    area -= counter;
    return area;
}

// function to test if point is in shape
bool Cross::isPointInShape(int x, int y) {
    bool test;
    if(crossArrayUse[y][x] == 1){
        test = true;
    }
    else{
        test = false;
    }
    return test;
}

// function to test if point is on shape
bool Cross::isPointOnShape(int x, int y) {
    bool test;
    if(crossArrayUse[y][x] == 0 ){
        test = true;
    }
    else{
        test = false;
    }
    return test;
}

void Cross::setArea(double area) {
    this->area = area;
}


