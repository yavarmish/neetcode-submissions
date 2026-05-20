class Solution {
public:
    // Bottom up Time O(n) Space O(n)
    int getMaxMoney(vector<int> &nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = nums[0], dp[1] = max(nums[0], nums[1]);
        for(int  i = 2; i < n; ++i) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i-1]);    
        }
        return dp[n - 1];   
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        vector<int> nums1(nums.begin(), nums.end() - 1), nums2(nums.begin() + 1, nums.end());
        return max(getMaxMoney(nums1), getMaxMoney(nums2));
    }
};
