#include <iostream>

using namespace std;

int main()
{   
    int points = 0, answer;
    cout << "Добро пожаловать на тест по информатике и информационным технологиям\nПервый вопрос: Какое из этих слов является определением целочисленного типа в С++?\n1) int\n2)float\n3)double\n4)bool\n"; cin >> answer; cout << endl;
    switch (answer) {
        case 1:
            cout << "Правильно! Ты молодец!" << endl;
            points += 1;
            break;
        default:
            cout << "Неправильно! Правильным вариантом ответа был: int" << endl;
    }
    cout << "Второй вопрос: Какой из операторов в C++ является декрементом?\n1)*= \n2)%\n3)--\n4)++\n"; cin >> answer; cout << endl;
    switch (answer) {
        case 3:
            cout << "Правильно! Ты молодец!" << endl;
            points += 1;
            break;
        default:
            cout << "Неправильно! Правильным вариантом ответа был: --" << endl;
    }
    cout << "Третий вопрос: Какое из этих устройств выводит информацию\n1)Микрофон \n2)Наушники\n3)Клавиатура\n4)Мышь\n"; cin >> answer; cout << endl;
    switch (answer) {
        case 2:
            cout << "Правильно! Ты молодец!" << endl;
            points += 1;
            break;
        default:
            cout << "Неправильно! Правильным вариантом ответа был: Наушники" << endl;
            break;
    }
    cout << "Четвертый вопрос: Что такое ПК в словаре информатики?\n1)Персональный компьютер \n2)Первичный компилятор\n3)Паровой котел\n4)Предохранительный клапан\n"; cin >> answer; cout << endl;
    switch (answer) {
        case 1:
            cout << "Правильно! Ты молодец!" << endl;
            points += 1;
            break;
        default:
            cout << "Неправильно! Правильным вариантом ответа был: Персональный компьютер" << endl;
            break;
    }
    cout << "Пятый вопрос: 2Кб это сколько байтов?\n1)100 \n2)1024\n3)3072\n4)2048\n"; cin >> answer; cout << endl;
    switch (answer) {
        case 4:
            cout << "Правильно! Ты молодец!" << endl;
            points += 1;
            break;
        default:
            cout << "Неправильно! Правильным вариантом ответа был: 2048" << endl;
            break;
    }
    cout << "Поздравляю с прохождением теста!\nВаш результат:" << points;
    return 0;
}
