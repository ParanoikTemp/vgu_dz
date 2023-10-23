#include "tree.h"

void Tree::add(const string word, TreeNode* node)
{
	if (node == nullptr) node = head;
	if (node == nullptr) {
	    head = node = new TreeNode{word};
	    return;
	}
	int res = node->word.compare(word);
	if (res > 0) {
		if (node->right != nullptr) add(word, node->right);
		else node->right = new TreeNode{ word };
		return;
	}
	if (res < 0) {
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
    if (node->right != nullptr) printCount(node->right);
    if (node->left != nullptr) printCount(node->left);
}

void Tree::printTree(TreeNode* node, int level, int side) {
    if (node == nullptr) node = head;
    if (node->right != nullptr) printTree(node->right, level + 1, 1);
    for (int i = 0; i < level; ++i) std::cout << "     ";
    if (side > 0) std::cout << '/';
    else if (side < 0) std::cout << '\\';
    std::cout << node->word << " [" << level << "]" << std::endl;
    if (node->left != nullptr) printTree(node->left, level + 1, -1);
}

// Лаба в разработке
