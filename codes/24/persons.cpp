#include "persons.h"

void processInputFile(const string& input_filename, const string& output_filename) {
    ifstream input_file(input_filename);
    ofstream output_file(output_filename, ios::binary);

    if (!input_file) {
        cout << "Failed to open input file." << endl;
        return;
    }

    if (!output_file) {
        cout << "Failed to open output file." << endl;
        return;
    }

    string line;
    while (!input_file.eof()) {
        Person person;

        getline(input_file, line, ':');
        line.copy(person.full_name, line.length());
        person.full_name[line.length()] = '\0';

        getline(input_file, line, ':');
        line.copy(person.street, line.length());
        person.street[line.length()] = '\0';

        getline(input_file, line, ':');
        line.copy(person.house_number, line.length());
        person.house_number[line.length()] = '\0';

        getline(input_file, line, ':');
        line.copy(person.apartment, line.length());
        person.apartment[line.length()] = '\0';

        getline(input_file, line);
        line.copy(person.phone_number, line.length());
        person.phone_number[line.length()] = '\0';

        // Write the person structure to the output file
        output_file.write((char*)&person, sizeof(person));
    }

    input_file.close();
    output_file.close();
}

Person findPersonByPhoneNumber(const string& filename, const char phone_number[7]) {
    ifstream file(filename, ios::binary);
    if (!file) {
        cout << "Failed to open file." << endl;
        return Person(); // Возвращаем пустую структуру в случае ошибки
    }

    Person person;
    while (file.read((char*)&person, sizeof(person))) {
        if (strcmp(person.phone_number, phone_number) == 0) {
            file.close();
            return person;
        }
    }

    file.close();
    return Person(); // Возвращаем пустую структуру, если номер не найден
}


void printPersonInfo(const Person& person) {
    cout << "Full Name: " << person.full_name << endl;
    cout << "Street: " << person.street << endl;
    cout << "House Number: " << person.house_number << endl;
    cout << "Apartment: " << person.apartment << endl;
    cout << "Phone Number: " << person.phone_number << endl;
}

void searchAndPrintPerson(const string& filename) {
    char phone_number[7];
    cout << "Введите номер телефона (6 цифр): ";
    cin.getline(phone_number, 7);

    Person foundPerson = findPersonByPhoneNumber(filename, phone_number);

    if (foundPerson.phone_number[0] != '\0') {
        cout << "Найден адресат:" << endl;
        printPersonInfo(foundPerson);
    } else {
        cout << "Адресат не найден." << endl;
    }
}
