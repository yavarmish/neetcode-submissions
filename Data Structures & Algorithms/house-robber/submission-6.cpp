    // Top down Time O(n) Space O(n) 
    class Solution {
    public:
        int getMaxMoney(vector<int> &nums, int i, vector<int> &dp) {
            if(i >= nums.size()) return 0;
            else if(dp[i] != -1) return dp[i];
            else return dp[i] = max(nums[i] + getMaxMoney(nums, i + 2, dp), getMaxMoney(nums, i + 1, dp));
        }
        int rob(vector<int>& nums) {
            int n = nums.size();
            vector<int> dp(n, -1);
            return getMaxMoney(nums, 0, dp);
        }    
    };