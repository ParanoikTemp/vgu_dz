#include "Rectangle.h"

Rectangle::Rectangle(double sideA, double sideB) {
    this->sideA = sideA;
    this->sideB = sideB;
}

double Rectangle::calcSquare() {
    return sideA * sideB;
}

double Rectangle::calcPerimeter() {
    return (sideA + sideB) * 2;
}
