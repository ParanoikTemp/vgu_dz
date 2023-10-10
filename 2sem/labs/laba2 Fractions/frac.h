using namespace std;
#include <ostream>

/// <summary>
/// Класс дроби. Может быть как правильной, так и неправильной.
/// </summary>
class Frac {
private:
    int* num; /// <summary> Числитель дроби - целое число </summary>
    unsigned int* den; /// <summary> Знаменатель дроби - натуральное число </summary>

    void reduce();
public:
    /// <summary> Конструктор дроби. </summary> <returns> Дробь с значением 0/1 </returns>
    Frac();
    /// <summary> Конструктор дроби. </summary> 
    /// <param name="int numerator">: Целое число - числитель дроби </param> 
    /// <returns> Дробь с значением параметра. В знаменателе 1 </returns>
    Frac(int numerator);
    /// <summary> Конструктор дроби. </summary> 
    /// <param name="int numerator">: Целое число - числитель дроби </param> 
    /// <param name="unsigned int denominator">: натуральное чило - знаменатель дроби, если равен 0 устанавливается в 1 </param> 
    Frac(int numerator, unsigned int denominator);
    /// <summary> Конструктор копирования дроби. </summary> 
    Frac(const Frac& fr);
    /// <summary> Конструктор дроби. </summary> 
    /// <param name="double numerator">: Вещественное число </param> 
    /// <returns> Дробь равная вещ. числу </returns>
    Frac(double number);
    /// <summary> Конструктор дроби. </summary> 
    /// <param name="double numerator">: Вещественное число </param> 
    /// <returns> Дробь равная вещ. числу </returns>
    Frac(float number);
    /// <summary> Деструктор дроби. </summary> 
    ~Frac();

    /// <summary>
    /// Геттер числителя
    /// </summary>
    /// <returns>Значение числителя дроби</returns>
    int getNum();
    /// <summary>
    /// Геттер знаменатель
    /// </summary>
    /// <returns>Значение знаменателя дроби</returns>
    unsigned int getDen();
    /// <summary>
    /// Сеттер числителя дроби
    /// </summary>
    /// <param name="numerator">: Целое число - числитель дроби</param>
    void setNum(int numerator);
    /// <summary>
    /// Сеттер знаменателя дроби
    /// </summary>
    /// <param name="denominator"> натуральное число - знаменатель дроби </param>
    void setDen(unsigned int denominator);

    /// <summary>
    /// Сложение дроби с другой дробью
    /// </summary>
    /// <param name="other">Другая дробь</param>
    /// <returns>Новая дробь, равная сумме слагаемых</returns>
    Frac operator + (Frac const& other) const;
    /// <summary>
    /// Сложение дроби с целым числом
    /// </summary>
    /// <param name="other">Целое число</param>
    /// <returns>Новая дробь, равная сумме слагаемых</returns>
    Frac operator + (int const& other) const;
    /// <summary>
    /// Сложение дроби с вещ. числом двойной точности
    /// </summary>
    /// <param name="other">вещ. число</param>
    /// <returns>Новая дробь, равная сумме слагаемых</returns>
    Frac operator + (double const& other) const;
    /// <summary>
    /// Сложение дроби с вещ. числом
    /// </summary>
    /// <param name="other">вещ. число</param>
    /// <returns>Новая дробь, равная сумме слагаемых</returns>
    Frac operator + (float const& other) const;
    /// <summary>
    /// Вычитание из дроби другой дроби
    /// </summary>
    /// <param name="other">Другая дробь</param>
    /// <returns>Новая дробь, равная разности дробей</returns>
    Frac operator - (Frac const& other) const;
    /// <summary>
    /// Вычитание из дроби целого числа
    /// </summary>
    /// <param name="other">Целое число</param>
    /// <returns>Новая дробь, равная разности дробей</returns>
    Frac operator - (int const& other) const;
    Frac operator - (double const& other) const;
    Frac operator - (float const& other) const;
    Frac operator * (Frac const& other) const;
    Frac operator * (int const& other) const;
    Frac operator * (double const& other) const;
    Frac operator * (float const& other) const;
    Frac operator / (Frac const& other) const;
    Frac operator / (int const& other) const;
    Frac operator / (double const& other) const;
    Frac operator / (float const& other) const;

    bool operator == (Frac const& other) const;
    bool operator == (int const& other) const;
    bool operator == (float const& other) const;
    bool operator == (double const& other) const;
    bool operator != (Frac const& other) const;
    bool operator != (int const& other) const;
    bool operator != (float const& other) const;
    bool operator != (double const& other) const;
    bool operator > (Frac const& other) const;
    bool operator > (int const& other) const;
    bool operator > (float const& other) const;
    bool operator > (double const& other) const;
    bool operator >= (Frac const& other) const;
    bool operator >= (int const& other) const;
    bool operator >= (float const& other) const;
    bool operator >= (double const& other) const;
    bool operator < (Frac const& other) const;
    bool operator < (int const& other) const;
    bool operator < (float const& other) const;
    bool operator < (double const& other) const;
    bool operator <= (Frac const& other) const;
    bool operator <= (int const& other) const;
    bool operator <= (float const& other) const;
    bool operator <= (double const& other) const;

    Frac& operator = (Frac const& other);
    Frac& operator = (int const& other);
    Frac& operator = (double const& other);
    Frac& operator = (float const& other);
    Frac& operator += (Frac const& other);
    Frac& operator += (int const& other);
    Frac& operator += (double const& other);
    Frac& operator += (float const& other);
    Frac& operator -= (Frac const& other);
    Frac& operator -= (int const& other);
    Frac& operator -= (double const& other);
    Frac& operator -= (float const& other);
    Frac& operator *= (Frac const& other);
    Frac& operator *= (int const& other);
    Frac& operator *= (double const& other);
    Frac& operator *= (float const& other);
    Frac& operator /= (Frac const& other);
    Frac& operator /= (int const& other);
    Frac& operator /= (double const& other);
    Frac& operator /= (float const& other);

    friend ostream& operator << (ostream& stream, const Frac& frac);
    friend istream& operator >> (istream& stream, Frac& frac);

    void print();
};
