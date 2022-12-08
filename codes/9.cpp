#include <iostream>

using namespace std;


int main()
{
    char text[] = "Hello,how,do,you,do,man?";
    int num = 0, len = sizeof text / sizeof text[0];
    for (int i = 0; i < len; ++i) {
        if (text[i] == ',') {
            if (num - i < 3) for (int j = num; j < i; ++j) cout << text[j];
        }
    }
}
