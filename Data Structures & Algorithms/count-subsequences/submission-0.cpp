class Solution {
public:
    int getDistinctSubsequnces(string &s, string &t, int i, int j, vector<vector<int>> &distinctSubsequencesCount) {
        if(j == t.size()) return 1;
        if(i == s.size()) return 0;
        if(distinctSubsequencesCount[i][j] != -1) return distinctSubsequencesCount[i][j];
        int res = 0;
        if(s[i] == t[j]) {
            res += getDistinctSubsequnces(s, t, i + 1, j + 1, distinctSubsequencesCount);
        }
        res += getDistinctSubsequnces(s, t, i +1, j, distinctSubsequencesCount);

        return distinctSubsequencesCount[i][j] = res;
    }
    int numDistinct(string s, string t) {
        if(s.size() < t.size()) return 0;
        vector<vector<int>> distinctSubsequencesCount(s.size(), vector<int>(t.size(), -1));
        return getDistinctSubsequnces(s, t, 0, 0, distinctSubsequencesCount);
    }
};
