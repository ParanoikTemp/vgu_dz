#include "funcs.h"

Book nextBook(istream& input_file) {
    Book book{};
    Book pattern{"Неизвестен", "Безымянный Н.Н.", "1999", "Не задано"};
    string word;
    int i;
    // внос автора
    getline(input_file, word, '|');
    if (!word.empty()) for (i = 0; i < word.length(); ++i) book.author[i] = word[i];
    else for (i = 0; i < sizeof(pattern.author); ++i) book.author[i] = pattern.author[i];
    // внос названия
    getline(input_file, word, '|');
    if (!word.empty()) for (i = 0; i < word.length(); ++i) book.name[i] = word[i];
    else for (i = 0; i < sizeof(pattern.name); ++i) book.name[i] = pattern.name[i];
    // внос года
    getline(input_file, word, '|');
    if (!word.empty()) for (i = 0; i < word.length(); ++i) book.year[i] = word[i];
    else for (i = 0; i < sizeof(pattern.year); ++i) book.year[i] = pattern.year[i];
    // внос специальности
    getline(input_file, word, '\n');
    if (!word.empty()) for (i = 0; i < word.length(); ++i) book.specialty[i] = word[i];
    else for (i = 0; i < sizeof(pattern.specialty); ++i) book.specialty[i] = pattern.specialty[i];
    return book;
}

bool makeDatabase(const string& input_file_name, const string& output_file_name, int& len) {
    ifstream input_file(input_file_name);
    if (!input_file.is_open()) return false;
    string word;
    len = 0;
    while (getline(input_file, word)) ++len;
    input_file.clear();
    input_file.seekg(ios::beg);
    ofstream output_file(output_file_name, ios::binary | ios::out);
    if (!output_file.is_open()) return false;
    for (int i = 0; i < len; ++i) {
        Book book = nextBook(input_file);
        output_file.write(book.author, sizeof(book.author));
        output_file.write(book.name, sizeof(book.name));
        output_file.write(book.year, sizeof(book.year));
        output_file.write(book.specialty, sizeof(book.specialty));
    }
    input_file.close();
    output_file.close();
    return true;
}

bool makeFile(const string& input_file_name, const string& output_file_name, const string& specialty, int len) {
    ifstream input_file(input_file_name, ios::binary | ios::out);
    if (!input_file.is_open()) return false;
    ofstream output_file(output_file_name);
    if (!output_file.is_open()) return false;
    for (int i = 0; i < len; ++i) {
        Book book{};
        input_file.read(book.author, sizeof(book.author));
        input_file.read(book.name, sizeof(book.name));
        input_file.read(book.year, sizeof(book.year));
        input_file.read(book.specialty, sizeof(book.specialty));
        if (string(book.specialty) == specialty) {
            output_file.write(string(book.author).c_str(), string(book.author).length());
            output_file.write(" | ", 3);
            output_file.write(string(book.name).c_str(), string(book.name).length());
            output_file.write(" | ", 3);
            output_file.write(string(book.year).c_str(), string(book.year).length());
            output_file.write(" | ", 3);
            output_file.write(string(book.specialty).c_str(), string(book.specialty).length());
            output_file.write("\n", 1);
        }
    }
    input_file.close();
    output_file.close();
    return true;
}

string* setSpecialtys(ifstream& input_file, int len, int& count) {
    string* specialtys = new string[1];
    bool flag;
    count = 0;
    for (int i = 0; i < len; ++i) {
        Book book{};
        input_file.read(book.author, sizeof(book.author));
        input_file.read(book.name, sizeof(book.name));
        input_file.read(book.year, sizeof(book.year));
        input_file.read(book.specialty, sizeof(book.specialty));
        if (!count) {specialtys[0] = book.specialty; ++count;}
        flag = true;
        for (int k = 0; k < count; ++k) {
            if (specialtys[k] == book.specialty) {flag = false; break;}
        }
        if (flag) {
            string* extra = new string[count];
            for (int k = 0; k < count; ++k) extra[k] = specialtys[k];
            specialtys = new string[++count];
            for (int k = 0; k < count - 1; ++k) specialtys[k] = extra[k];
            specialtys[count - 1] = book.specialty;
            delete[] extra;
        }
    }
    input_file.clear();
    input_file.seekg(0);
    return specialtys;
}

bool Interface(const string& input_file_name, const string& output_file_name, int count) {
    int spec_count, num;
    ifstream database(input_file_name, ios::binary | ios::out);
    if (!database.is_open()) {cout << "Ошибка открытия БД\n"; return false;}
    string* specialtys = setSpecialtys(database, count, spec_count);
    cout << "Выберите специальность:\n";
    for (int i = 0; i < spec_count; ++i) cout << i + 1 << ") " << specialtys[i] << endl;
    cin >> num;
    if (num <= 0 || num > spec_count) {cout << "Я вас понял. Хорошего дня."; return true;}
    bool res = makeFile(input_file_name, output_file_name, specialtys[num - 1], count);
    if (!res) {cout << "Ошибка при генерации текстового файла!\n"; return false;}
    cout << "Файл успешно сгенерирован!";
    return true;
}