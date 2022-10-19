#include<iostream>
using namespace std;

int main()
{
    int k, i = 1, num = 1;
    cin >> k;
    while (k) {
        --k;
        unsigned d = 1;
        while (num / d > 9) d *= 10;
        num %= d;
        if (num == 0) {num = i * i; ++i;}
    }
    while (num > 9) num /= 10;
    cout << num;
}
