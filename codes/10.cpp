#include <iostream>

using namespace std;


int main()
{
    int count, num;
    float ves[10] = {0.5, 2, 0.5, 0.3, 0.7, 0.4, 0.1, 0.2, 0.8, -1}, sum;
    for (int i = 1; i < 11; ++i) {
        count = 0;
        for (int j = 0; j < 1024; ++j) {
            sum = 0;
            num = 0;
            for (int k = j; k != 0; k /= 2) {
                sum += ves[num] * (float) (k % 2);
                ++num;
            }
            if (sum == (float) i) ++count;
        }
        cout << "C" << i << " - " << count << endl;
    }
}
