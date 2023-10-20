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

// Лаба в разработке
