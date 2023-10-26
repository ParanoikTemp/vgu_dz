#include<iostream>
#include<string>
#include"tree.h"
#include<fstream>
//#include <windows.h>

using namespace std;

int main()
{
    //SetConsoleOutputCP(CP_UTF8);
    //setlocale(LC_ALL, "RU");
    Tree tree, tree2;
    //ifstream file("C:\\cpp_files\\2sem\\structs\\Tree1\\words.txt");
    ifstream file("words.txt");
    if (file.is_open()) {
        string word;
        for (int i = 0; i < 250; ++i) {
            file >> word;
            tree.add(word);
        }
    }
    file.close();
    //ifstream file2("C:\\cpp_files\\2sem\\structs\\Tree1\\words2.txt");
    ifstream file2("words2.txt");
    if (file2.is_open()) {
        string word;
        for (int i = 0; i < 4; ++i) {
            file2 >> word;
            tree2.add(word, tree.removeElement(word));
        }
    }
    tree.printTree();
    cout << "\n\n\n\n";
    tree2.printTree();
    return 0;
}
