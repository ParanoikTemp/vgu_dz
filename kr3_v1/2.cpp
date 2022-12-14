#include<iostream>

using namespace std;

int main()
{
    int count = 0, s;
    cin >> s;
    for (int i = 10; i < 100; ++i) if (i / 10 + i % 10 == s) ++count;
    cout << endl << "Result: " << count;
    return 0;
}
