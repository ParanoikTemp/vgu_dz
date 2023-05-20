#include "cars.h"

Car **setCars(const string& name, int& count) {
    ifstream in(name);
    string word;
    if (in.is_open()) {
        while (getline(in, word)) ++count;
        in.clear();
        in.seekg(0); // переход в начало файла после подсчета строк
        Car** cars = new Car* [count];
        for (int i = 0; i < count; ++i) {
            cars[i] = nextCar(in);
        }
        return cars;
    } else return nullptr;
}

Car* nextCar(ifstream& input) {
    Car* car = new Car{};
    car->number = new Number{};
    string word;

    getline(input, word, '!');
    if (!word.empty()) for (int k = 0; k < word.length(); ++k) car->model[k] = word[k];
    else for (int k = 0; k < 5; ++k) car->model[k] = "ERROR"[k];

    getline(input, word, '!');
    if (!word.empty()) car->number->region = stoi(word);

    getline(input, word, '!');
    if (!word.empty()) car->number->number = stoi(word);

    getline(input, word, '!');
    if (!word.empty()) car->number->letters = word;
    else car->number->letters = "AAA";

    getline(input, word, '!');
    if (!word.empty()) car->color[0] = stoi(word);
    getline(input, word, '!');
    if (!word.empty()) car->color[1] = stoi(word);
    getline(input, word, '!');
    if (!word.empty()) car->color[2] = stoi(word);

    getline(input, word, '!');
    if (!word.empty()) car->last_name = word;
    else car->last_name = "Безфамильный";

    getline(input, word, '!');
    if (!word.empty()) car->name = word;
    else car->name = "Безымянный";

    getline(input, word, '!');
    if (!word.empty()) car->patronymic = word;
    else car->patronymic = "Детдомовский";

    getline(input, word, '\n');
    if (!word.empty()) car->inspection = word;
    else car->inspection = "01.01.1998";

    return car;
}


void splitNumber(const string& input, string& chars, int& number1, int& number2) {
    chars = "";
    number1 = 0, number2 = 0;
    int state = 0; // используем для определения, читаем ли мы символы или числа
    for (char i : input) {
        if (isdigit(i)) {
            if (state == 0) number1 = number1 * 10 + (i - '0');
            if (state == 1) number2 = number2 * 10 + (i - '0');
        } else {
            if (i == '-') state = 1;
            else chars += i;
        }
    }
}


Car* getCar(const Number& number, Car** cars, int len) {
    for (int i = 0; i < len; ++i) {
       if (number.letters == cars[i]->number->letters &&
            number.number == cars[i]->number->number &&
            number.region == cars[i]->number->region) return cars[i];
    }
    return nullptr;
}

void printCar(const Car* car, const string& num) {
    cout << "Номер машины: " << num << endl;
    cout << "Модель: " << car->model << endl;
    cout << "Владелец: " << car->name << " " << car->last_name << " " << car->patronymic << endl;
    cout << "Цвет в RGB: (" << car->color[0] << ", " << car->color[1] << ", " << car->color[2] << ")\n";
    cout << "Дата последнего техосмотра: " << car->inspection << "\n\n";
}


void func(Car** cars, int count) {
    bool run = true;
    string word;
    Number num;
    while (run) {
        cout << "Введите номер машины или 0 чтобы выйти.\nНомер машины введите в формате: А345ТК-36\n";
        getline(cin, word);
        if (word != "0") {
            splitNumber(word, num.letters, num.number, num.region);
            Car* car = getCar(num, cars, count);
            if (car == nullptr) cout << "Не найдено\n\n";
            else printCar(car, word);
        }
        else run = false;
    }
}