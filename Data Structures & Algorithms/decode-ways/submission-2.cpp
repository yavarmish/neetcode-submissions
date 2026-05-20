class Solution {
public:
    // Top down DP Time O(n) Space O(n)
    int countPossibleWays(string &s, int i, vector<int> &dp) {
        // Base case
        if(i == s.size()) return 1;        
        if(s[i] == '0') return 0;
        if(dp[i] != -1) return dp[i];
        // Recursion
        int res = countPossibleWays(s, i + 1, dp);
        if(i < s.size() -1 and stoi(s.substr(i, 2)) <= 26) res += countPossibleWays(s, i + 2, dp);
        return dp[i] = res;
    }
    int numDecodings(string s) {       
        vector<int> dp(s.size(), -1);
        return countPossibleWays(s, 0, dp);
    }
};
