/*
 * Файл "Каталог книг"
 * - Структура записи:
 * - - Автор ... 40 знаков
 * - - Название ... 80 знаков
 * - - Год издания ... 4 знака
 * - - Специальность ... 40 знаков
 *
 * № 17 Создать файл "Каталог книг". По заданной специальности занести в отдельный файл сведения обо всех изданиях
 */
#include "funcs.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "Ru");
    const string input_file_name = "D:\\cpp_files\\task6.1\\books.txt";
    const string database_file_name = "D:\\cpp_files\\task6.1\\database.bin";
    const string output_file_name = "D:\\cpp_files\\task6.1\\result.txt";
    int books_count = 0;
    bool result = makeDatabase(input_file_name, database_file_name, books_count);
    if (!result) {cout << "Ошибка при создании БД!"; return 0;}
    result = Interface(database_file_name, output_file_name, books_count);
    if (!result) {cout << "Работа программы была прекращена в связи с ошибкой!";}
    return 0;
}