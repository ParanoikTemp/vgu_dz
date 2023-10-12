#include <iostream>
using namespace std;

struct StackNode {
  int value;
  StackNode* next = nullptr;
};

class Stack {
private:
    StackNode* head = nullptr;
    int length = 0;
public:
    ~Stack();
    int getLength() const;
    void push(int value);
    int peek() const;
    int pop();
    void clear();
    bool include(int value) const;
    int count(int value) const;
};
