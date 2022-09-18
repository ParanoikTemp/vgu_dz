#include <iostream>

using namespace std;

int main()
{
    char text[] = "abc cbac bac acb abc abc abc ab acbac bac bca bac babababbcbcbcb";
    for (int i = 0;i <= sizeof(text) - 1;i++) {
        if (text[i] == 'c' && text[i + 1] == 'b') {
            for (int j = i + 2;j <= sizeof(text);j++) {
                text[j - 1] = text[j];
            }
        }
    }
    cout << text;

    return 0;
}
