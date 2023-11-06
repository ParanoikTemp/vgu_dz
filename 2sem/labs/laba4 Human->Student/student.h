#include "man.h"

class Student: public Man {
private:
    unsigned int* yearOfStudy;
public:
    /**
     * Конструтор студента
     * @param name - Имя студента
     * @param age - Возраст студента
     * @param sex - Пол студента
     * @param weight - Вес студента
     * @param year - год обучения студента
     */
    Student(string name, int age, bool sex, float weight, unsigned int year);
    /**
     * Конструтор копирования
     * @param other - Объект класса Student
     */
    Student(const Student &other);
    /**
     * Деструктор класса Student
     */
    ~Student() override;
    /**
     * Сеттер года обучения студента
     * @param year - год обучения студента
     */
    void setYearOfStudy(unsigned int year);
    /**
     * Оператор инкремента
     * @return возвращает текущий объект
     */
    Student& operator++();
    /**
     * Оператор сравнения
     * @param other - объект класса Student
     * @return возвращает текущий объект
     */
    Student& operator= (const Student &other);
    /**
     * Выводит в консоль объект
     */
    void print();
};
