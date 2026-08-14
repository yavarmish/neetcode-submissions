class Solution {
    vector<vector<int>> dp;
public:
    int getMaxCoins(vector<int> &nums, int i, int j) {
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int res = 0;
        for(int k = i; k <= j; ++k) {
            // Choose the last balloon to burst
            int coins = nums[k] * nums[i - 1] * nums[j + 1];
            coins += getMaxCoins(nums, i, k - 1);
            coins += getMaxCoins(nums, k + 1, j);
            res = max(coins, res);
        }
        return dp[i][j] = res;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();
        dp.resize(n, vector<int>(n, -1));
        return getMaxCoins(nums, 1, n - 2);
    }
};
