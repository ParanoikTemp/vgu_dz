#include <iostream>
using namespace std;

int main() {
    char stroke[] = "Stroke";
    int num, stroke_len = sizeof stroke / sizeof stroke[0] - 1;
    cin >> num;
    if (num > stroke_len) cout << "The entered number is greater than the string length";
    else if (num < stroke_len) cout << "The entered number is less than the string length";
    else cout << "The entered number is equal to the string length";
}
