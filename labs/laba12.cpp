#include <iostream>

using namespace std;

int** init(int n, int m) {
    int** arr = new int* [n];
    for (int i = 0; i < n; ++i) arr[i] = new int [m];
    for (int y = 0; y < n; ++y) for (int x = 0; x < m; ++x) arr[y][x] = rand() % 100;
    return arr;
}

void print(int** arr, int rows, int cols) {
    for (int y = 0; y < rows; ++y) {
        for (int x = 0; x < cols; ++x) cout << arr[y][x] << "\t";
        cout << endl;
    }
}

int* sort(int* row, int size) {
    int ex;
    for (int i = size - 1; i > 0; --i) {
        for (int j = 0; j < i; ++j) {
            if (row[j] > row[j + 1]) {
                ex = row[j + 1];
                row[j + 1] = row[j];
                row[j] = ex;
            }
        }
    }
    return row;
}

int main() {
    int rows, cols;
    cout << "Введите количество строк: "; cin >> rows; cout << endl;
    cout << "Введите количество столбцов: "; cin >> cols; cout << endl;
    int** arr = init(rows, cols);
    cout << "Матрица сгенерирована:\n";
    print(arr, rows, cols);
    int row;
    cout << "Выберите строку для сортировки: "; cin >> row; cout << endl;
    arr[row - 1] = sort(arr[row - 1], cols);
    cout << "Строка отсортирована:\n";
    print(arr, rows, cols);
}
