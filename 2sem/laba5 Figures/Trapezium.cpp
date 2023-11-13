#include "Trapezium.h"
#include <cmath>

Trapezium::Trapezium(double sideA, double sideB, double height) {
    this->sideA = sideA;
    this->sideB = sideB;
    this->height = height;
}

double Trapezium::calcSquare() {
    return (sideB + sideA) * height / 2;
}

double Trapezium::calcPerimeter() {
    double side = sqrt(abs(sideB - sideA) / 2 + height * height);
    return side * 2 + sideA + sideB;
}
