class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);
        stack<int> tempStack;
        for(int i = 0; i < n; ++i) {
            while(tempStack.size() and temperatures[tempStack.top()] < temperatures[i]) {
                int idx = tempStack.top();
                tempStack.pop();
                res[idx] = i - idx;
            }
            tempStack.push(i);
        }
        return res;
    }
};
