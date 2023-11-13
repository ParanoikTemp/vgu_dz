#pragma once
#include "Figure.h"

class Rectangle: public Figure {
private:
    double sideA, sideB;
public:
    /**
     * Конструктор класса
     * @param sideA первая сторона прямоугольника
     * @param sideB вторая сторона прямоугольника
     */
    Rectangle(double sideA, double sideB);
    /**
     * Конструктор копирования класса
     * @param r Объект класса Rectangle
     */
    Rectangle(const Rectangle &r) = default;
    /**
     * Оператор присваивания
     * @param r объект класса Rectangle
     * @return Ссылку на себя
     */
    Rectangle& operator=(const Rectangle &r) = default;
    /**
     * Функция вычисления площади фигуры
     * @return площадь фигуры
     */
    double calcSquare() override;
    /**
     * Функция вычисления периметра фигуры
     * @return периметр фигуры
     */
    double calcPerimeter() override;
    /**
     * Деструктор класса
     */
    virtual ~Rectangle() = default;
};
