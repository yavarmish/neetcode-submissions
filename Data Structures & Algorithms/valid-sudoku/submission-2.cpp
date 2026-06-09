class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool seenRow[9][10], seenCol[9][10];
        bool seenBox[3][3][10];

        for(int i = 0; i < 9; ++i) {
            for(int j = 0; j < 9; ++j) {
                if(board[i][j] != '.') {
                    int val = board[i][j] - '1';
                    if(seenRow[i][val] or seenCol[j][val] or seenBox[i/3][j/3][val]) return false;
                    seenRow[i][val] = seenCol[j][val] = seenBox[i/3][j/3][val] = true;
                }
            }
        }
        return true;
    }
};
