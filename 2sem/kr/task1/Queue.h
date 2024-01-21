#pragma once
#include <iostream>

using std::cout;

struct Node {
    int data;
    Node* prev = nullptr;
    Node* next = nullptr;
};

class Queue {
private:
    Node* head;
    Node* tail;
    int len = 0;
public:
    void insert(int num); // Добавление элемента
    void replace(int num, int new_num); // Замена элементов
    void print(); // печать очереди
};
