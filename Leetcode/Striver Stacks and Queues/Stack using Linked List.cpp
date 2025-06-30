class MyStack {
private:
    StackNode *top;

public:
    void push(int x) {
        StackNode* newNode = new StackNode(x);
        if (!newNode) {
            return;
        }
        if (top == NULL) {
            top = newNode;
        } else {
            newNode->next = top;
            top = newNode;
        }
    }

    int pop() {
        if (top == NULL) {
            return -1;
        }
        int val = top->data;
        top = top->next;
        return val;
    }

    MyStack() { top = NULL; }
};