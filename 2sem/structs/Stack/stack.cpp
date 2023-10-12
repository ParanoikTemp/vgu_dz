#include "struct.h"

Stack::~Stack() {clear();};

int Stack::getLength() const {
    return length;
}

void Stack::push(const int value) {
    head = new StackNode{value, head};
    length += 1;
}

int Stack::peek() const {
    return head->value;
}

int Stack::pop() {
    if (length > 0) {
        length -= 1;
        StackNode* rem = head;
        head = head->next;
        int value = rem->value;
        delete rem;
        return value;
    }
    return 0;
}

void Stack::clear() {
    while (length > 0) pop();
}

bool Stack::include(const int value) const {
    for (StackNode* node = head; node != nullptr; node = node->next)
        if (node->value == value) return true;
    return false;
}

int Stack::count(const int value) const {
    int cnt = 0;
    for (StackNode* node = head; node != nullptr; node = node->next)
        if (node->value == value) ++cnt;
    return cnt;
}
