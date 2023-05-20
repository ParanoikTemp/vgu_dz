#include <iostream>
#include <string>

using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* arrayToList(int arr[], int n);
int getCount(Node* head);
