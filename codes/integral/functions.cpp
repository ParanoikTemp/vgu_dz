#include <math.h>
#include "functions.h"

double f1(double x)
{
    return -cos(x);
}

double f2(double x)
{
    return x/2-sin(2*x)/4;
}

double f3(double x, int n)
{
    double temp=sin(x);
    double res=cos(x);
    for (int i=1; i<n; i++)
        res*=temp;
    return -res/n;
}

double IntSin_N(double a, double b, int n)
{
switch (n)
    {
    case 1:
        {
        return f1(b)-f1(a);
        break;
        }
    case 2:
        {
        return f2(b)-f2(a);
        break;
        }
    default:
        {
        return f3(b,n)-f3(a,n)+double(n-1)/n*IntSin_N(a,b,n-2);
        }
    }
}
