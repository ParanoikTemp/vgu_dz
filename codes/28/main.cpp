#include "list.h"

int main() {
    int len1 = 10, len2 = 10;
    int nums1[] = {1, 2, 2, 3, 6, 9, 4, 2, 2, 4};
    int nums2[] = {5, 6, 7, 4, 3, 8, 5, 1, 3, 7};
    Node* list1 = makeList(nums1, len1);
    Node* list2 = makeList(nums2, len2);
    cout << "Input lists:\n";
    printList(list1); cout << endl;
    printList(list2); cout << endl;
    cout << "Output list:\n";
    Node* list3 = setList(list1, list2);
    printList(list3);
    return 0;
}
