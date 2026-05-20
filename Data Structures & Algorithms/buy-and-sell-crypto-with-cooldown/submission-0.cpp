class Solution {
public:
    int getMaxProfit(vector<int> &prices, int idx, int buying, vector<vector<int>> &maxProfitStates) {
        if(idx >= prices.size()) return 0;
        if(maxProfitStates[idx][buying]) return maxProfitStates[idx][buying];
        if(buying) {
            return max(getMaxProfit(prices, idx + 1, 0, maxProfitStates) - prices[idx], getMaxProfit(prices, idx + 1, 1, maxProfitStates));
        }
        else {
            return max(getMaxProfit(prices, idx + 1, 0, maxProfitStates), prices[idx] + getMaxProfit(prices, idx + 2, 1, maxProfitStates));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> maxProfitStates(n, vector<int>(2, 0));
        return getMaxProfit(prices, 0, 1, maxProfitStates);
    }
};
