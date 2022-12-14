#include<iostream>

using namespace std;

int ccount(char **matrix, char c, int n) {
    int res = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == c) {
                ++res;
                break;
            }
        }
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    char **chars = new char * [n], x;
    cin.ignore();
    cin.get(x);
    for (int i = 0; i < n; ++i) {
        chars[i] = new char [n];
        for (int j = 0; j < n; ++j) chars[i][j] = (char)((int) 'a' + rand() % 26);
      // По хорошему надо заполнять рандомными числами и сделать чисто rand() % 256, но для удобства представления я сделал матрицу чисто из букв.
      // насчет такого лучше уточнить у Лещинской
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) cout << chars[i][j] << " ";
        cout << endl;
    }
    cout << "Result: " << ccount(chars, x, n);
    return 0;
}
