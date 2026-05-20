class Solution {
public:
    // Top down DP Time  O(t * m * n) Space O(n)
    bool isBreakable(string &s, int i, vector<string> &wordDict, vector<int> &dp) {
        if(i == s.size()) return true;  
        if(dp[i] != -1) return dp[i];      
        for(int  j = 0; j < wordDict.size(); ++j) {
            if(s.find(wordDict[j], i) == i) {
                if(isBreakable(s, i + wordDict[j].size(), wordDict, dp)) return dp[i] = true;
            }
        }
        return dp[i] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size(), -1);
        return isBreakable(s, 0, wordDict, dp);
    }
};
