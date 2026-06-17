class MinStack {
    stack<int> mainStack, minStack;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        mainStack.push(val);
        int minNum = minStack.size() ? min(minStack.top(), val) : val;
        minStack.push(minNum);
    }
    
    void pop() {
        mainStack.pop();
        minStack.pop();
    }
    
    int top() {
        return mainStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};
