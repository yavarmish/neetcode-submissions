class Solution {
public:    
    // Bottom up Time O(n) Space O(n)
    int climbStairs(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = dp[1] = 1;
        for(int i = 2; i <= n; ++i) {
            dp[i] = dp[i - 2] + dp[i - 1]; 
        } 
        return dp[n];
    }
};
