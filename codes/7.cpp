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

void selectSort(int *&arr, int m) {
    int max;
    for (int i = 0; i < m - 1; ++i) {
        max = 0;
        for (int j = 0; j < m - i; ++j) if (arr[max] < arr[j]) max = j;
        swap(arr[max], arr[m - i - 1]);
    }
}

int main()
{
    int n, m, num; // num - вспомогательная переменная для цикла
    cin >> n >> m; // размеры матрицы (строки, стобцы)
    int **nums = new int*[n];
    for (int i = 0; i < n; ++i) nums[i] = new int[m];
    init(nums, n, m); // заполнение данными
    bool play = true; // пока эта переменная true цикл работает
    while (play) {
        print(nums, n, m);
        cout << "Enter number" << endl; // тут поставь какой то свой текст. Если строка под введеным номером не найдетс, то конец циклу
        cin >> num;
        if (num < 1 || num > n) play = false;
        else selectSort(nums[num - 1], m);
    }
    return 0;
}
