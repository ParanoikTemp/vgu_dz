#include <iostream>
#include <string>
using namespace std;

int main() {
    string text;
    cin >> text;
    int max_len = 0, local_len = 0;
    for (char c: text) {
        if ('0' <= c && c <= '9') ++local_len;
        else {
            if (local_len > max_len) max_len = local_len;
            local_len = 0;
        }
    }
    cout << "Result: " << max_len;
}
