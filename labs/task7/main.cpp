#include "list.h"

// Дан список. После каждого элемента добавить предшествующую ему часть списка.

int main() {
    Node* head = createNode();
    func(head);
    printNode(head);
    return 0;
}
