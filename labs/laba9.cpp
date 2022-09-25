#include <iostream>

using namespace std;

int main()
{
    	char text[] = "276362726363736626", check;
    	cout << "Введите символ: "; cin >> check; cout << endl;
    	for (int i = 0; i < sizeof(text); ++i) {
    	    if (text[i] == check) cout << i << endl;
    	}
}