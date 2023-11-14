#include <iostream>
#include "Array.h"


using namespace std;

int main() {
    FlexArray<int> arr(5, 7), arr2(5, 4);
    arr.pushToIndex(19, -9);
    arr.remove(0, 5);
    arr[3] = 9;
    arr.replace(7, 2, 2);
    cout << arr << ' ' << arr2 << endl;
    arr2[2] = 18;
    arr.insertElements(arr2.begin() + 2, arr2.end() - 2, 2);
    cout << arr << endl;
    arr.replaceElements(arr2.begin(), arr2.end(), 1);
    cout << arr << ' ' << arr2 << endl;
    arr.removeElements(arr.begin() + 2, arr.begin() + 5);
    cout << arr << endl;
}
