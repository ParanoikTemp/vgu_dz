#include <iostream>

using namespace std;

int main()
{
    float i = 0, sum = 0;
    while (i < 128) {
        i += 2;
        sum += 1.0 / (i * i);
    }
    cout << sum;
    return 0;
}
