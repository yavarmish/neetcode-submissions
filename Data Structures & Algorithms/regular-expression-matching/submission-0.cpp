class Solution {
public:
    bool matchPattern(string &str, string &pattern, int i, int j, vector<vector<int>> &matchExists) {
        if(j >= pattern.size()) return i >= str.size();
        if(matchExists[i][j] != -1) return matchExists[i][j];

        bool charMatch = i < str.size() and (str[i] == pattern[j] or pattern[j] == '.');
        // * case
        if(j + 1 < pattern.size() and pattern[j + 1] == '*') {
            return matchExists[i][j] = matchPattern(str, pattern, i, j + 2, matchExists) or (charMatch and matchPattern(str, pattern, i + 1, j, matchExists));  // zero or more occurences
        }
        else return matchExists[i][j] = charMatch and matchPattern(str, pattern, i + 1, j + 1, matchExists);
    }
    bool isMatch(string str, string pattern) {
        int n = str.size(), m = pattern.size();
        vector<vector<int>> matchExists(n + 1, vector<int>(m + 1, -1));
        return matchPattern(str, pattern, 0, 0, matchExists);   
    }
};
