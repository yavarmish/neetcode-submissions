class Solution {
public:
    /*
        Time O(m * n) Space O(m)
        We only need the current row values at a given time to evaluate the next row
    */
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1);
        for(int  i = m - 2; i >= 0; --i) {
            for(int j = n - 2; j >= 0; --j) {
                dp[j] += dp[j + 1];
            }
        }
        return dp[0];
    }
};
