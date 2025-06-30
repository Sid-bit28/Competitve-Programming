class MinStack {
public:
    vector<int> stack;
    vector<int> minVal;
    MinStack() {
        stack.clear();
        minVal.clear();
    }

    void push(int val) {
        stack.push_back(val);
        if (minVal.empty()) minVal.push_back(val);
        else minVal.push_back(min(minVal.back(), val));
    }

    void pop() {
        stack.pop_back();
        minVal.pop_back();
    }

    int top() {
        return stack.back();
    }

    int getMin() {
        return minVal.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */