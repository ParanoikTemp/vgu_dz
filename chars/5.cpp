#include<iostream>

using namespace std;

int main()
{
    char bukva, el;
    int n, count = 0;
    cout << "Введите подсчитываемый символ: "; cin.get(bukva); cout << endl;
    cout << "Введите количество символов: "; cin >> n; cout << endl;
    for (int i = 0; i < n; ++i) {
        cin.ignore();
        cout << "Введите " << i + 1 << " символ: "; cin.get(el); cout << endl;
        if (el == bukva) ++count;
    }
    cout << "количество символов '" << bukva << "' составляет: " << count;
}
