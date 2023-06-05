#include <iostream>

using namespace std;

struct Node {
    int num;
    Node* next = nullptr;
};

Node* makeList(const int nums[], int len);
void printList(Node* head);
bool inList(Node* head, int num);
Node* setList(Node *head1, Node *head2);
