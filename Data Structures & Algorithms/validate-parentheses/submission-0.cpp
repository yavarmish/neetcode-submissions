class Solution {
public:
    bool isValid(string s) {
        stack<int> bracketStack;
        unordered_map<char, char> bracketMapping;
        bracketMapping[']'] = '['; bracketMapping['}'] = '{'; bracketMapping[')'] = '(';
        for(char &ch : s) {
            cout<<ch<<"\n";
            if(ch == '(' or ch == '{' or ch == '[') bracketStack.push(ch);
            else if(bracketStack.size() and bracketMapping[ch] == bracketStack.top()) bracketStack.pop();
            else return false;            
        }
        return !bracketStack.size();
    }
};
