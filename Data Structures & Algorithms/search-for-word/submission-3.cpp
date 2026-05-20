class Solution {
public:
    vector<int> dx = {0, 1, -1, 0};
    vector<int> dy = {1, 0, 0, -1};
    bool wordExists(vector<vector<char>> &board, int i, int j, string &word, int wordIdx, vector<vector<int>> &visited) {        
        if(i < 0 or i >= board.size() or j < 0 or j >= board[0].size() or word[wordIdx] != board[i][j]) return false;
        if(wordIdx + 1 == word.size()) return true;
        visited[i][j] = true;
        for(int k = 0; k < 4; ++k) {
            if(i + dx[k] >= 0  and i + dx[k] < board.size() and j + dy[k] >= 0 and j + dy[k] < board[0].size() and 
                !visited[i + dx[k]][j + dy[k]] and wordExists(board, i + dx[k], j + dy[k], word, wordIdx + 1, visited))
                return true;
        }
        visited[i][j] = false;
        return false;
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
