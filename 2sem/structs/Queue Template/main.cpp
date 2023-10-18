#include <iostream>
#include "queue.h"
#include <Windows.h>

using namespace std;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Enot enot("Аркадий", 2, 4.23), enot2("Акакий", 3, 5.23);
    Queue<Enot> racoons;
    racoons.enqueue(enot);
    racoons.enqueue(enot2);
    cout << racoons.dequeue();
    cout << racoons.dequeue();
}
