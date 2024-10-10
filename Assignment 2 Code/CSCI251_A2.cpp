// starting of the main
// remember to uncomment the line below

#include "CSCI251_A2.h"

int main() {
    string choice;
    string shape;
    string spaceType;
    vector <ShapeTwoD*> allSpace;
    vector <ShapeTwoD*> normalSpace;
    vector <ShapeTwoD*> warpedSpace;
    vector <double> allArea;
    while (true) {
        try {
            menu();
            cin >> choice;
            if (choice == "q") {
                allSpace.clear();
                warpedSpace.clear();
                normalSpace.clear();
                break;
            }
            else if(choice == "c"){
                allSpace.clear();
                warpedSpace.clear();
                normalSpace.clear();
            }
            else if (choice == "1") {
                cout << "[ Input Sensor Data ]" << endl;
                cout << "Please Enter Name Of Shape: ";
                cin >> shape;
                cout << "Please Enter Special Type: ";
                cin >> spaceType;
                shapes(shape, spaceToBool(spaceType), allSpace);

            }
            else if (choice == "2") {
                allArea.clear();
                for(ShapeTwoD * i : allSpace){
                    i->setArea(i->computeArea());
                }
                cout << "Computation completed!!  ( " << allSpace.size() << " records updated )" << endl;
            }
            else if (choice == "3") {
                if (allSpace.empty()) {
                    cout << "No Records to be shown" << endl;
                }
                else {
                    int counter = 0;
                    cout << "Total no. of records available = " << allSpace.size() << endl;
                    for (ShapeTwoD *i: allSpace) {
                        cout << "Shape [" << counter << "]" << endl;
                        cout << i->toString() << endl;
                        counter++;
                    }
                }
            }
            else if (choice == "4") {
                string sortOption;
                while(true){
                    sortMenu();
                    cin >> sortOption;
                    if(sortOption == "q"){
                        break;
                    }
                    else if(sortOption == "a"){
                        sort(allSpace.begin(),allSpace.end(), areaAsc);
                        for(ShapeTwoD * i : allSpace){
                            cout << "Shape [" << i->getCount() << "]\n";
                            cout << i->toString() << endl;
                        }
                    }
                    else if(sortOption == "b"){
                        sort(allSpace.begin(),allSpace.end(), areaDsc);
                        for(ShapeTwoD * i : allSpace){
                            cout << "Shape [" << i->getCount() << "]\n";
                            cout << i->toString() << endl;
                        }
                    }
                    else if(sortOption == "c"){
                        for(ShapeTwoD * i : allSpace){
                            if(i->getContainsWarpSpace()) {
                                cout << "Shape [" << i->getCount() << "]\n";
                                cout << i->toString() << endl;
                            }
                        }
                        for(ShapeTwoD * i : allSpace){
                            if(!i->getContainsWarpSpace()) {
                                cout << "Shape [" << i->getCount() << "]\n";
                                cout << i->toString() << endl;
                            }
                        }
                    }
                    else{
                        continue;
                    }
                    pause();
                }


            }
            else {
                continue;
            }
            pause();
        }

        catch (int excp) {
            if (excp == 1000) {
                cout << "Error in Shape name!\nPlease Try Again!\n";
                break;
            }
            else if(excp == 1001){
                cout << "error";
                break;
            }
            else{
                break;
            }
        }
    }
}

void pause(){
    cout << "Press <enter> to go back to main menu ...";
    cin.ignore(10, '\n');
    cin.get();
}

bool areaAsc(ShapeTwoD * & one, ShapeTwoD * & two){
    return (one->computeArea() < two->computeArea());
}

bool areaDsc(ShapeTwoD * & one, ShapeTwoD * & two){
    return (one->computeArea() > two->computeArea());
}

void shapes(string shape, bool spaceType, vector<ShapeTwoD*> & allSpace){
    int x,y;
    if(shape == "Cross"){
        coordinates cr[12];
        for(int i = 0; i < 12; i ++){
            cout << "Please Enter x-ordinate of pt." << i << ": ";
            cin >> x;
            cout << "Please Enter y-ordinate of pt." << i << ": ";
            cin >> y;
            cr[i].x=x;
            cr[i].y=y;
        }
        allSpace.push_back(new Cross(shape,spaceType,cr));
    }
    else if(shape == "Square"){
        coordinates sq[4];
        for(int i = 0; i < 4; i ++){
            cout << "Please Enter x-ordinate of pt." << i << ": ";
            cin >> x;
            cout << "Please Enter y-ordinate of pt." << i << ": ";
            cin >> y;
            sq[i].x=x;
            sq[i].y=y;
        }
        allSpace.push_back(new Square(shape, spaceType,sq));

    }
    else if(shape == "Rectangle"){
        coordinates rec[4];
        for(int i = 0; i < 4; i ++){
            cout << "Please Enter x-ordinate of pt." << i << ": ";
            cin >> x;
            cout << "Please Enter y-ordinate of pt." << i << ": ";
            cin >> y;
            rec[i].x=x;
            rec[i].y=y;
        }
        allSpace.push_back(new Rectangle(shape, spaceType,rec));
    }
    else if(shape == "Circle"){
        int radius;
        coordinates coords[1];
        cout << "Please Enter x-ordinate of center: ";
        cin >> x;
        cout << "Please Enter y-ordinate of center: ";
        cin >> y;
        cout << "Please Enter radius (units): ";
        cin >> radius;
        coords[0].x = x;
        coords[0].y = y;
        allSpace.push_back(new Circle(shape,spaceType,coords,radius));
    }
    else{
        throw 1000;
    }

}

bool spaceToBool(string spaceType){
    bool test = false;
    if(spaceType == "WS"){
        test = true;
    }
    else if(spaceType == "NS"){
        test = false;
    }
    return test;
}

void menu(){
	string stdnum = "";
	string name = "";
	cout << setw(20) << left << "Student ID" << " : " << stdnum << endl;
	cout << setw(20) << left << "Student Name" << " : " << name << endl;
	cout << string(40,'-') << endl;
	cout << "Welcome to Assn 2 program!" << endl;
	cout << setw(10) << left << "1)" << "Input sensor data" << endl;
	cout << setw(10) << left << "2)" << "Compute area (for all records)" << endl;
	cout << setw(10) << left << "3)" << "Print shapes report" << endl;
	cout << setw(10) << left << "4)" << "Sort shape data" << endl;
    cout << setw(10) << left << "c)" << "Press c to clear all current data" << endl;
	cout << setw(10) << left << "q)" << "Press q to Quit" << endl;
    cout << string(40,'-') << endl;
	cout << endl << "Please Enter Your Choice: ";
}

void sortMenu(){
    cout << string(40,'-') << endl;
	cout << setw(6) << left << " " << "a)" << setw(6) << "Sort by area (Ascending)" << endl;
	cout << setw(6) << left << " " << "b)" << setw(6) << "Sort by area (descending)" << endl;
	cout << setw(6) << left << " " << "c)" << setw(6) << "Sort by special type and area" << endl;
    cout << string(40,'-') << endl;
	cout << "Please select sort option ('q' to go main menu) :";
}
