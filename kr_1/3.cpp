#include <iostream>

using namespace std;

int main() {
    char text[] = ")hi((ldksds)ds)kdskjdj(";
    int k = 0, count1 = 0, count2 = 0;
    bool flag = true;
    for (char i : text) {
        if (i == '(') {++k; ++count1;}
        else if (i == ')') {--k; ++count2;}
        if (k < 0) flag = false;
    }
    if (!k && flag) cout << "The brackets are correctly placed";
    else cout << "The brackets are not placed correctly";
    cout << endl << "Opening brackets: " << count1;
    cout << endl << "Closing brackets: " << count2;
    return 0;
}
