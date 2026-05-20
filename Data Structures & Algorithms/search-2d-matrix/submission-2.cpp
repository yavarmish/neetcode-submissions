class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Time : O(log(n*m)) Space: O(1)
        int topRow = 0, bottomRow = matrix.size() - 1, midRow, targetRow;
        while(topRow <= bottomRow) {
            midRow = topRow + (bottomRow - topRow) / 2;
            if(matrix[midRow][0] == target) return true;
            else if(matrix[midRow][0] < target) {
                targetRow = midRow;
                topRow = midRow + 1;
            }
            else bottomRow = midRow - 1;
        }   
        return binary_search(matrix[targetRow].begin(), matrix[targetRow].end(), target);
    }
};
