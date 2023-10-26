#include <iostream>

using std::string;

struct TreeNode
{
    string word;
    int count = 1;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;
    ~TreeNode();
};

class Tree
{
private:
    TreeNode* head = nullptr;
    void remove(TreeNode* node, TreeNode* rmnode);
public:
    void add(const string word, int count = 1, TreeNode* node = nullptr);
    void printCount(TreeNode* node = nullptr);
    void printTree(TreeNode* node = nullptr, int level = 0, int side = 0);
    int removeElement(const string word, TreeNode* node = nullptr, int level = 0);
    void setCount(const string word, const int count);
};
