#include <iostream>

using namespace std;

int main()
{
	int count;
	cout << "Введите количество интервалов: "; cin >> count; cout << endl;
	int* nums = new int[count * 2];
	for (int i = 0; i < count * 2; ++i) {
	    cout << "Введите значение a" << i + 1 << ": "; cin >> nums[i]; cout << endl;
	}
	int total;
	bool flag = false;
	for (int i = 0; i < count * 2; ++i) {
	    total = 0;
	    for (int j = 0; j < count * 2; j += 2) {
	        if (nums[j] < nums[i] && nums[j + 1] > nums[i] || nums[j] > nums[i] && nums[j + 1] < nums[i]) total += 1;
	        if (total == 3) {
	            cout << "Точка найдена: "  << nums[i];
	            flag = true;
	            break;
	        }
	    }
	    if (flag) break;
	}
}
