#include <iostream>
#include <windows.h>

using namespace std;

struct Node {
    double num;
    Node* next = nullptr;
};

Node* makeList(const double nums[], int count);
bool isArithmeticProgression(Node* list);
bool isGeometricProgression(Node* list);