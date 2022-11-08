#include<iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int start = 0, end = -1, count = 0;
    bool flag = true;
    char k[] = "Hello! How do you do?";
    int len = sizeof(k) / sizeof(k[0]);
    for (int i = 0; i < len; ++i) {
        if (k[i] == ' ' || k[i] == ',' || k[i] == '.' || k[i] == '!' || k[i] == '?') {
            if (i == start) start += 1;
            else {
                end = i - 1;
                flag = true;
                for (int j = start; j <= end; ++j) {
                    count = 0;
                    for (int l = start; l <= end; ++l) if (k[l] == k[j]) ++count;
                    if (count > 1) {flag = false; break;}
                }
                if (flag) {for (int j = start; j <= end; ++j) cout << k[j]; cout << endl;}
                start = i + 1;
            }
        }
    }
}
