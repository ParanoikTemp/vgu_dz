#include "funcs.h"

Product** setItemsList(const string& input_filename, int& count) {
    ifstream file(input_filename, ios::binary);
    if (!file.is_open()) {cout << "Ошибка открытия базы данных!";}
    Product item{};
    count = 0;
    while (file.read((char*)&item, sizeof(item))) ++count;
    Product** items = new Product * [count];
    file.clear();
    file.seekg(0);
    for (int i = 0; i < count; ++i) {
        items[i] = new Product;
        file.read((char*)&*items[i], sizeof(item));
    }
    file.close();
    return items;
}

void saveItemsList(const string& output_filename, Product** items, int count) {
    ofstream file(output_filename, ios::binary);
    if (!file.is_open()) {cout << "Ошибка открытия базы данных для записи!";}
    for (int i = 0; i < count; ++i) {
        Product item = *items[i];
        file.write((char*)&item, sizeof(item));
    }
    file.close();
}

void Interface(const string& filename) {
    int count, num, item_num, skip;
    bool run = true;
    Product** items = setItemsList(filename, count);
    string texts[] = {"Введите новое название для товара: (не больше 30 символов)\n", "Введите новое количество товара:\n", "Введите новую цену товара:\n"};
    while (run) {
        cout << "Выберите действие:\n0) Просмотреть список товаров\n1) Изменить название\n2) Изменить количество товаров\n3) Изменить цену\n4) Добавить товар\n5) Удалить товар\n6) Сохранить изменения\nЧтобы выйти, введите любое другое число.\n";
        cin >> num; cout << endl;
        if (num == 0) {
            if (!count) cout << "\n\nУ вас пока нет товаров!\n\n";
            else {
                cout << "Список товаров на данный момент:\n";
                for (int i = 0; i < count; ++i) cout << i + 1 << ") " << items[i]->name << " " << items[i]->cost << "руб. " << items[i]->count << "шт.\n";
                cout << endl;
            }
        }
        else if (num >= 1 && num <= 3) {
            if (!count) cout << "\n\nУ вас пока нет товаров!\n\n";
            else {
                cout << "Введите номер товара:\n";
                for (int i = 0; i < count; ++i) cout << i + 1 << ") " << items[i]->name << " " << items[i]->cost << "руб. " << items[i]->count << "шт.\n";
                cin >> item_num; cout << endl;
                cout << texts[num - 1];
                if (num == 1) cin >> items[item_num - 1]->name;
                else if (num == 2) cin >> items[item_num - 1]->count;
                else if (num == 3) cin >> items[item_num - 1]->cost;
                cout << "\nСделано!\n\n";
            }
        }
        else if (num == 4) {
            Product** extra = new Product * [count];
            for (int i = 0; i < count; ++i) extra[i] = items[i];
            items = new Product * [++count];
            for (int i = 0; i < count - 1; ++i) items[i] = extra[i];
            delete[] extra;
            items[count - 1] = new Product;
            cout << "Введите название товара:"; cin >> items[count - 1]->name; cout << endl;
            cout << "Введите цену товара:"; cin >> items[count - 1]->cost; cout << endl;
            cout << "Введите количество товара:"; cin >> items[count - 1]->count; cout << endl;
            cout << "Товар успешно добавлен!\n\n";
        }
        else if (num == 5) {
            if (!count) cout << "\n\nУ вас пока нет товаров!\n\n";
            else {
                cout << "Введите номер товара:\n";
                skip = 0;
                for (int i = 0; i < count; ++i)
                    cout << i + 1 << ") " << items[i]->name << " " << items[i]->cost << "руб. " << items[i]->count
                         << "шт.\n";
                cin >> item_num;
                cout << endl;
                Product **extra = new Product *[count - 1];
                for (int i = 0; i < count - 1; ++i) {
                    if (i + 1 == item_num) ++skip;
                    extra[i] = items[i + skip];
                }
                items = new Product * [--count];
                for (int i = 0; i < count; ++i) items[i] = extra[i];
                delete[] extra;
                cout << "Успешно удалил товар!\n\n";
            }
        }
        else if (num == 6) {
            saveItemsList(filename, items, count);
            cout << "Успешно сохранил файл!\n\n";
        }
        else run = false;
    }
}

