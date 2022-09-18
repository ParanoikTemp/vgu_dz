#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int i, x, N;
    float E;
    cout << "Введите значение переменной x: "; cin >> x;
    cout << "Введите значение переменной N: "; cin >> N;
    cout << "Введите значение переменной E: "; cin >> E;
    cout << "Выберите действие программы: (1/2)"; cin >> i;
    if (i == 1) {
        float sum1 = 0, sum2 = 0;
        for (int i=0;i <= N;i++) {
            float elem;
            elem = pow(x, i);
            int fact = 1;
            if (i > 1) {
                for (int j=1;j<=i;j++) {
                        fact *= j;
                    }
            }
            elem /= fact;
            sum1 += (elem * pow(-1, i));
            if (elem > E) sum2 += (elem * pow(-1, i));
        }
        cout << "Сумма 1: " << sum1 << endl << "Сумма 2: " << sum2;
    } else {
        float new_E = E * 10 + E;
        int i = 0;
        float sum = 0;
        float elem;
        while (sum < new_E) {
            elem = pow(x, i);
            int fact = 1;
            if (i > 1) {
                for (int j=1;j<=i;j++) {
                        fact *= j;
                    }
            }
            elem /= fact;
            sum += (elem * pow(-1, i));
            i += 1;
        } 
        sum -= (elem * pow(-1, i));
        i -= 1;
        float err = pow(M_E, x) - sum;
        cout << "Количество слагаемых составляет: " << i << endl << "Разница между формулой и суммой составляет: " << err;
    }
}


