#include <iostream>

using namespace std;

int main() {
    int num, count = 0;
    cin >> num;
    for (int i = 1, j = num - 1; i < num; ++i, --j) if (i + j == num) ++count;
    cout << endl << count;
}
