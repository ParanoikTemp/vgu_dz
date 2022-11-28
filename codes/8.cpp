#include <iostream>
#include <string>
using namespace std;
bool isAlpha(char c) {
    return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z';
}

bool isZnak(char c) {
    return c == '+' || c == '-' || c == '*';
}

bool isNumber(char c) {
    return c >= '0' && c <= '9';
}

int main()
{
    int groupAlpha = 0, groupZnak = 0, groupNumber = 0, groupExtra = 0, type;
    string word;
    cin >> word;
    word += '.';
    char extra, c;
    if (isAlpha(word[0])) {type = 1; extra = word[0];}
    else if (isNumber(word[0])) type = 2;
    else type = 3;
    for (int i = 0; i < word.length(); ++i) {
        c = word[i];
        if (isAlpha(c) && type != 1 || isNumber(c) && type != 2 || isZnak(c) && type != 3 || c == '.') {
            if (type == 1) {
                ++groupAlpha;
                if (word[i - 1] == extra) ++groupExtra;
            }
            else if (type == 2) ++groupNumber;
            else ++groupZnak;
            if (isAlpha(c)) {
                if (type != 1) extra = c;
                type = 1;
            }
            else if (isNumber(c)) type = 2;
            else type = 3;
        }
    }
    if (groupAlpha > groupZnak) cout << "True";
    else cout << "False";
    cout << endl << groupExtra;
    return 0;

}
