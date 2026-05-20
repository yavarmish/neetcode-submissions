class Solution {
public:
    bool formAllPossibleStrings(string &s1, int i, string &s2, int j, string &s3, int k, vector<vector<int>> &dp) {
        if(k == s3.size()) {
            return i == s1.size() and j == s2.size();
        }
        if(dp[i][j] != -1) return dp[i][j];
        bool res = false;
        if(i < s1.size() and s1[i] == s3[k]) {
            res |= formAllPossibleStrings(s1, i + 1, s2, j, s3, k + 1, dp);
        }
        if(j < s2.size() and s2[j] == s3[k]) {
            res |= formAllPossibleStrings(s1, i, s2, j + 1, s3, k +1, dp);
        }  
        return dp[i][j] = res;
    }
    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, -1));
        return formAllPossibleStrings(s1, 0, s2, 0, s3, 0, dp);
    }
};
