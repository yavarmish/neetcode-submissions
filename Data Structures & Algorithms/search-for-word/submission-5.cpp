class Solution {
public:
    /* 
        Backtracking with visited array
        Time O(n * m * 4 ^ L) Space O(n * m + L) n -> rows, m -> columns, L -> length of word
    */
    vector<int> dx = {0, 1, -1, 0};
    vector<int> dy = {1, 0, 0, -1};
    bool wordExists(vector<vector<char>> &board, int i, int j, string &word, int wordIdx, vector<vector<int>> &visited) {    
        if(wordIdx == word.size()) return true;    
        if(i < 0 or i >= board.size() or j < 0 or j >= board[0].size() or visited[i][j] or word[wordIdx] != board[i][j]) return false;
        bool res = false;
        visited[i][j] = true;
        for(int k = 0; k < 4; ++k) 
            res |= wordExists(board, i + dx[k], j + dy[k], word, wordIdx + 1, visited);         
        visited[i][j] = false;
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        vector<vector<int>> visited(n, vector<int> (m, 0));
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(wordExists(board, i, j, word, 0, visited)) return true;
            }
        }
        return false;    
    }

};
