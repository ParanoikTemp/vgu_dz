#include <iostream>

using namespace std;

int *shell(int arr[], int len) {
    int d = len;
    while (d != 1) {
        d /= 2;
        for (int i = 0; i < len - d; ++i) for (int j = i; j <= len - d; j += d) if (arr[i] > arr[j]) swap(arr[i], arr[j]);
    }
    return arr;
}

void init(int **&matrix, int h, int w) {
    for (int i = 0; i < h; ++i) for (int j = 0; j < w; ++j) matrix[i][j] = rand() % 10;
}

void print(int **matrix, int h, int w) {
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) cout << matrix[i][j] << "\t";
        cout << endl;
    }
}

int main() {
    int w, h, num = -1;
    cout << "Enter the height and width of the matrix: "; cin >> h >> w; cout << endl;
    int **matrix = new int*[h];
    for (int i = 0; i < h; ++i) matrix[i] = new int[w];
    init(matrix, h, w);
    while (num) {
        print(matrix, h, w);
        cout << "Enter 0 to end the program\nOr enter the number of the line you want to sort" << endl;
        cin >> num;
        if (num > 0) {
            matrix[num - 1] = shell(matrix[num - 1], w);
        }
    }
    return 0;
}
