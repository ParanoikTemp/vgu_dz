#include <iostream>
#include <string>
#include <vector>
#include <fstream>

/*
 * В trie-дереве распечатать все слова минимальной длины и максимальной длины.
 */

using std::vector;
using std::cout;
using std::endl;
using std::string;

class TrieNode {
private:
    char letter;
    vector<TrieNode*> next;
public:
    TrieNode(char letter): letter(letter) {}
    TrieNode *getNextNode(char next_letter) const {
        for (TrieNode *node : next)
            if (node->letter == next_letter)
                return node;
        return nullptr;
    }
    TrieNode *createNextNode(char new_letter) {
        if (new_letter == '\0')
            next.insert(next.begin(), new TrieNode(new_letter));
        else
            next.push_back(new TrieNode(new_letter));
        return next[next.size() - 1];
    }
    char getLetter() const {
        return letter;
    }
    vector<TrieNode*> getNextLetters() const {
        return next;
    }
};

class TrieTree {
private:
    TrieNode* root;
    void addWord(string word, TrieNode *node) {
        if (word.empty()) {
            node->createNextNode('\0');
            return;
        }
        if (node->getNextNode(word[0]) == nullptr)
            addWord(word.substr(1), node->createNextNode(word[0]));
        else
            addWord(word.substr(1), node->getNextNode(word[0]));
    }
    int findMinLength(TrieNode *node, int len) {
        if (node != root && node->getLetter() == '\0')
            return len;
        int length = -1;
        for (TrieNode *node2 : node->getNextLetters()) {
            int x = findMinLength(node2, len + 1);
            if (length < 0 || x < length)
                length = x;
            if (x == len + 1) break;
        }
        return length;
    }
    int findMaxLength(TrieNode *node, int len) {
        if (node != root && node->getLetter() == '\0')
            return len;
        int length = -1;
        for (TrieNode *node2 : node->getNextLetters()) {
            int x = findMaxLength(node2, len + 1);
            if (length < 0 || x > length)
                length = x;
        }
        return length;
    }
    void printWord(TrieNode *node, string word, int length) {
        if (length == 0) {
            if (node->getNextNode('\0') != nullptr)
                cout << word << endl;
            else
                return;
        } else
            for (TrieNode *next_node : node->getNextLetters())
                printWord(next_node, word + next_node->getLetter(), length - 1);
    }
public:
    TrieTree() {
        root = new TrieNode('\0');
    }
    void addWord(string word) {
        if (word.size() == 0) return;
        addWord(word, root);
    }
    int getMinLength() {
        if (root->getNextLetters().empty()) return 0;
        return findMinLength(root, -1);
    }
    int getMaxLength() {
        if (root->getNextLetters().empty()) return 0;
        return findMaxLength(root, -1);
    }
    void printWords(int length) {
        string word;
        if (length <= 0) return;
        for (TrieNode *node : root->getNextLetters())
            printWord(node, word + node->getLetter(), length - 1);
    }
};

int main() {
    string filepath = "C:\\cpp_files\\task40\\words.txt";
    std::ifstream file(filepath);
    if (file.is_open()) {
        string word;
        TrieTree tree;
        while (!file.eof()) {
            file >> word;
            cout << word << endl;
            tree.addWord(word);
        }
        cout << tree.getMinLength() << ' ' << tree.getMaxLength() << endl;
        tree.printWords(tree.getMinLength());
        tree.printWords(tree.getMaxLength());
    }
    return 0;
}
