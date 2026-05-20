class Solution {
public:    
    // Top down Time O(n) Space O(n)
    int getSteps(int n, vector<int> &dp) {
        if(n == 0 or n == 1) return 1;
        else if(dp[n]) return dp[n];
        else return dp[n] = getSteps(n-1, dp) + getSteps(n-2, dp);
    }
    int climbStairs(int n) {
        vector<int> dp(n + 1, 0);
        return getSteps(n, dp);
    }    
};
