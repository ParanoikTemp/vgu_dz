#include<iostream>

using namespace std;

int main()
{
    long float nums[30], sum1 = 0, sum2 = 0;
    int nums2[30];
    for (int i = 0; i < 30; ++i) nums[i] = rand() % 50;  // наполнение цифрами
    for (int i = 0; i < 30; ++i) nums2[i] = rand() % 50;  // наполнение цифрами
    for (int i = 0; i < 50; ++i) {
        sum1 += nums[i] * nums2[i];
        sum2 += nums2[i];
    }
    cout << "Результат: " << sum1 / sum2 << endl;
}
