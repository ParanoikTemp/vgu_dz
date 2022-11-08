#include<iostream>

using namespace std;

int main()
{
    char letters[70] = "0x3wNTL\4L]aiOZv@Q_4^^e>l<A@V2rIyA<cNxmapmf96R[VjyOIV]JB7]s]CpFl>fNr4]";
    int len = sizeof(letters) / sizeof(letters[0]) - 1;
    for (len; len >= 0; --len) cout << letters[len];
}
