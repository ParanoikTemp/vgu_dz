#include <iostream>

using namespace std;

int main() {
    char text[] = "ABCSCBIOS";
    for (int i = 0; i < sizeof(text) / sizeof(text[0]) - 1; ++i) {
        if (text[i] > text[i + 1]) {
            cout << "The text is not written in alphabetical order";
            return 0;
        }
    }
    cout << "The text is written in alphabetical order";
    return 0;
}
