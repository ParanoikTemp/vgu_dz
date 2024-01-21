#include "Queue.h"

void Queue::insert(int num) {
    if (len == 0) {
        head = tail = new Node{num};
    } else {
        tail->next = new Node{num, tail};
        tail = tail->next;
    }
    ++len;
}

void Queue::replace(int num, int new_num) {
    for (Node* node = head; node != nullptr; node = node->next)
        if (node->data == num)
            node->data = new_num;
}

void Queue::print() {
    for (Node* node = head; node != nullptr; node = node->next)
        cout << node->data << ' ' ;
}
