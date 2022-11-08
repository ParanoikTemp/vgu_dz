#include<iostream>

using namespace std;

int main()
{
    char letters[80] = "0x3wNTL4L]aiOZv@Q_4^^e>l<Ad@V2rIyA<cNxmapmf9R[VjyOIV]JB7]s]CpFla>fNr4]:Y^cGw:Z2";
    for (int i = 0; i < 80; ++i) if (letters[i] <= '9' && letters[i] >= '0') cout << letters[i];
    cout << endl;
    for (int i = 0; i < 80; ++i) if (letters[i] > '9' || letters[i] < '0') cout << letters[i];
    return 0;
}
