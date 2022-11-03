#include<iostream>

using namespace std;

int main()
{
    int nums[] = {1, 2, 1, 4, 5, 7, 8}, max = -999999999, min = 999999999;
    int sz = sizeof(nums) / sizeof(nums[0]);
    for (int i = 0; i < sz; ++i) {
        if (nums[i] < min) min = nums[i];
        if (nums[i] > max) max = nums[i];
    }
    for (int i = 0; i < sz; ++i) {
        if (nums[i] == min) nums[i] += max;
        cout << nums[i] << " ";
    }
}
