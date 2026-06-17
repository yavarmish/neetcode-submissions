class Solution {
    stack<string> resStack;
    unordered_set<string> ops = {"+", "-", "*", "/"};
public:
    bool isOperator(string &s) {
        return ops.count(s);
    }
    int evalRes(string &token, stack<string> &resStack) {
        int val1, val2, val;
        val1 = stoi(resStack.top());
        resStack.pop();
        val2 = stoi(resStack.top());
        resStack.pop();

        if(token == "+") {
            val = val2 + val1;
        }
        else if(token == "-") {
            val = val2 - val1;
        }
        else if(token == "*") {
            val = val2 * val1;
        }
        else val = val2 / val1;

        return val;
    }
    int evalRPN(vector<string>& tokens) {
        for(auto &token : tokens) {
            if(isOperator(token)) {
                int val = evalRes(token, resStack);
                resStack.push(to_string(val));
            }
            else resStack.push(token);
        }
        return stoi(resStack.top());
    }
};
