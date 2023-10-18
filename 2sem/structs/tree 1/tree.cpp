#include "tree.h"

void Tree::add(const string word, TreeNode* node = nullptr)
{
	if (node == nullptr) node = head;
	switch (node->word.compare(word))
	{
	case 1:
		if (node->right != nullptr) add(word, node->right);
		else node->right = new TreeNode{ word };
		return;
	case -1:
		if (node->left != nullptr) add(word, node->left);
		else node->left = new TreeNode{ word };
		return;
	case 0:
		node->count += 1;
		return;
	}
}
