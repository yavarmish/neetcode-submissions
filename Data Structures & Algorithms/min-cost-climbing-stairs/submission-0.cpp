class Solution {
public:
    // Top down Time O(n) Space O(n)
    int getMinCost(vector<int> &cost, int i, vector<int> &dp) {
        if(i == cost.size()) return 0;
        else if(dp[i] != -1) return dp[i];
        else return dp[i] = min(cost[i] + getMinCost(cost, i + 1, dp), cost[i] + getMinCost(cost, i + 2, dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1, -1);        
        return min(getMinCost(cost, 0, dp), getMinCost(cost, 1, dp));
    }
};
