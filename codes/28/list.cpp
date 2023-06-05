#include "list.h"

Node* makeList(const int nums[], int len) {
    Node* head = new Node{nums[0]};
    Node* node = head;
    for (int i = 1; i < len; ++i, node = node->next) node->next = new Node{nums[i]};
    return head;
}

void printList(Node* head) {
    for (Node* node = head;node != nullptr;node = node->next) cout << node->num << ' ';
}

bool inList(Node* head, int num) {
    for (Node* node = head;node != nullptr;node = node->next) if (node->num == num) return true;
    return false;
}

Node* setList(Node *head1, Node *head2) {
    Node *head = nullptr;
    Node *node = nullptr;
    for (Node *node1 = head1; node1 != nullptr; node1 = node1->next) {
        if (!inList(head, node1->num) && !inList(head2, node1->num)) {
            if (head == nullptr) {
                head = new Node{node1->num};
                node = head;
            } else {
                node->next = new Node{node1->num};
                node = node->next;
            }
        }
    }
    return head;
}
