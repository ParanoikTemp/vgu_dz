struct StackElement {
  int value;
  StackElement* next = nullptr;
};

class Stack {
    private:
  StackElement* head = nullptr;
  int len = 0;
    public:
  ~Stack();
  
  int length();
  int pop();
  void push(int value);
  int show();
  void clear();
};

struct SOSNode {
  SOSNode* next;
  Stack* stack = new Stack();
};

class SetofStacks {
    private:
       SOSNode* head;
       int len = 0;
       int maxLength;
       
    public:
        SetofStacks(int maxLength);
        ~SetofStacks();
        
        int length();
        void push(int value);
        int pop();
        int popAt(int index);
};
