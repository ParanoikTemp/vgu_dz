using namespace std;
#include <ostream>

class Frac {
    private:
        int* num;
        unsigned int* den;
        
        void reduce();
    public:
        Frac();
        Frac(int numerator);
        Frac(int numerator, unsigned int denominator);
        Frac(const Frac& fr);
        Frac(double number);
        Frac(float number);
        ~Frac();
        
        int getNum();
        unsigned int getDen();
        void setNum(int numerator);
        void setDen(unsigned int denominator);
        
        Frac operator + (Frac const &other);
        Frac operator + (int const &other);
        Frac operator + (double const &other);
        Frac operator + (float const &other);
        Frac operator - (Frac const &other);
        Frac operator - (int const &other);
        Frac operator - (double const &other);
        Frac operator - (float const &other);
        Frac operator * (Frac const &other);
        Frac operator * (int const &other);
        Frac operator * (double const &other);
        Frac operator * (float const &other);
        Frac operator / (Frac const &other);
        Frac operator / (int const &other);
        Frac operator / (double const &other);
        Frac operator / (float const &other);
        Frac operator % (Frac const &other);
        
        bool operator == (Frac const &other) const;
        bool operator == (int const &other) const;
        bool operator == (float const &other) const;
        bool operator == (double const &other) const;
        bool operator != (Frac const &other) const;
        bool operator != (int const &other) const;
        bool operator != (float const &other) const;
        bool operator != (double const &other) const;
        bool operator > (Frac const &other) const;
        bool operator > (int const &other) const;
        bool operator > (float const &other) const;
        bool operator > (double const &other) const;
        bool operator >= (Frac const &other) const;
        bool operator >= (int const &other) const;
        bool operator >= (float const &other) const;
        bool operator >= (double const &other) const;
        bool operator < (Frac const &other) const;
        bool operator < (int const &other) const;
        bool operator < (float const &other) const;
        bool operator < (double const &other) const;
        bool operator <= (Frac const &other) const;
        bool operator <= (int const &other) const;
        bool operator <= (float const &other) const;
        bool operator <= (double const &other) const;
        
        Frac operator = (Frac const &other);
        Frac operator = (int const &other);
        Frac operator = (double const &other);
        Frac operator = (float const &other);
        Frac operator += (Frac const &other);
        Frac operator += (int const &other);
        Frac operator += (double const &other);
        Frac operator += (float const &other);
        Frac operator -= (Frac const &other);
        Frac operator -= (int const &other);
        Frac operator -= (double const &other);
        Frac operator -= (float const &other);
        Frac operator *= (Frac const &other);
        Frac operator *= (int const &other);
        Frac operator *= (double const &other);
        Frac operator *= (float const &other);
        Frac operator /= (Frac const &other);
        Frac operator /= (int const &other);
        Frac operator /= (double const &other);
        Frac operator /= (float const &other);
        
        friend ostream& operator << (ostream& stream, const Frac& frac);
        friend istream& operator >> (istream& stream, Frac& frac);
        
        void print();
};
