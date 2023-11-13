#pragma once
#include "Figure.h"

class Trapezium: public Figure {
private:
    double sideA, sideB, height;
public:
    /**
     * Конструктор классa
     * @param sideA верхнее основание трапеции
     * @param sideB нижнее основание трапеции
     * @param height высота трапеции
     */
    Trapezium(double sideA, double sideB, double height);
    /**
     * Конструктор копирования класса
     * @param r Объект класса Trapezium
     */
    Trapezium(const Trapezium &r) = default;
    /**
     * Оператор присваивания
     * @param r объект класса Trapezium
     * @return Ссылку на себя
     */
    Trapezium& operator=(const Trapezium &r) = default;
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
    virtual ~Trapezium() = default;
};
