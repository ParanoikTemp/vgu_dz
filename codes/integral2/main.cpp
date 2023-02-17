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
    cout << "Input power of sin() n>0: ";
    cin  >> n;
    cout << "Result (1): " << IntSin_N(a,b,n) << endl;
    double p=1;
    cout << "Result (2): " << Integral(n,b,p) - Integral(n,a,p) << endl;
    return 0;
}
    
