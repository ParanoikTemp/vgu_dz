#include <iostream>
#include <string>
#include <vector>

using std::string; 
using std::cout;
using std::endl;
using std::vector;


// Справа те элементы, что больше. Слева - меньше.
struct STNode {
    string word;
    int count = 1;
    STNode* parent = nullptr;
    STNode *right = nullptr;
    STNode *left = nullptr;
    ~STNode() {
        right = nullptr;
        left = nullptr;
        parent = nullptr;
        delete right;
        delete left;
        delete parent;
    }
    STNode& operator= (const STNode& other) {
        word = other.word;
        count = other.count;
        right = other.right;
        left = other.left;
        return *this;
    }

};

class StringTree {
private:
    STNode* head = nullptr;
    int length = 0;
    void hardRemove(STNode* node, STNode* rmnode);
public:
    void insert(const string& word, int count = 1, STNode* node = nullptr);
    int remove(const string& word, STNode* node = nullptr, int side = 0, bool isHead = true);
    void printTree(STNode* node = nullptr, int level = 0, int side = 0, vector<int> nums = vector<int>());
    void printCount(STNode* node = nullptr, bool isHead = true);
    int findWord(const string &word, STNode* node = nullptr, int steps = 1, bool isHead = true);
};
