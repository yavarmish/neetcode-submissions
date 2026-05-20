class Solution {
public:
    int getMinimumEdits(string &word1, string & word2, int i, int j, vector<vector<int>> operationsPerformed) {
        if(j == word2.size()) return word1.size() - i;
        if(i == word1.size()) return word2.size() - j;

        if(operationsPerformed[i][j] != -1) return operationsPerformed[i][j];

        if(word1[i] == word2[j]) return operationsPerformed[i][j] = getMinimumEdits(word1, word2, i + 1, j + 1, operationsPerformed);
        else {
            int res = min(getMinimumEdits(word1, word2, i + 1, j, operationsPerformed), getMinimumEdits(word1, word2, i, j + 1, operationsPerformed));
            res = min(res, getMinimumEdits(word1, word2, i + 1, j + 1, operationsPerformed));
            return operationsPerformed[i][j] = 1 + res;
        }
    }
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> operationsPerformed(n, vector<int>(m, -1));
        return getMinimumEdits(word1, word2, 0, 0, operationsPerformed);
    }
};
