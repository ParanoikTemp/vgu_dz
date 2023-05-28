#include "functions.h"

luggage** setBags(const string& way, int& count) {
    ifstream bag1(way);
    string temp;
    count = 0;
    if (!bag1.is_open()) {cout << "Ошибка открытия файла!"; return nullptr;}
    while (getline(bag1, temp)) ++count;
    bag1.clear();
    bag1.seekg(0);

    luggage** arr = new luggage* [count];
    for (int n = 0; n < count; ++n) {
        arr[n] = new luggage;
        bag1 >> arr[n]->kolvo >> arr[n]->ves;
    }
    return arr;
}

void printOneLuggagePassenger(luggage** arr, int count) {
    cout << "\nПункт  e)" << endl;
    int flag = 0;
    for (int i = 0; i < count; i++) {
    if (arr[i]->kolvo == 1 && arr[i]->ves >= 30) {
    flag = 1;
    cout << "\tПассажир №" << i + 1 << " имеет багаж с одной вещью весом не менее 30 кг \n";
    }
    }
    if (flag == 0) {
    cout << "\n  Таких пассажиров нет \n";
    }
}

void printMaxLugMinWei(luggage** arr, int count) {
        cout << "\nПункт f)" << endl;
        luggage* lug = arr[0];
        int num;
        for (int i = 1; i < count; ++i) {
            if (lug->kolvo < arr[i]->kolvo || lug->kolvo == arr[i]->kolvo && lug->ves > arr[i]->ves) {
                lug = arr[i];
                num = i;
            }
        }
        cout << "\n\tПассажир с багажом, число вещей в котором не меньше, чем в любом другом багаже, а вес вещей не больше, чем в любом другом багаже с этим же количеством вещей:\n";
        cout << "\n\tПассажир № " << num + 1 << "\n";
        cout << "\tЧисло вещей: " << lug->kolvo << "\n";
        cout << "\tВес: " << lug->ves << "\n";
};

