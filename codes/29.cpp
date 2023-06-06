#include <iostream>
#include <string>
#include <sstream>

using namespace std;

char updChar(char c, bool mode) {
    if ('a' <= c && c <= 'z' && !mode) return char(c - 'a' + 'A');
    if ('A' <= c && c <= 'Z' && mode) return char(c - 'A' + 'a');
    return c;
}

string updateWord(string& word, bool first_word) {
    string new_word;
    if (first_word) {
        int i = 0;
        for (char c: word) {new_word += updChar(c, i); ++i;}
    } else {
        int count = 0;
        for (char c: word) {
            if ('A' <= c && c <= 'Z') ++count;
            if (count > 1) break;
        }
        for (char c: word) new_word += updChar(c, bool(count <= 1));
    }
    return new_word;
}

int main() {
    string text = "Kak zhe ZAEbali eTi Labi. blya ti bi ZnaL, realno. Hochu ubit Billa.";
    string new_text;
    stringstream stext(text);
    bool first_mode = true;
    while (!stext.eof()) {
        string word;
        stext >> word;
        new_text += updateWord(word, first_mode);
        new_text += ' ';
        if (first_mode) first_mode = false;
        if (word[word.length() - 1] == '.') first_mode = true;
    }
    cout << new_text;
    return 0;
}
