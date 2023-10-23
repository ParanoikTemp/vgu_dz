#include<iostream>
#include<string>
#include"tree.h"
#include<fstream>

using namespace std;

int main()
{
    Tree tree;
    ifstream file("words.txt");
    if (file.is_open()) {
        string word;
        for (int i = 0; i < 250; ++i) {
            file >> word;
            tree.add(word);
        }
    }
    tree.printTree();
    return 0;
}
