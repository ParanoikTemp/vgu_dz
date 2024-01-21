#include "BinaryTree.h"

void BinaryTree::insert(int num) {
    root = insert(num, root);
}

Node* BinaryTree::insert(int num, Node* node) {
    if (node == nullptr)
        return new Node{num};
    else if (node->data < num)
        node->right = insert(num, node->right);
    else if (node->data > num)
        node->left = insert(num, node->left);
    return node;
}

int BinaryTree::getMaxLevel() {
    if (root != nullptr)
        return root->getLevel(1);
    return 0;
}

void BinaryTree::printMaxElements() {
    int maxLevel = getMaxLevel();
    int* nums = new int[maxLevel];
    int* levels = new int(0);
    if (root != nullptr)
        root->getMaxNum(nums, levels,1);
    for (int i = 0; i < maxLevel; ++i)
        cout << nums[i] << ' ';
}

void BinaryTree::printSymmetric() {
    printSymmetric(root);
}

void BinaryTree::printSymmetric(Node *node) {
    if (node == nullptr)
        return;
    printSymmetric(node->left);
    cout << node->data << ' ';
    printSymmetric(node->right);
}

int Node::getLevel(int level) {
    if (right == nullptr && left == nullptr)
        return level;
    int a = 0, b = 0;
    if (right != nullptr)
        a = right->getLevel(level + 1);
    if (left != nullptr)
        b = left->getLevel(level + 1);
    return max(a, b);
}

void Node::getMaxNum(int *nums, int *levels, int level) {
    if (*levels < level) {
        nums[level - 1] = data;
        ++(*levels);
    } else
        if (nums[level - 1] < data)
            nums[level - 1] = data;
    if (right != nullptr)
        right->getMaxNum(nums, levels, level + 1);
    if (left != nullptr)
        left->getMaxNum(nums, levels, level + 1);
}
