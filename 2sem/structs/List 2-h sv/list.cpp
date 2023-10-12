#include "list.h"

void List::addHead(const int value) {
    length += 1;
    if (length == 1) {
        head = tail = new ListNode{value};
    } else {
        head = new ListNode{value, head};
        head->next->prev = head;
    }
}

void List::addEnd(const int value) {
    length += 1;
    if (length == 1) {
        head = tail = new ListNode{value};
    } else {
        tail = new ListNode{value, nullptr, tail};
        tail->prev->next = tail;
    }
}

void List::addAfterNum(const int after, const int value) {
    for (ListNode* node = head; node != nullptr; node = node->next) {
        if (node->value == after) {
            insert(node, value);
            node = node->next;
            length += 1;
        }
    }
}

void List::deleteNode(ListNode* node) {
    if (length > 0) length -= 1;
    if (length == 0) head = tail = nullptr; 
    else if (node->prev = nullptr) {
        head = head->next;
        head->prev = nullptr;
    } else if (node->next = nullptr) {
        tail = tail->prev;
        tail->next = nullptr;
    } else {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    delete node;
}

void List::remove(const int value) {
    for (ListNode* node = head; node != nullptr;) {
        if (node->value == value) {
            ListNode* delNode = node;
            node = node->next;
            deleteNode(delNode);
        } else node = node->next;
    }
}

void List::removeAfterNum(const int after) {
    for (ListNode* node = head; node != nullptr; node = node->next) {
        if (node->value == after) deleteNode(node->next);
    }
}

void List::removeHead() {
    deleteNode(head);
}

void List::clear() {
    while (length > 0) deleteNode(head);
}

void List::insert(ListNode* node, const int value) {
    node->next = new ListNode{node, node->next, node};
    if (node->next->next != nullptr)
        node->next->next->prev = node->next;
}

bool List::include(const int value) {
    for (ListNode* node = head; node != nullptr; node = node->next)
        if (node->value == value) return true;
    return false;
}

int List::get(const int index) {
    if (index >= 0) {
        ListNode* node = head;
        for (int i = 0; i < index; ++i) node = node->next;
    } else {
        ListNode* node = tail;
        for (int i = -1; i > index; --i) node = node->prev;
    }
    return node->value;
}
