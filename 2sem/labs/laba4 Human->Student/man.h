#include <string>
#include <iostream>

using namespace std;

class Man {
protected:
    string* name;
    int* age;
    bool* sex;
    float* weight;
public:
    /**
     * Базовый конструктор класса Man
     * @param name - Имя человека
     * @param age - Возраст человека
     * @param sex - Пол человека (1 - мужчина, 0 - женщина)
     * @param weight - вес человека
     */
    Man(string name, int age, bool sex, float weight);
    /**
     * Конструктор копирования класса Man
     * @param other - Другой объект класса Man
     */
    Man(const Man &other);
    /**
     * Деструктор класса Man
     */
    virtual ~Man();
    /**
     * Сеттер имени человека
     * @param name - имя человека
     */
    void setName(string name);
    /**
     * Сеттер возраста человека
     * @param age - возраст человека
     */
    void setAge(int age);
    /**
     * Сеттер пола человека (ну мало ли =D )
     * @param sex - пол человека
     */
    void setSex(bool sex);
    /**
     * Сеттер веса человека
     * @param weight - вес человека
     */
    void setWeight(float weight);
    /**
     * Оператор присваивания
     * @param other - объект класса Man
     * @return возвращает текущий объект
     */
    Man& operator= (const Man &other);
};
