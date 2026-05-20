class Solution {
public:
    /*
        Time O(n * m) Space O(1)
        Matrix
        [1, 2, 3]
        [4, 5, 6]
        [7, 8, 9]

        Transpose
        [1, 4, 7]
        [2, 5, 8]
        [3, 6, 9]
        
        Reverse rows
        [7, 4, 1]
        [8, 5, 2]
        [9, 6, 3]

        Effectively
        a[i][j] -> a[j][i] -> a[j][m-i-1] 

        Same as required
        0, 0 -> 0, m - 1 
        0, 1 -> 1, m - 1  
        0, 2 -> 2, m - 1
        1, 0 -> 0, m - 2
        1, 1 -> 1, m - 2
        1, 2 -> 2, m - 2
        2, 0 -> 0, m - 3
        2, 1 -> 1, m - 3
        2, 2 -> 2, m - 3

        Reversing rows and then transposing leads to 90 degrees anticlockwise rotation
    */

    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < m; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(int i = 0; i < n; ++i) {
            reverse(matrix[i].begin(), matrix[i].end());
        }        
    }
};
