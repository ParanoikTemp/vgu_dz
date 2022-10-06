#include <iostream>
#include <string>
#include <limits.h>
#define nl; cout << endl; // сокращение для переноса на следующую строку

using namespace std;

int **init(int& h, int& w) { // функция создания матрицы и ее заполнения оценками от 2 до 5
    cout << "Введите количество учеников: "; cin >> h; nl;
    cout << "Введите количество предметов: "; cin >> w; nl;
    int **matrix = new int*[h];
    for (int i = 0; i < h; ++i) matrix[i] = new int[w];
    for (int i = 0; i < h; ++i) for (int j = 0; j < w; ++j) matrix[i][j] = rand() % 4 + 2;
    cin.ignore();
    return matrix;
}

int *get_row(int **matrix, int i) { // чисто по заданию нужна функция возвращающая ряд
    return matrix[i];
}

int *get_col(int **matrix, int i) { // функция возвращающая столбец
    int size = sizeof(matrix) / sizeof(matrix[0]); // рассчет размера массива (количество рядов)
    int *col = new int[size];
    for (int j = 0; j < size; ++j) col[j] = matrix[j][i];
    return col;
}

int main()
{
    // инициализация данных
    int h, w;
    int **matrix = init(h, w);
    string *students = new string[h], *objects = new string[w];
    for (int i = 0; i < h; ++i) {cout << "Введите имя " << i + 1 << " ученика: "; getline(cin, students[i]); nl;}
    for (int i = 0; i < w; ++i) {cout << "Введите название " << i + 1 << " предмета: "; getline(cin, objects[i]); nl;}
    while (1) {
        // Вывод матрицы
        cout << "\t";
        for (int i = 0; i < h; ++i) cout << objects[i]<< "\t"; nl;
        for (int i = 0; i < h; ++i) {
            cout << students[i] << "\t";
            for (int j = 0; j < w; ++j) cout << matrix[i][j] << "\t";
            nl;
        }
        // действия
        int doing;
        cout << "Узнать количество успевающих учеников - 1\nУзнать средний балл студента - 2\nВыйти из программы - 0\nВыберите действие: "; cin >> doing; nl;
        if (doing == 0) {break;}
        else if (doing == 1) { 
            int n, sum;
            cout << "Выберите номер предмета: "; cin >> n; nl;
            int *col = get_col(matrix, n - 1);
            for (int i = 0; i < h; ++i) if (col[i] >= 4) sum += 1;
            cout << "Количество успевающих учеников по " << objects[n] << " составляет " << sum << " учеников.\n\n";
        } else if (doing == 2) {
            int n;
            float sum;
            cout << "Введите номер ученика: : "; cin >> n; nl;
            int *row = get_row(matrix, n - 1);
            for (int i = 0; i < n; ++i) sum += row[i];
            cout << "Средний балл ученика \"" << students[n] << "\" составляет " << sum << ".\n\n";
        }
    }
}
