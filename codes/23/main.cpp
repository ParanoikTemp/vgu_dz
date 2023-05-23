#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

struct Book {
    char author[51];
    char title[101];
};

bool readBooksByAuthor(const std::string& authorName) {
    std::ofstream outputFile("C:\\cpp_files\\task6\\output.dat", std::ios::binary);
    if (!outputFile) {
        std::cerr << "Ошибка создания файла output.dat" << std::endl;
        return false;
    }

    std::ifstream inputFile("C:\\cpp_files\\task6\\books.dat", std::ios::binary);
    if (!inputFile) {
        std::cerr << "Ошибка открытия файла books.dat" << std::endl;
        return false;
    }

    Book book;
    bool foundBooks = false;
    while (inputFile.read((char*)&book, sizeof(Book))) {
        if (authorName == book.author) {
            std::cout << "Автор: " << book.author << std::endl;
            std::cout << "Название произведения: " << book.title << std::endl;
            std::cout << std::endl;
            outputFile.write((char*)&book, sizeof(Book));
            foundBooks = true;
        }
    }

    inputFile.close();
    return foundBooks;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "RU");
    std::string authorName;
    std::cout << "Введите имя автора: ";
    std::getline(std::cin, authorName);

    if (readBooksByAuthor(authorName)) {
        std::cout << "Файл создан";
    } else std::cout << "Ошибка создания файла!";

    return 0;
}
