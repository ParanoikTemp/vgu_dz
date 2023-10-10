#include "frac.h"
#include <iostream>
#include <cmath>
#define EPS 1e-9

void Frac::reduce() {
    int number = min(abs(*num), int(*den));
    if (number == 0) return;
    if (max(abs(*num), int(*den)) % number == 0) {
        *num /= number;
        *den /= number;
        return;
    }
    else {
        for (int n = number / 2; n > 1; --n) {
            if ((*num) % n == 0 && (*den) % n == 0)
            {
                *num /= n;
                *den /= n;
                return;
            }
        }
        return;
    }
}

Frac::Frac() {
    num = new int(0);
    den = new unsigned int(1);
}

Frac::Frac(int numerator) {
    num = new int(numerator);
    den = new unsigned int(1);
}

Frac::Frac(int numerator, unsigned int denominator) {
    den = new unsigned int(denominator ? denominator : 1);
    num = new int(numerator);
    this->reduce();
}

Frac::Frac(double number) {
    den = new unsigned int(1);
    while (abs(number - round(number)) > EPS && *den < 1e8) {
        *den *= 10;
        number *= 10;
    }
    num = new int((int) number);
    this->reduce();
}

Frac::Frac(float number) {
    den = new unsigned int(1);
    while (abs(number - round(number)) > EPS && *den < 1e8) {
        *den *= 10;
        number *= 10;
    }
    num = new int((int) number);
    this->reduce();
}

Frac::Frac(const Frac& fr) {
    num = new int(*(fr.num));
    den = new unsigned int(*(fr.den));
}

Frac::~Frac() {
    num = nullptr;
    den = nullptr;
    delete num, den;
}

void Frac::print() {
    std::cout << *num << '/' << *den;
}

int Frac::getNum() {
    return *num;
}

unsigned int Frac::getDen() {
    return *den;
}

void Frac::setNum(int numerator) {
    *num = numerator;
    this->reduce();
}

void Frac::setDen(unsigned int denominator) {
    *den = denominator;
    this->reduce();
}

Frac Frac::operator + (Frac const& other) const {
    if (*den == *(other.den)) return Frac(*num + *(other.num), *den);
    else return Frac(*num * int(*(other.den)) + *(other.num) * int(*den), *den * *(other.den));
}
Frac Frac::operator + (int const& other) const { return *this + Frac(other); }
Frac Frac::operator + (double const& other) const { return *this + Frac(other); }
Frac Frac::operator + (float const& other) const { return *this + Frac(other); }

Frac Frac::operator - (Frac const& other) const {
    if (*den == *(other.den)) return Frac(*num - *(other.num), *den);
    else return Frac(*num * int(*(other.den)) - *(other.num) * int(*den), *den * *(other.den));
}
Frac Frac::operator - (int const& other) const { return *this - Frac(other); }
Frac Frac::operator - (double const& other) const { return *this - Frac(other); }
Frac Frac::operator - (float const& other) const { return *this - Frac(other); }

Frac Frac::operator * (Frac const& other) const {
    return Frac(*num * *(other.num), *den * *(other.den));
}
Frac Frac::operator * (int const& other) const { return *this * Frac(other); }
Frac Frac::operator * (double const& other) const { return *this * Frac(other); }
Frac Frac::operator * (float const& other) const { return *this * Frac(other); }

Frac Frac::operator / (Frac const& other) const {
    return Frac(*num * int(*(other.den)), int(*den) * *(other.num));
}
Frac Frac::operator / (int const& other) const { return *this / Frac(other); }
Frac Frac::operator / (double const& other) const { return *this / Frac(other); }
Frac Frac::operator / (float const& other) const { return *this / Frac(other); }

bool Frac::operator == (Frac const& other) const {
    return (*num == *(other.num) && *den == *(other.den));
}
bool Frac::operator == (int const& other) const { return *this == Frac(other); }
bool Frac::operator == (double const& other) const { return *this == Frac(other); }
bool Frac::operator == (float const& other) const { return *this == Frac(other); }

bool Frac::operator != (Frac const& other) const {
    return (*num != *(other.num) || *den != *(other.den));
}
bool Frac::operator != (int const& other) const { return *this != Frac(other); }
bool Frac::operator != (double const& other) const { return *this != Frac(other); }
bool Frac::operator != (float const& other) const { return *this != Frac(other); }

bool Frac::operator > (Frac const& other) const {
    return ((*num * int(*(other.den))) > (*(other.num) * int(*den)));
}
bool Frac::operator > (int const& other) const { return *this > Frac(other); }
bool Frac::operator > (double const& other) const { return *this > Frac(other); }
bool Frac::operator > (float const& other) const { return *this > Frac(other); }

bool Frac::operator >= (Frac const& other) const {
    return (*num * int(*(other.den)) >= *(other.num) * int(*den));
}
bool Frac::operator >= (int const& other) const { return *this >= Frac(other); }
bool Frac::operator >= (double const& other) const { return *this >= Frac(other); }
bool Frac::operator >= (float const& other) const { return *this >= Frac(other); }

bool Frac::operator < (Frac const& other) const {
    return (*num * int(*(other.den)) < *(other.num) * int(*den));
}
bool Frac::operator < (int const& other) const { return *this < Frac(other); }
bool Frac::operator < (double const& other) const { return *this < Frac(other); }
bool Frac::operator < (float const& other) const { return *this < Frac(other); }

bool Frac::operator <= (Frac const& other) const {
    return (*num * int(*(other.den)) <= *(other.num) * int(*den));
}
bool Frac::operator <= (int const& other) const { return *this <= Frac(other); }
bool Frac::operator <= (double const& other) const { return *this <= Frac(other); }
bool Frac::operator <= (float const& other) const { return *this <= Frac(other); }

Frac& Frac::operator = (Frac const& other) {
    *num = *(other.num);
    *den = *(other.den);
    return *this;
}
Frac& Frac::operator = (int const& other) { return *this = Frac(other); }
Frac& Frac::operator = (double const& other) { return *this = Frac(other); }
Frac& Frac::operator = (float const& other) { return *this = Frac(other); }

Frac& Frac::operator += (Frac const& other) {
    *this = *this + other;
    return *this;
}
Frac& Frac::operator += (int const& other) { return *this += Frac(other); }
Frac& Frac::operator += (double const& other) { return *this += Frac(other); }
Frac& Frac::operator += (float const& other) { return *this += Frac(other); }

Frac& Frac::operator -= (Frac const& other) {
    *this = *this - other;
    return *this;
}
Frac& Frac::operator -= (int const& other) { return *this -= Frac(other); }
Frac& Frac::operator -= (double const& other) { return *this -= Frac(other); }
Frac& Frac::operator -= (float const& other) { return *this -= Frac(other); }

Frac& Frac::operator *= (Frac const& other) {
    *this = *this * other;
    return *this;
}
Frac& Frac::operator *= (int const& other) { return *this *= Frac(other); }
Frac& Frac::operator *= (double const& other) { return *this *= Frac(other); }
Frac& Frac::operator *= (float const& other) { return *this *= Frac(other); }

Frac& Frac::operator /= (Frac const& other) {
    *this = *this / other;
    return *this;
}
Frac& Frac::operator /= (int const& other) { return *this /= Frac(other); }
Frac& Frac::operator /= (double const& other) { return *this /= Frac(other); }
Frac& Frac::operator /= (float const& other) { return *this /= Frac(other); }

ostream& operator << (ostream& stream, const Frac& frac)
{
    stream << '[' << *frac.num << '|' << *frac.den << ']';
    return stream;
}

istream& operator >> (istream& stream, Frac& frac)
{
    stream >> *(frac.num);
    stream >> *(frac.den);
    frac.reduce();
    return stream;
}
