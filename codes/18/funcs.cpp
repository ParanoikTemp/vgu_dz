#include "funcs.h"

Chel** setCheliki(ifstream& file, int& count) {
    count = 0;
    string line;
    while (getline(file, line)) {
        count += 1;
    }
    file.clear();
    file.seekg(0);
    Chel** cheliki = new Chel * [count];
    for (int i = 0; i < count; ++i) {
        cheliki[i] = getChel(file);
    }
    return cheliki;
}

Chel* getChel(ifstream& file) {
    Address adr{"Dont know", "000", "0"};
    Chel* chel = new Chel{"Noname", adr, "00000"};
    string line;
    getline(file, line, '|');
    if (!line.empty()) for (int i = 0; i < line.length(); ++i) chel->fio[i] = line[i];
    getline(file, line, '|');
    if (!line.empty()) for (int i = 0; i < line.length(); ++i) chel->address.street[i] = line[i];
    getline(file, line, '|');
    if (!line.empty()) for (int i = 0; i < line.length(); ++i) chel->address.number[i] = line[i];
    getline(file, line, '|');
    if (!line.empty()) for (int i = 0; i < line.length(); ++i) chel->address.flat[i] = line[i];
    getline(file, line, '\n');
    if (!line.empty()) for (int i = 0; i < line.length(); ++i) chel->number[i] = line[i];
    return chel;
}

void makeDatabase(const string& input, const string& dbpath) {
    int len = 0;
    ifstream file(input);
    Chel** cheliki = setCheliki(file, len);
    ofstream db(dbpath, ios::binary);
    for (int i = 0; i < len; ++i) db.write((char*)&(*cheliki[i]), sizeof (*cheliki[i]));
    db.close();
}

void Menu(const string input, const string output_file) {
    ifstream db(input, ios::binary);
    if (db.is_open()) {
        ofstream output(output_file);
        string number;
        cout << "Введите две цифры номера телефона: "; cin >> number;
        Chel chel{};
        while (!db.eof()) {
            db.read((char*)&chel, sizeof(chel));
            if (chel.number[0] == number[0] && chel.number[1] == number[1]) {
                output << chel.fio << "|" << chel.address.street << "|" << chel.address.number << "|" << chel.address.flat << "|" << chel.number << "\n";
            }
        }
        db.close();
        output.close();
    }
}