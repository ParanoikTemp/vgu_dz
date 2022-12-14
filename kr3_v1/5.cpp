#include<string>

using namespace std;

int count(string str2, string str1) {
    int c = 0, ind = 0;
    while (str1.find(str2, ind) != string::npos) {
        ++c;
        ind = str1.find(str2, ind) + 1;
    }
    return c;
}
