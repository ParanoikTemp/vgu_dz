#include "sos.h"

int Stack::length() {
    return len;
}

int Stack::show() {
    return head->value;
}

void Stack::push(int value) {
    len += 1;
    head = new StackElement{value, head};
}

int Stack::pop() {
    len -= 1;
    StackElement* node = head;
    head = head->next;
    node->next = nullptr;
    return node->value;
}

void Stack::clear() {
    while (head != nullptr) this->pop();
}

Stack::~Stack() {
    this->clear();
}

SetofStacks::SetofStacks(int length) {
    maxLength = length;
}

int SetofStacks::length() {
    return len;
}

void SetofStacks::push(int value) {
    if (len == 0 || head->stack->length() == maxLength) {
        len += 1;
        head = new SOSNode{head};
        head->stack->push(value);
    } else head->stack->push(value);
}

SetofStacks::~SetofStacks() {
    while (len != 0) this->pop();
}

int SetofStacks::pop() {
    int number = head->stack->pop();
    if (head->stack->length() == 0) {
        len -= 1;
        SOSNode* delNode = head;
        head = head->next;
        delete delNode->stack;
        delNode->next = nullptr;
        delNode->stack = nullptr;
    }
    return number;
}

int SetofStacks::popAt(int index) {
    if (index == 0) return this->pop();
    SOSNode* delNode = head, *prev;
    for (int i = 0; i < index; ++i) {
        prev = delNode;
        delNode = delNode->next;
    }
    int number = delNode->stack->pop();
    if (delNode->stack->length() == 0) {
        len -= 1;
        prev->next = delNode->next;
        delete delNode->stack;
        delNode->next = nullptr;
        delNode->stack = nullptr;
    }
    return number;
}
