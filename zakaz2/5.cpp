#include <iostream>

using namespace std;

void init(int **&arr, int n, int m) {
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) arr[i][j] = rand() % 10;
}

void print(int **arr, int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) cout << arr[i][j] << "\t";
        cout << endl;
    }
}

void shellSort(int *arr, int len, bool reverse=false) {
    int d = len;
    while (d != 1) {
        d /= 2;
        for (int i = 0; i < len - d; ++i) for (int j = i; j <= len - d; j += d) if (arr[i] > arr[j] && !reverse || arr[i] < arr[j] && reverse) swap(arr[i], arr[j]);
    }
}

int main()
{
    int n, m, num;
    cin >> n >> m;
    int **nums = new int*[n];
    for (int i = 0; i < n; ++i) nums[i] = new int[m];
    init(nums, n, m);
    bool play = true;
    while (play) {
        print(nums, n, m);
        cout << "Enter number" << endl;
        cin >> num;
        if (num < 1 || num > n) play = false;
        else shellSort(nums[num - 1], m);
    }
    return 0;
}
