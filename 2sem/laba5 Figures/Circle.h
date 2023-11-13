#pragma once
#include "Figure.h"

class Circle: public Figure {
private:
    double radius;
public:
    /**
     * Конструтор класса
     * @param r радиус круга
     */
    Circle(double r);
    /**
     * Конструктор копирования класса
     * @param c объект класса Circle
     */
    Circle(const Circle &c) = default;
    /**
     * Оператор присваивания
     * @param c объект класса Circle
     * @return Ссылку на себя
     */
    Circle& operator=(const Circle &c) = default;
    /**
     * Функция вычисления площади круга
     * @return площадь круга
     */
    double calcSquare() override;
    /**
     * Функция вычисления периметра круга
     * @return периметр круга
     */
    double calcPerimeter() override;
    /**
     * Деструктор класса
     */
    virtual ~Circle() = default;
};

