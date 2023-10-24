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
    TreeNode* find(const string word);
    TreeNode* find(const string word, TreeNode* node);
    TreeNode* findPrev(const string word, TreeNode* node = nullptr);
    TreeNode* findMin(TreeNode* node = nullptr);
public:
    void add(const string word, TreeNode* node = nullptr);
    void printCount(TreeNode* node = nullptr);
    void printTree(TreeNode* node = nullptr, int level = 0, int side = 0);
    int removeElement(const string word);
    void setCount(const string word, const int count);
};
