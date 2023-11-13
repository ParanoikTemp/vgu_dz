#include "Circle.h"
#define PI 3.1415926535

double Circle::calcSquare() {
    return radius * radius * PI;
}

double Circle::calcPerimeter() {
    return 2 * radius * PI;
}

Circle::Circle(double r) {
    radius = r;
}
