#include <iostream>
#include "sos.h"

using namespace std;

int main() {
    SetofStacks s(3);
    for (int i = 0; i < 14; ++i) s.push(i);
    int mem = s.length();
    while (s.length() > 3) {
        cout << s.popAt(1) << endl;
        if (s.length() != mem) {cout << "-\n"; mem = s.length();};
    }
    cout << "--\n";
    while (s.length() > 0) {
        cout << s.pop() << endl;
        if (s.length() != mem) {cout << "-\n"; mem = s.length();};
    }
    return 0;
}
