#include "funcs.h"
#include <fstream>

using namespace std;

man ideal = {"", "", "", 20, 170, {66, 170, 255}, 250, 240, 190, 1000000, true, true};

std::string *split(const std::string& text, int &len) {
    int spaces = 1;
    for (auto i: text) if (i == ' ') ++spaces;
    len = spaces;
    auto *array = new string [spaces];
    for (int i = 0; i < spaces; ++i) array[i] = "";
    int j = 0;
    for (auto i: text) {
        if (i == ' ') ++j;
        else array[j] += i;
    }
    return array;
}

void calcCoefficient(man* parm) {
    double i = 100;
    i -= double(abs(parm->age - ideal.age)) / 5;
    i -= double(abs(parm->height - ideal.height)) / 10;
    i -= double(abs(parm->eye_color[0] - ideal.eye_color[0])) / 25;
    i -= double(abs(parm->eye_color[1] - ideal.eye_color[1])) / 25;
    i -= double(abs(parm->eye_color[2] - ideal.eye_color[2])) / 25;
    i -= double(abs(parm->hair_color[0] - ideal.hair_color[0])) / 25;
    i -= double(abs(parm->hair_color[1] - ideal.hair_color[1])) / 25;
    i -= double(abs(parm->hair_color[2] - ideal.hair_color[2])) / 25;
    i -= double(-parm->salary + ideal.salary) / 20000;
    i -= (parm->has_room != ideal.has_room) * 10;
    i -= (parm->has_car != ideal.has_car) * 10;
    parm->cof = i;
}

void StringToStruct(man* parm, const string& text) {
    int len;
    string *data = split(text, len);
    string new_data[] = {"Ноунеймов", "Ноунейм", "Ноунеймович", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0"};
    for (int i = 0; i < len; ++i) if (!data[i].empty()) new_data[i] = data[i];
    parm->last_name = new_data[0];
    parm->name = new_data[1];
    parm->fatherhood = new_data[2];
    parm->age = stoi(new_data[3]);
    parm->height = stoi(new_data[4]);
    parm->eye_color[0] = stoi(new_data[5]);
    parm->eye_color[1] = stoi(new_data[6]);
    parm->eye_color[2] = stoi(new_data[7]);
    parm->hair_color[0] = stoi(new_data[8]);
    parm->hair_color[1] = stoi(new_data[9]);
    parm->hair_color[2] = stoi(new_data[10]);
    parm->salary = stoi(new_data[11]);
    parm->has_room = stoi(new_data[12]);
    parm->has_car = stoi(new_data[13]);
}

void menSort(man **men, int len) {
    for (int k = 1; k < len; ++k) for (int i = 0; i < len - k; ++i) if (men[i]->cof < men[i + 1]->cof) swap(men[i], men[i + 1]);
}

void printMan(man* parm) {
    cout << parm->last_name << " " << parm->name << " " << parm->fatherhood << endl;
    cout << "Возраст: " << parm->age << " лет. Рост: " << parm->height << " см. Зарплата: " << parm->salary << " руб.\n";
    cout << "Цвет глаз (RGB): " << parm->eye_color[0] << " " << parm->eye_color[1] << " " << parm->eye_color[2];
    cout << "  Цвет волос (RGB): " << parm->hair_color[0] << " " << parm->hair_color[1] << " " << parm->hair_color[2] << endl;
    if (parm->has_room) cout << "Есть жилье.\n";
    if (parm->has_car) cout << "Есть машина.\n";
}

man** getMenArray(const string& filepath, int &len) {
    string line;
    int count = 0, num = 0;
    ifstream in(filepath);
    if (in.is_open()) while (getline(in, line)) ++count;
    len = count;
    man** men = new man*[count];
    ifstream in2(filepath);
    if (in2.is_open()) {
        while (getline(in2, line)) {
            men[num] = new man;
            StringToStruct(men[num], line);
            calcCoefficient(men[num]);
            ++num;
        }
    }
    return men;
}

void printMenArray(man** men, int len) {
    int num = 1;
    cout << "Напишите номер кандидата для просмотра его анкеты или \"0\" чтобы завершить работу программы\n";
    while (num > 0 && num <= len) {
        cout << "Кандидат: (" << num << "/" << len << ")" << endl;
        if (num == 1) cout << "[НАИЛУЧШИЙ ВАРИАНТ]\n";
        printMan(men[num - 1]);
        cin >> num;
    }
}
