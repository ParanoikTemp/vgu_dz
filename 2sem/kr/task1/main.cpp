#include <iostream>
#include <fstream>
#include "Queue.h"

using namespace std;

/* КИМ 16 НОМЕР 1
 * Написать программу, которая создает очередь целых чисел, считываемых из файла и заменяет в этой очереди
 * значения элементов, которые равны вводимому с клавиатуры, на новое, также задаваемое с клавиатуры.
 * Вывести полученную очередь на экран.
 */

/*
 * Итого из задачи нужно реализовать класс очереди, который имеет три метода:
 * 1) Добавление элементов
 * 2) Замена элементов
 * 3) Вывод очереди на экран
 */

int main() {
    ifstream file("C:\\cpp_files\\task34\\nums.txt");
    if (file.is_open()) {
        int num, new_num;
        Queue que;
        while (!file.eof()) {
            file >> num;
            que.insert(num);
        }
        file.close();
        cout << "Enter the number: ";
        cin >> num;
        cout << "\nEnter the new number: ";
        cin >> new_num;
        cout << "\n";
        que.replace(num, new_num);
        que.print();
    }
    return 0;
}
