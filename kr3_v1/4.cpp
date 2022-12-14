#include<iostream>

using namespace std;

int ccount(char x, char *str, int n) {
    int c = 0;
    for (int j = 0; j < n; ++j) {
        if (str[j] == x) ++c;
    }
    return c;
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
        for (int j = 0; j < n; ++j) chars[i][j] = (char) rand() % 256;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) cout << chars[i][j] << " ";
        cout << "| " << ccount(x, chars[i], n) << endl;
    }
    return 0;
}

