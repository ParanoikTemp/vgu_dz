#include <iostream>

using namespace std;

int main()
{
    char nums[] = "39708569096543.", base[] = "0123456789", winner = '.';
    int max = -1, count, j;
    for (int i = 0; i < 10; ++i) {
        count = 0;
        j = 0;
        while (nums[j] != '.') {
            if (nums[j] == base[i]) ++count;
            ++j;
        }
        if (count > max) {
            max = count;
            winner = base[i];
        }
    }
    cout << "Чаще всего встречается цифра: " << winner;
    return 0;
}
