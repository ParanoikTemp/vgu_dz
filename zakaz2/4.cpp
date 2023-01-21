#include <iostream>
using namespace std;

int main() {
    int array_len;
    cin >> array_len;
    auto *nums = new int [array_len];
    for (int i = 0; i < array_len; ++i) nums[i] = rand() % 100;
    auto *new_nums = new int [array_len / 2 + array_len % 2];
    for (int i = 0; i < array_len; i += 2) new_nums[i / 2] = nums[i];
    cout << "Old array: [ ";
    for (int i = 0; i < array_len; ++i) cout << nums[i] << " ";
    cout << "]\nNew array: [ ";
    for (int i = 0; i < array_len / 2 + array_len % 2; ++i) cout << new_nums[i] << " "; cout << "]";
}
