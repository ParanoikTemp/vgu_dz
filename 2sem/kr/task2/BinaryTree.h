#pragma once
#include <iostream>

using std::cout;
using std::max;

struct Node{
    int data;
    Node* right = nullptr;
    Node* left = nullptr;
    int getLevel(int level);
    void getMaxNum(int* nums, int* levels, int level);
};

class BinaryTree {
private:
    Node* root = nullptr;
    Node* insert(int num, Node* node);
    int getMaxLevel();
    void printSymmetric(Node* node);
public:
    void insert(int num);
    void printMaxElements();
    void printSymmetric();
};

