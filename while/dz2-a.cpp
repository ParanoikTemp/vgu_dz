#include <iostream>

using namespace std;

int main()
{
    float i = 0, sum = 0;
    while (i < 50) {
        ++i;
        sum += 1.0 / (i * i * i);
    }
    cout << sum;
    return 0;
}
