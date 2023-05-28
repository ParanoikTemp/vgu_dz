#include "listcode.h"

Node* makeList(const double nums[], int count) {
    Node* head = new Node{nums[0]};
    Node* node = head;
    for (int i = 1; i < count; ++i, node = node->next) node->next = new Node{nums[i]};
    return head;
}

bool isArithmeticProgression(Node* list) {
    Node* head = list;
    if (head == nullptr || head->next == nullptr) return false;
    double b = head->next->num - head->num;
    for (; head->next != nullptr; head = head->next) if (abs((head->next->num - head->num) - b) > 0.00000001) return false;
    return true;
}

bool isGeometricProgression(Node* list) {
    Node* head = list;
    if (head == nullptr || head->next == nullptr) return false;
    double b = head->next->num / head->num;
    for (; head->next != nullptr; head = head->next) if (abs((head->next->num / head->num) - b) > 0.00000001) return false;
    return true;
}
