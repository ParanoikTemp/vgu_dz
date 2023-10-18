#include <iostream>


using std::string;

struct TreeNode
{
	string word;
	int count = 1;
	TreeNode* left = nullptr;
	TreeNode* right = nullptr;
};

class Tree
{
private:
	TreeNode* head = nullptr;
public:
	void add(const string word, TreeNode* node = nullptr);
};

