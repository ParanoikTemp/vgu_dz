template <typename Type>
struct QueueNode {
  Type value;
  QueueNode<Type>* next = nullptr;
  QueueNode<Type>* prev = nullptr;
};

template <typename Type>
class Queue {
private:
    QueueNode<Type>* head = nullptr;
    QueueNode<Type>* tail = nullptr;
    Type length = 0;
public:
    ~Queue();
    int getLength() const;
    void enqueue(const Type value);
    Type dequeue();
    Type peek() const;
    void clear();
    bool include(const Type value) const;
    int count(const Type value) const;
};
