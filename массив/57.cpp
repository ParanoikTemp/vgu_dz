#include<iostream>

using namespace std;

int main()
{
    float nums[50], sum = 0;
    for (int i = 0; i < 50; ++i) nums[i] = rand() % 201 + 600;  // наполнение цифрами
    for (int i = 0; i < 50; ++i) {
        sum += nums[i];
    }
    sum /= 50;
    cout << "Среднее значение: " << sum << endl;
    for (int i = 0; i < 50; ++i) {
        cout << sum - nums[i] << " ";
    }
}
