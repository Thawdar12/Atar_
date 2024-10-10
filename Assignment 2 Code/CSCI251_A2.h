
#include "Square.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Cross.h"
#include "ShapeTwoD.h"

void menu();
void sortMenu();
void shapes(string shape, bool type, vector<ShapeTwoD*> & all);
bool spaceToBool(string type);
bool areaAsc(ShapeTwoD * & one, ShapeTwoD * & two);
bool areaDsc(ShapeTwoD * & one, ShapeTwoD * & two);
void pause();