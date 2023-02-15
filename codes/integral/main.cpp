#include <iostream>
#include "functions.h"

using namespace std;

int main()
{
    double a, b; int n;
    cout << "Input a: ";
    cin  >> a;
    cout << "Input b: ";
    cin  >> b;
    if (a>=b)
    {
        double temp=a;
        a=b;
        b=temp;
    }
    cout << "Input power of sin() n>2: ";
    cin  >> n;
    if (n<=2) n=3;
    cout << "Result: " << IntSin_N(a,b,n) << endl;
    return 0;
}
    
