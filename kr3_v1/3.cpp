#include<iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    double **matrix = new double * [n], sum1, sum2;
    for (int i = 0; i < n; ++i) {
        matrix[i] = new double [m];
        for (int j = 0; j < m; ++j) matrix[i][j] = rand() % 100 + (rand() % 100) * 0.01;
    }

    for (int k = 1; k < m - 1; ++k) {
        for (int j = 0; j < m - k; ++j) {
            sum1 = 0, sum2 = 0;
            for (int i = 0; i < n; ++i) sum1 += matrix[i][j];
            for (int i = 0; i < n; ++i) sum2 += matrix[i][j + 1];
            if (sum1 > sum2) for (int i = 0; i < n; ++i) swap(matrix[i][j], matrix[i][j + 1]);
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) cout << matrix[i][j] << "\t";
        cout << endl;
    }
    return 0;
}
