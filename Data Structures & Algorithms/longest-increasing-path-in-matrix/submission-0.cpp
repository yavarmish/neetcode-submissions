class Solution {
    vector<int> dx = {0, 1, -1, 0};
    vector<int> dy = {1, 0, 0 , -1};
public:
    int populateAllLongestPaths(vector<vector<int>> &matrix, int i, int j, int prev, vector<vector<int>> &longestPath) {
        if(i < 0 or j < 0 or i >= matrix.size() or j >= matrix[0].size() or prev >= matrix[i][j]) return 0;
        if(longestPath[i][j] != -1) return longestPath[i][j];
        int res = 1;
        for(int k = 0; k < 4; ++k) {
            res = max(res, 1 + populateAllLongestPaths(matrix, i + dx[k], j + dy[k], matrix[i][j], longestPath));
        }
        return res;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> longestPath(n, vector<int>(m, -1));

        int longestIncreasingPath = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                longestIncreasingPath = max(longestIncreasingPath, populateAllLongestPaths(matrix, i, j, INT_MIN, longestPath));
            }
        }
        return longestIncreasingPath;
    }
};
