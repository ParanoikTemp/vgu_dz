struct ListNode {
  int value;
  ListNode* next = nullptr;
};

class List {
private:
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    int length = 0;
public:
    void addHead(const int value);
    void addEnd(const int value);
    void addAfterNum(const int after, const int value);
    void remove(const int value);
    void removeAfterNum(const int after);
    void removeHead();
    void clear();
    void insert(ListNode* node, const int value);
    void deleteNode(ListNode* node);
    
    bool include(const int value);
    int get(const int index);
};
