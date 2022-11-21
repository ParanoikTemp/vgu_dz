#include <iostream>

using namespace std;

int main() {
    char a, b;
    cin >> a;
    cin >> b;
    while (b != '.') {
        if (a > b) {
            cout << "The text is not written in alphabetical order";
            return 0;
        }
        a = b;
        cin >> b;
    }
    cout << "The text is written in alphabetical order";
    return 0;
}
