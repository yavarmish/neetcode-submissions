class MinStack {
public:
    // Bruteforce Time for getMin: O(n) Space: O(n)

    // Mantain min at each point Time: O(1) Space: O(n)
    stack<int> mainStack;
    stack<int> minStack;    
    void push(int val) {
        mainStack.push(val);
        minStack.size() ? minStack.push(min(minStack.top(), val)) : minStack.push(val);
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
