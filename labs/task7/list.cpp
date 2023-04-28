#include "list.h"

Node* newNode(const int* nums, int len) {
    Node* head = new Node{nums[0]};
    Node* node = head;
    for (int i = 1; i < len; ++i) {
        node->next = new Node{nums[i], node};
        node = node->next;
    }
    return head;
}

void insertNode(Node* cur_node, int num) {
    Node* node = new Node{num, cur_node->prev, cur_node};
    cur_node->prev->next = node;
    cur_node->prev = node;
}

void printNode(Node* node) {
    for (Node* h = node; h != nullptr; h = h->next) {
        cout << h->data << " ";
    }
}

void func(Node* head) {
    int num = 1;
    for (Node* h = head, *h2 = head; h != nullptr; h = h->next, num *= 2, h2 = head) for (int i = 0; i < num - 1; ++i, h2 = h2->next) insertNode(h, h2->data);
    //    for (Node* h = head; h != nullptr; h = h->next) {
    //        Node *h2 = head;
    //        for (int i = 0; i < num - 1; ++i) {
    //            insertNode(h, h2->data);
    //            h2 = h2->next;
    //        }
    //        num *= 2;
    //    }
}

Node* createNode() {
    int cnt;
    cout << "Enter count numbers: "; cin >> cnt; cout << endl;
    int* nums = new int[cnt];
    cout << "Enter numbers: "; for (int i = 0; i < cnt; ++i) cin >> nums[i]; cout << endl;
    return newNode(nums, cnt);
}