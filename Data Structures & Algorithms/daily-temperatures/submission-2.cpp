class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);
        stack<pair<int, int>> s;

        for(int i = 0; i < n; ++i) {
            while(s.size()) {
                pair<int, int> topElement = s.top();
                int temperature = topElement.first, index = topElement.second;
                if(temperature >= temperatures[i]) break;
                res[index] = i - index;
                s.pop();
            }
            s.push({temperatures[i], i});
        }
        return res;
    }
};
