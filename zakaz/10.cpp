#include<iostream>
#include<cmath>

using namespace std;

int main()
{
    int len, element;
    cin >> len;
    int *array = new int [len];
    for (int i = 0; i < len; ++i) {array[i] = rand() % 50; cout << array[i] << " ";}
    cout << endl;
    cin >> element;
    int *new_array = new int [len + 1];
    for (int i = 0; i < len / 2; ++i) new_array[i] = array[i];
    new_array[len / 2] = element;
    for (int i = len / 2 + 1; i < len + 1; ++i) new_array[i] = array[i - 1];
    delete[] array;
    for (int i = 0; i < len + 1; ++i) cout << new_array[i] << " ";
    return 0;
}
