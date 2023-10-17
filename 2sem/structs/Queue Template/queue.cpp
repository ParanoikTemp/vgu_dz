#include "queue.h"

template <typename Type>
Queue<Type>::~Queue() {
    clear();
}

template <typename Type>
int Queue<Type>::getLength() const {
    return length;
}

template <typename Type>
void Queue<Type>::enqueue(const Type value) {
    length += 1;
    if (length == 1) head = tail = new QueueNode<Type>{value};
    else {
        head = new QueueNode<Type>{value, head};
        head->next->prev = head;
    }
}

template <typename Type>
Type Queue<Type>::dequeue() {
    length -= 1;
    int value = tail->value;
    QueueNode<Type>* rem = tail;
    if (length == 0) 
        head = tail = nullptr;
    else {
        tail = tail->prev;
        tail->next = nullptr;
    }
    delete rem;
    return value;
}

template <typename Type>
Type Queue<Type>::peek() const {
    return tail->value;
}

template <typename Type>
void Queue<Type>::clear() {
    while (length > 0) dequeue();
}

template <typename Type>
bool Queue<Type>::include(const Type value) const {
    for (QueueNode<Type>* node = head; node != nullptr; node = node->next)
        if (node->value == value) return true;
    return false;
}

template <typename Type>
int Queue<Type>::count(const Type value) const {
    int cnt = 0;
    for (QueueNode<Type>* node = head; node != nullptr; node = node->next)
        if (node->value == value) ++cnt;
    return cnt;
}
