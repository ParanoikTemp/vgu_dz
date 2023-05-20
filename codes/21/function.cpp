#include "function.h"

Node* arrayToList(int arr[], int n) {
    Node* head = nullptr;
    for (int i = 0; i < n; i++) {
        Node* newNode = new Node();
        newNode->data = arr[i];
        newNode->next = nullptr;
        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }
    return head;
}

int getCount(Node* head) {
    int count = 0;
    for (int i = 0; head->next->next != nullptr; ++i, head = head->next) {
        if (head->data == head->next->next->data) ++count;
    }
    return count;
}