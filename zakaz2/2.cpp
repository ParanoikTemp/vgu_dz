#include <iostream>
#include <cmath>
using namespace std;

double minNum(double *nums, int len) {
    double num = nums[0];
    for (int i = 0; i < len; ++i) if (num > nums[i]) num = nums[i];
    return num;
}

double maxNum(double *nums, int len) {
    double num = nums[0];
    for (int i = 0; i < len; ++i) if (num < nums[i]) num = nums[i];
    return num;
}

int main() {
    int intervals_count;
    cout << "Enter the number of intervals: ";
    cin >> intervals_count;
    auto *intervals = new double [intervals_count * 2];
    for (int i = 0; i < intervals_count * 2; ++i) cin >> intervals[i];
    double sum_lens = 0;
    for (int i = 0; i < intervals_count * 2; i += 2) sum_lens += abs(intervals[i] - intervals[i + 1]);
    if (intervals_count == 1) cout << "Interval found: (" << intervals[0] << ", " << intervals[1] << ")";
    else if (sum_lens <= maxNum(intervals, intervals_count * 2) - minNum(intervals, intervals_count * 2)) cout << "Interval does not exist!";
    else cout << "Interval found: (" << minNum(intervals, intervals_count * 2) << ", " << maxNum(intervals, intervals_count * 2) << ")";
}
