#include <string>
#include "StringTree.h"
#include <fstream>
#include <windows.h>


using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    StringTree tree;
    ifstream file("C:\\Users\\evstigneev_na\\Desktop\\cpp\\tree1.2\\words.txt");
    string word;
    for (int i = 0; i < 250; ++i) {
        file >> word;
        tree.insert(word);
    }
    file.close();
    tree.printTree();
    cout << "\n\n\n";
    tree.printCount();
    cout << "\n\n\n";
    int count = tree.findWord("Море");
    cout << "Слов найдено: " << count;
    return 0;
}
