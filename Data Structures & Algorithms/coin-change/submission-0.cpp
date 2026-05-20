class Solution {
public:
    // Top down Time O(n) Space O(1)
    int getMinCoins(vector<int> &coins, int amount, vector<int> &dp) {        
        if(amount == 0) return 0;
        if(dp[amount] != -1) return dp[amount];
        int res = 1e9;
        for(int  i = 0; i < coins.size(); ++i) {
            if(coins[i] <= amount) {
                res = min(res, 1 + getMinCoins(coins, amount - coins[i], dp));
            }
        }
        return dp[amount] = res;
    }
    int coinChange(vector<int>& coins, int amount) {        
        vector<int> dp(amount + 1, -1);
        int res = getMinCoins(coins, amount, dp);
        return res == 1e9 ? -1 : res;
    }
};
