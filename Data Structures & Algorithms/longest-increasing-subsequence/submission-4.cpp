class Solution {
public:
    // Top Down : if cur > prev max(take, notake) else notake Time O(n ^ 2) Space O(n ^ 2)
    int longestLength(vector<int> &nums, int  i, int j, vector<vector<int>> &dp) {
        if(i == nums.size()) return 0;
        if(dp[i][j + 1] != -1) return dp[i][j + 1];        
        if(j == -1 or nums[i] > nums[j]) return dp[i][j + 1] = max(1 + longestLength(nums, i + 1, i, dp), longestLength(nums, i + 1, j, dp));        
        else return dp[i][j + 1] = longestLength(nums, i + 1, j, dp);        
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return longestLength(nums, 0, -1, dp);
    }
};
