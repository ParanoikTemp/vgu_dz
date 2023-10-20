#include<iostream>
#include<string>
#include"tree.h"

using namespace std;

int main()
{
    string words[] = {"mama", "papa", "baba", "mama", "papa", "baba", "deda", "gena", "baba", "gena", "rima", "baba"}; // 12
    Tree tr;
    for (int i = 0; i < 12; ++i) tr.add(words[i]);
    tr.printCount();
    return 0;
}
