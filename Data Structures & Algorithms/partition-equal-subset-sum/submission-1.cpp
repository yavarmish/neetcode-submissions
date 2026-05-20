class Solution {
public:
    // Bottom up Time O(n * targetSum) Space O(targetSum)
    bool canPartition(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0), targetSum = 0;
        if(totalSum & 1) return false;
        else targetSum = totalSum / 2;
        vector<int> dp(targetSum + 1, 0);
        dp[0] = 1;

        for(int i = 0; i < nums.size(); ++i) {
            for(int j = targetSum; j >= 0; --j) {
                if(nums[i] <= j) dp[j] |= dp[j - nums[i]];
            }
        }
        return dp[targetSum];
    }
};
