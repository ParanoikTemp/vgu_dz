#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    /*
     * Когда мы открываем файл у нас появляется курсор.
     * При считывании, этот курсор перемещается вперед, так что каждый раз вы будете получать
     * следующую информацию, после той, которую прочли.
     *
     * Также важно помнить, что при открытии файла для записи, если такого нет, то программа его создаст.
     * Если такой файл есть, то программа его ОБНУЛИТ и вы проебете все данные
     */
    // названия файлов
    string num_filename = "C:\\cpp_files\\files\\nums.txt";  // файл с числами
    string words_filename = "C:\\cpp_files\\files\\words.txt";  // файл с словами
    string output_filename = "C:\\cpp_files\\files\\output.txt";  // файл для вывода
    string bin_filename = "C:\\cpp_files\\files\\file.bin";  // файл бинарный

    /////////////////////// Числа
    ifstream num_file(num_filename);  // открытие файла

    if (!num_file.is_open()) {  // проверка на то, открыт ли файл
        cout << "Error open file with numbers";
        return 1;
    }

    int count;
    // мы можем взять ПЕРВОЕ число, которое в нашем случае - количество чисел во второй строке
    // здесь мы используем структуру аналогично cin
    num_file >> count;
    // далее курсор остановился на пробеле, то есть в count у нас число 4
    int *nums = new int[count];

    for (int i = 0; i < count; ++i) {
        // далее будет каждый раз считываться следующее число
        num_file >> nums[i];
    }

    ///////////////////////

    /////////////////////// Строки
    ifstream words_file(words_filename);  // открытие файла

    if (!words_file.is_open()) {  // проверка на то, открыт ли файл
        cout << "Error open file with words";
        return 1;
    }

    string word, words, words2, txtnum;

    words_file >> word; // Так МОЖНО! Но так считывается только ОДНО слово до пробела.
    // То есть сейчас в переменной word у нас слово "Hello,".

    getline(words_file, words); // getline считывает текст ДО конца строки. То есть с учетом списанного первого слова
    // у нас в words сейчас слова "world! My name is Nikita."

    // Однако у getline есть интересная фишка. Мы можем поставить символ ДО которого он будет считывать, например
    getline(words_file, words2, ',');  // у нас в words2 сейчас слова "I like oranges"

    getline(words_file, words2, '|');
    // а теперь тут текст " bananas and pizdit bad people.\nI am"

    int num;  // предположим нам нужно считать из текста число. Сделать это можно так
    getline(words_file, txtnum, '|');  // сейчас в txtnum у нас строка "18"
    // Если вам повезет, то у вас будет работать функция stoi(), что расшифровывается как string to int
    num = stoi(txtnum);  // теперь тут число 18

    char word2[6];  // Мы можем взять определенное количество символов в массив символов
    words_file.read(word2, 6);  // делается это вот так :3
    // ну и мы можем это дело перенести в строку
    string chartxt(words2);  // теперь у нас тут строка " years"

    ///////////////////////

    /////////////////////// Запись
    num = 123;
    string text = "Hello, world";
    char chars[6] = "Hello";

    ofstream output_file(output_filename);  // В этот файл будет производиться запись

    // в принципе есть два вариант
    output_file << num << ' ' << text << '\n';  // это первый

    // второй
    output_file.write(chars, sizeof(chars));
    // тут прервый аргумент - массив символов, второй - сколько символов будет записано

    ///////////////////////

    /////////////////////// Бинарная запись и чтение

    // Суть бинарных файлов в том, что все записывается в одну строку байтами, так что для нормальной работы
    // вам по хорошему нужно знать сколько места занимает ваша инфа.
    // Структуры вам врядли придется записывать на экзамене, если че сами найдите как их записывать.
    // в принципе запись и чтение почти идентичны как и с обычными файлами. Просто упор делается именно на байты и их четкое количество.

    ofstream bin_file(bin_filename, ios::binary);

    bin_file << "Hello";

    ifstream bin_file2(bin_filename, ios::binary);
    char chars3[6];
    bin_file2.read(chars3, 6);

    // я устал я спать. Не забывайте закрывать файлы

    num_file.close();
    words_file.close();
    output_file.close();
    bin_file.close();
    bin_file2.close();
    return 0;
}
