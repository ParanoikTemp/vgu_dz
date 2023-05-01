#include <iostream>
#include <string>
#include <set>
#include <windows.h>

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "Ru");
    string text;
    cin >> text; cout << endl;
    int count = 0, num = 0;
    for (char i : text) if (i == ',' || i == '.') ++count;
    auto* words = new string[count];
    for (char i : text) {
        if (i == '.') break;
        else if (i == ',') {++num; continue;}
        words[num] += i;
    }
    set <char> vowels {'a', 'e', 'i', 'o', 'u', 'y'};
    set <char> consonants {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z'};
    set <char> ringing {'b', 'd', 'g', 'j', 'l', 'm', 'n', 'r', 'v', 'w', 'y', 'z'};
    set <char> deaf{'p', 't', 'k', 'f', 's', 'h', 't'};
    set <char> inter{'p', 't', 'k', 'f', 's', 'h'};
    set <char> un, ring, letters, answer, df;
    for (int i = 0; i < count; ++i) {
        letters.clear();
        for (char & j : words[i]) letters.insert(j);
        set_intersection(letters.begin(), letters.end(), vowels.begin(), vowels.end(), inserter(answer, answer.begin()));
        vowels = answer; answer.clear();
        set_difference(consonants.begin(), consonants.end(), letters.begin(), letters.end(), inserter(answer, answer.begin()));
        consonants = answer; answer.clear();
        set_union(un.begin(), un.end(), letters.begin(), letters.end(), inserter(answer, answer.begin()));
        un = answer; answer.clear();
        set_intersection(letters.begin(), letters.end(), inter.begin(), inter.end(), inserter(answer, answer.begin()));
        inter = answer; answer.clear();
    }
    set_intersection(un.begin(), un.end(), ringing.begin(), ringing.end(), inserter(ring, ring.begin()));
    set_difference(deaf.begin(), deaf.end(), inter.begin(), inter.end(), inserter(df, df.begin()));
    for (char vowel : vowels) cout << vowel << " "; cout << endl;
    for (char consonant : consonants) cout << consonant << " "; cout << endl;
    for (char r : ring) cout << r << " "; cout << endl;
    for (char d : df) cout << d << " "; cout << endl;
    return 0;
}
