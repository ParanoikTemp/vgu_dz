#include <iostream>

using namespace std;

int main() {
    int arr[] = {1, 3, 5, 3, 5, 3, 2, 5, 2, 9, 9, 3, 5, 4};
    int k = 1, *new_arr = new int[5];
    bool flag;
    new_arr[0] = arr[0];
    for (int i : arr) {
        flag = true;
        for (int j = 0; j < k; ++j) if (i == new_arr[j]) {flag = false; break;}
        if (flag) {
            int *extra = new int[k];
            for (int j = 0; j < k; ++j) extra[j] = new_arr[j];
            ++k;
            delete[] new_arr;
            int *new_arr = new int[k];
            for (int j = 0; j < k - 1; ++j) new_arr[j] = extra[j];
            new_arr[k - 1] = i;
            delete[] extra;
        }
    }
    for (int i = 0; i < k; ++i) cout << new_arr[i] << " ";
    return 0;
}
