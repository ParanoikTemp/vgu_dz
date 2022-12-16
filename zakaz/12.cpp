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

void selectSort(int *arr, int m) {
    int max;
    for (int i = 0; i < m - 1; ++i) {
        max = 0;
        for (int j = 0; j < m - i; ++j) if (arr[max] < arr[j]) max = j;
        swap(arr[max], arr[m - i - 1]);
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
        else selectSort(nums[num - 1], m);
    }
    return 0;
}
