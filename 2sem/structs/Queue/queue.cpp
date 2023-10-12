#include "queue.h"

Queue::~Queue() {
    clear();
}

int Queue::getLength() const {
    return length;
}

void Queue::enqueue(const int value) {
    length += 1;
    if (length == 1) head = tail = new QueueNode{value};
    else {
        head = new QueueNode{value, head};
        head->next->prev = head;
    }
}

int Queue::dequeue() {
    length -= 1;
    int value = tail->value;
    QueueNode* rem = tail;
    if (length == 0) 
        head = tail = nullptr;
    else {
        tail = tail->prev;
        tail->next = nullptr;
    }
    delete rem;
    return value;
}

int Queue::peek() const {
    return tail->value;
}

void Queue::clear() {
    while (length > 0) dequeue();
}

bool Queue::include(const int value) const {
    for (QueueNode* node = head; node != nullptr; node = node->next)
        if (node->value == value) return true;
    return false;
}
int Queue::count(const int value) const {
    int cnt = 0;
    for (QueueNode* node = head; node != nullptr; node = node->next)
        if (node->value == value) ++cnt;
    return cnt;
}
