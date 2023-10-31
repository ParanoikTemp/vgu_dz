#include <string>
#include "StringTree.h"
#include <fstream>
#include <windows.h>


using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "RU");
    StringTree tree;
    ifstream file("C:\\cpp_files\\2sem\\structs\\tree1.2\\words.txt");
    string word;
    for (int i = 0; i < 250; ++i) {
        file >> word;
        tree.insert(word);
    }
    file.close();
    tree.printTree();
    cout << "\n\n\n";
    StringTree tree2;
    ifstream file2("C:\\cpp_files\\2sem\\structs\\tree1.2\\words2.txt");
    for (int i = 0; i < 4; ++i) {
        file2 >> word;
        tree2.insert(word, tree.remove(word));
    }
    tree2.printTree();
    cout << "\n\n\n";
    tree.printTree();
    return 0;
}
