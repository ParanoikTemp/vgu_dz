#include "tree.h"

void Tree::add(const string word, TreeNode* node)
{
    if (node == nullptr) node = head;
    if (node == nullptr) {
        head = node = new TreeNode{word};
        return;
    }
    int res = node->word.compare(word);
    if (res < 0) {
        if (node->right != nullptr) add(word, node->right);
        else node->right = new TreeNode{ word };
        return;
    }
    if (res > 0) {
        if (node->left != nullptr) add(word, node->left);
        else node->left = new TreeNode{ word };
        return;
    }
    node->count += 1;
    return;
}

void Tree::printCount(TreeNode* node) {
    if (node == nullptr) node = head;
    std::cout << node->word << ": " << node->count << std::endl;
    if (node->left != nullptr) printCount(node->left);
    if (node->right != nullptr) printCount(node->right);
}

void Tree::printTree(TreeNode* node, int level, int side) {
    if (node == nullptr) node = head;
    if (node == nullptr) return;
    if (node->left != nullptr) printTree(node->left, level + 1, 1);
    for (int i = 0; i < level; ++i) std::cout << "     ";
    if (side > 0) std::cout << '/';
    else if (side < 0) std::cout << '\\';
    std::cout << node->word << " [lvl: " << level << "]" << std::endl;
    if (node->right != nullptr) printTree(node->right, level + 1, -1);
}

TreeNode* Tree::findPrev(const string word, TreeNode* node) {
    if (node == nullptr) node = head;
    if (node->right != nullptr && node->right->word == word || node->left != nullptr && node->left->word == word) return node;
    int res = node->word.compare(word);
    if (res < 0 && node->right != nullptr) return findPrev(word, node->right);
    if (res > 0 && node->left != nullptr) return findPrev(word, node->left);
    return nullptr;
}

TreeNode* Tree::find(const string word) {
    TreeNode* prev = findPrev(word);
    if (prev == nullptr) {
        if (head->word == word) return prev;
        return nullptr;
    }
    if (prev->left != nullptr && prev->left->word == word) return prev->left;
    if (prev->right != nullptr && prev->right->word == word) return prev->right;
    return nullptr;
}

TreeNode* Tree::find(const string word, TreeNode* node) {
    if (node->right != nullptr && node->right->word == word) return node->right;
    return node->left;
}

int Tree::removeElement(const string word) {
    TreeNode* prev = findPrev(word);
    TreeNode* node = head;  // чисто шоб компилятор не ругался
    int count = 0;
    if (prev == nullptr) {
        node = find(word);
        if (node == nullptr) return 0;
        count = node->count;
        if (node->right == nullptr) {head = node->left; delete node; return count;}
        if (node->left == nullptr) {head = node->right; delete node; return count;}
    } else {
        node = find(word, prev);
        count = node->count;
        if (node->right == nullptr) {prev = node->left; delete node; return count;}
        if (node->left == nullptr) {prev = node->right; delete node; return count;}
    }
    TreeNode *minNode = findMin();
    string wrd = minNode->word;
    int cnt = removeElement(wrd);
    node->word = wrd;
    node->count = cnt;
    return count;
}

TreeNode *Tree::findMin(TreeNode *node) {
    if (node == nullptr) node = head;
    if (node == nullptr) return nullptr;
    if (node->right != nullptr) return findMin(node->right);
    return node;
}

void Tree::setCount(const string word, const int count) {
    return;
}

// Лаба в разработке
TreeNode::~TreeNode() {
    left = right = nullptr;
    delete left, right;
}
