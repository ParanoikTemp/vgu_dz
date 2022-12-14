#include<iostream>
#include<cmath>

using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;
    double **matrix = new double * [m], min;
    for (int i = 0; i < m; ++i) {
        matrix[i] = new double [n];
        for (int j = 0; j < n; ++j) matrix[i][j] = rand() % 10 + (rand() % 100) * 0.01;
    }
    for (int i = 0; i < m; ++i) {
        min = matrix[i][0];
        for (int j = 0; j < n; ++j) {
            if (min > matrix[i][j]) min = matrix[i][j];
            cout << matrix[i][j] << "\t";
        }
        cout << "[" << min << "]" << endl;
    }
    return 0;
}
