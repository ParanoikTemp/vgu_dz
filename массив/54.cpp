#include<iostream>

using namespace std;

int main()
{
    float nums[] = {1, 2, 1, 4, 5, 7, 8}, max = -999999999, min = 999999999, sum = 0;
    int sz = sizeof(nums) / sizeof(nums[0]);
    for (int i = 0; i < sz; ++i) {
        sum += nums[i];
        nums[i] = sum / (i + 1);
        cout << nums[i] << " ";
    }
}
