class Solution {
public:
    bool hasSubsetWithTargetSum(vector<int> &nums, int  i, int targetSum, vector<vector<int>> &dp) {
        if(targetSum == 0) return true;
        if(i == nums.size()) return false;
        if(dp[i][targetSum] != -1) return dp[i][targetSum];
        if(nums[i] <= targetSum) return dp[i][targetSum] = hasSubsetWithTargetSum(nums, i + 1, targetSum - nums[i], dp) or hasSubsetWithTargetSum(nums, i + 1, targetSum, dp);
        else return dp[i][targetSum] = hasSubsetWithTargetSum(nums, i + 1, targetSum, dp);
    }
    bool canPartition(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0), targetSum = 0;
        if(totalSum & 1) return false;
        else targetSum = totalSum / 2;
        vector<vector<int>> dp(nums.size(), vector<int>(targetSum + 1, -1));
        return hasSubsetWithTargetSum(nums, 0, targetSum, dp);
    }
};
