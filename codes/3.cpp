#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
    int choice;
    cout << "1. Сумма заданного каличества слагаемых\n";
    cout << "2. Сумма с заданной точностью\n";
    cout << "3. Завершить работу\n";
    bool isError = false;
    do
    {
        cout << "-> ";
        cin >> choice;
        if (cin.fail() || choice < 1 || choice > 3)
        {
            isError = true;
            cout << "Ошибка ввода!\n";
            cin.clear();
            cin.ignore(cin.rdbuf() -> in_avail());
        }
        else
            isError = false;
    } while (isError);
    
    //std::cout << choice << '\n';
    do
    {
        //-------------------------------------------
        double x;
        cout << "Введите значение x: ";
        while (!(cin >> x) || abs(x) >=1)
        {
            cout << "Ошибка ввода (|x|<1)!\n";
            cin.clear();
            cin.ignore(255, '\n');
        }
        //std::cout << x << '\n';
        cout << setw(26) << left << "Приближённое значение"<< " = "<< fixed << setprecision(11) << (1 / sqrt(1+x))<< '\n';
        if (choice == 1)
        {
            cout << "Задача 1\n";
            cout << "Введите количество слагаемых:\n";
            int n;
            cin >> n;
            double s = 0, a = x;
            for (int i = 0; i < n; ++i )
            {
                s += a;
                a *= x * x*(2 * i + 1)*(2 * i + 1) / (2 * (i + 1)*(2 * i + 3));
            }
            cout << s << endl;
        }
        else    //choice = 2
        {
            cout << "Задача 2\n";
            double E;
            cout << "Введите точность вычислений: "; cin >> E;
            int i = 0;
            double s = 0, a = x;
            while (abs(a) > E)
            {
                s += a;
                a *= x * x*(2 * i + 1)*(2 * i + 1) / (2 * (i + 1)*(2 * i + 3));
                ++i;
            }
            cout << "Точность = "<< E << '\n';
            cout << "Количество слагаемых = "<< i << '\n';
            cout << setw(26) << left << "Приближённое значение"<< " = "<< fixed << setprecision(11)<< s << '\n';
            E = E/10;
        }
        char isExit;
        cout << "Завершить работу (Y/N - любой символ)\n";
        cin >> isExit;
        if (isExit == 'Y' || isExit == 'y') choice = 3;
    } while (choice != 3);
    return 0;
}
