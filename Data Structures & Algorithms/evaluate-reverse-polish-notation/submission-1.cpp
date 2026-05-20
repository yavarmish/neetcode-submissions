class Solution {
public:
    bool isOperator(string &s) {
        return s == "+" or s == "-" or s == "/" or s == "*";
    }
    int evalOperation(stack<int> &evalRes, string token) {
        int firstElement = evalRes.top();evalRes.pop();
        int secondElement = evalRes.top();evalRes.pop();

        if(token == "+")      
            return secondElement + firstElement;
        else if(token == "*")
            return secondElement * firstElement;
        else if(token == "/")
            return secondElement / firstElement;
        else 
            return secondElement - firstElement;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> evalRes;
        for(string &token : tokens) {
            if(isOperator(token)) evalRes.push(evalOperation(evalRes, token));        
            else evalRes.push(stoi(token));
        }
        return evalRes.top();        
    }
};
