class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> maxProfitStates(n + 2, vector<int>(2, 0));
        for(int i = n - 1; i >=0; --i) {
            for(int buying = 0; buying <= 1; ++buying) {
                if(buying) 
                    maxProfitStates[i][buying] = max(maxProfitStates[i + 1][buying], maxProfitStates[i + 1][0] - prices[i]);
                else
                    maxProfitStates[i][buying] = max(maxProfitStates[i + 1][buying], maxProfitStates[i + 2][1] + prices[i]);
            }
        }
        return maxProfitStates[0][1];
    }
};
