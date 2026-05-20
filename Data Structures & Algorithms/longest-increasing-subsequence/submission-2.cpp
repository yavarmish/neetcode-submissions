class Solution {
public:
    // Top Down Time O(n ^ 2) Space O(n ^ 2)
    int longestLength(vector<int> &nums, int  i, int j, vector<vector<int>> &dp) {
        if(i == nums.size()) return 0;
        if(dp[i][j + 1] != -1) return dp[i][j + 1];
        int res = 0;
        if(j == -1 or nums[i] > nums[j]) res = max(res, 1 + longestLength(nums, i + 1, i, dp));        
        res = max(res, longestLength(nums, i + 1, j, dp));
        return dp[i][j + 1] = res;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return longestLength(nums, 0, -1, dp);
    }
};
