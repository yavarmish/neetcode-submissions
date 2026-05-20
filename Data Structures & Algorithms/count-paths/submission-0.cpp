class Solution {
public:
    int countUniquePaths(int m, int n, vector<vector<int>> &dp) {
        if(m < 0 or n < 0) return 0;
        if(m == 0 and n == 0) return 1;
        if(dp[m][n] != -1) return dp[m][n];
        else return dp[m][n] = countUniquePaths(m, n - 1, dp) + countUniquePaths(m - 1, n, dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return countUniquePaths(m - 1, n - 1, dp);
    }
};
