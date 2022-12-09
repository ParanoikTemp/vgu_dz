#include<iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int n;
    cin >> n;
    char *text = new char[n];
    for (int i = 0; i < n; ++i) cin >> text[i];
    for (int i = 0; i < n; ++i) {
        cout << text[i];
        if (text[i] == ':') break;
    }
}
