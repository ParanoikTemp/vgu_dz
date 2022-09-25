#include <iostream>

using namespace std;

int main()
{
	int arr[] = {1, 2, 3, 5, 6, 7}, num;
    cout << "Введите число: "; cin >> num; cout << endl;
    int size = sizeof(arr) / sizeof(arr[0]);
    int* new_arr = new int[size + 1];
    new_arr[size / 2] = num;
    for (int i = 0; i < size; ++i) {
        if (i < size / 2) new_arr[i] = arr[i];
        if (i  >= size / 2) new_arr[i+1] = arr[i];
    }
    for (int i = 0; i < size + 1; ++i) cout << new_arr[i] << " ";
}