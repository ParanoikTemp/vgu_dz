struct QueueNode {
  int value;
  QueueNode* next = nullptr;
  QueueNode* prev = nullptr;
};

class Queue {
private:
    QueueNode* head = nullptr;
    QueueNode* tail = nullptr;
    int length = 0;
public:
    ~Queue();
    int getLength() const;
    void enqueue(const int value);
    int dequeue();
    int peek() const;
    void clear();
    bool include(const int value) const;
    int count(const int value) const;
};
