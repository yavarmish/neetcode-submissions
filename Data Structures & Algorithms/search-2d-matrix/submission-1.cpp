class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = 0, j = matrix.size() - 1, mid, targetRow;
        while(i <= j) {
            mid = i + (j - i) / 2;
            if(matrix[mid][0] == target) return true;
            else if(matrix[mid][0] < target) {
                targetRow = mid;
                i = mid + 1;
            }
            else j = mid - 1;
        }   
        i = 0, j = matrix[0].size() - 1;
        while(i <= j) {
            mid = i + (j - i)/2;
            if(matrix[targetRow][mid] == target) return true;
            else if(matrix[targetRow][mid] < target) i = mid + 1;
            else j = mid - 1;
        }
        return false;
    }
};
