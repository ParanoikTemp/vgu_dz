#include<iostream>

using namespace std;

int main()
{
    char letters[26], letter;
    for (int i = 0; i < 26; ++i) letters[i] = 97 + i;
    while (letter != ' ') {
        cin.get(letter);
        if (letter <= 'z' && letter >= 'a') for (int i = 0; i < 26; ++i) if (letters[i] == letter) letters[i] = '.';
    }
    for (int i = 0; i < 26; ++i) if (letters[i] != '.') cout << letters[i];
}
