#include<iostream>

using namespace std;

int main()
{
    int n, count;
    cin >> n;
    char **chars = new char * [n], x;
    cin >> x;
    for (int i = 0; i < n; ++i) {
        chars[i] = new char [n];
        for (int j = 0; j < n; ++j) chars[i][j] = (char) rand() % 256;
    }

    for (int i = 0; i < n; ++i) {
        count = 0;
        for (int j = 0; j < n; ++j) {
            if (chars[i][j] == x) ++count;
            cout << chars[i][j] << " ";
        }
        cout << "| " << count << endl;
    }
    return 0;
}
