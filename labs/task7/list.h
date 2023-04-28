#ifndef TASK7_1_LIST_H
#define TASK7_1_LIST_H
#include <iostream>
using namespace std;

struct Node {
    int data = 0;
    Node* prev = nullptr;
    Node* next = nullptr;
};

Node* newNode(const int* nums, int len);
void insertNode(Node* cur_node, int num);
void printNode(Node* node);
void func(Node* head);
Node* createNode();

#endif //TASK7_1_LIST_H
