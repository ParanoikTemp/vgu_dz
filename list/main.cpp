#include <iostream>
#include "list.h"
#include <windows.h>
#include <cmath>

using namespace std;

/*
 * Драсте, это моя реализация списков, ага да
 * Код пишу на стандарте C++ 20, так что если че то беды, то адаптируйте его под вашу версию стандарта языка
 * Либо поменяйте стандарт языка в настройках компилятора
 * Где их искать это ваши проблемы, гуглите. Я пользуюсь CLion и мне по кайфу
 * Его вам тоже советую. Могу даже ключ бесплатный дать
 */

int main() {
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "RU");
    int nums[] = {23, 3, 423, 3, 235, 8};  // инициализирую массив чисел
    Node* head = setList(sizeof (nums) / sizeof (nums[0]), nums);  // инициализирую список на основе массива

    cout << "Количество элементов в списке: " << getListLength(head) << endl;  // Вывожу количество элементов списка

    cout << "Элементы в списке: ";
    printList(head);  // вывожу сами элементы
    cout << endl;

    cout << "Третий элемент списка: " << getNode(head, 2)->value << endl;  // мы можем быстро получить нужный элемент списка по индексу

    head = pushBack(head, 150);  // добавляем новый элемент в конец
    cout << "Добавил в конец число 150. \nНовый список: ";
    printList(head); cout << " | Длина: " << getListLength(head) << endl;

    head = pushFront(head, -15);  // добавляем новый элемент в начало.
    // функция фактически меняет ведущий элемент в head.
    cout << "Добавил в начало число -15. \nНовый список: ";
    printList(head); cout << " | Длина: " << getListLength(head) << endl;

    head = insertNode(head, 5, 666);  // добавляем новый элемент с индексом 5.
    // функция фактически меняет ведущий элемент в head.
    cout << "Добавил после пятого элемента число 666. \nНовый список: ";
    printList(head); cout << " | Длина: " << getListLength(head) << endl;

    head = removeBack(head);  // Удаляем самый последний элемент
    cout << "Удалил последнее число. \nНовый список: ";
    printList(head); cout << " | Длина: " << getListLength(head) << endl;

    head = removeFront(head);  // Удаляем самый первый элемент
    cout << "Удалил первое число. \nНовый список: ";
    printList(head); cout << " | Длина: " << getListLength(head) << endl;

    head = removeNode(head, 2);  // Удаляем элемент по индексу
    cout << "Удалил третий элемент. \nНовый список: ";
    printList(head); cout << " | Длина: " << getListLength(head) << endl;

    head = reverseNode(head);
    cout << "Реверснул хуйню. \nНовый список: ";
    printList(head); cout << " | Длина: " << getListLength(head) << endl;
    cout << endl << endl << "Ну и вот экспериментальный тест:\n";
    Node *list = nullptr;
    for (int i = 0; i < 8; ++i) {
        list = pushBack(list, pow(3, i));
    }
    list = insertNode(list, getListLength(list) / 2, 1000);
    list = removeFront(list);
    list = removeBack(list);
    printList(list);
    return 0;
}
