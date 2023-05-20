#include "function.h"

int main() {
    int numbers[] = {3, 2, 3, 4, 3, 5,4, 5,5,5};
    Node* head = arrayToList(numbers, 10);
    cout << getCount(head);
    return 0;
}
