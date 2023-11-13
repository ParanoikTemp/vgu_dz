#pragma once
#include <iostream>


class Figure {
public:
    /**
     * Конструктор класса
     */
    Figure() = default;
    /**
     * Конструктор копирования класса
     * @param figure Объект класса Figure
     */
    Figure(const Figure &figure) = default;
    /**
     * Деструктор класса
     */
    virtual ~Figure() = default;
    /**
     * Оператор присваивания
     * @param figure Объект класса Figure
     * @return Ссылку на себя
     */
    virtual Figure& operator=(const Figure &figure) = default;
    /**
     * Функция вычисления площади фигуры
     * @return площадь фигуры
     */
    virtual double calcSquare() {return 0;}
    /**
     * Функция вычисления периметра фигуры
     * @return периметр фигуры
     */
    virtual double calcPerimeter() {return 0;}
};
