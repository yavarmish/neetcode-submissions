class Solution {
    vector<int> dx = {0, 1, -1, 0};
    vector<int> dy = {1, 0 , 0 , -1};
public:
    /*
        Border 0s and their neighbors won't be surrounded(multi source BFS)
        Time O(m*n) Space O(m*n)
    */
    void markUnsurroundedCellsUsingBfs(vector<vector<char>> &board, queue<pair<int,int>> &borderZeroesBfsQueue, vector<vector<bool>> &unsurroundedCells) {
        int n = board.size(), m = board[0].size();
        while(borderZeroesBfsQueue.size()) {
            int x = borderZeroesBfsQueue.front().first, y = borderZeroesBfsQueue.front().second;
            borderZeroesBfsQueue.pop();
            unsurroundedCells[x][y] = true;
            for(int k = 0; k < 4; ++k) {
                int nx = x + dx[k], ny = y + dy[k];
                if(nx < 0 or nx >= n or ny < 0 or ny >= m or unsurroundedCells[nx][ny] or board[nx][ny] == 'X') continue;
                borderZeroesBfsQueue.push({nx, ny});
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<bool>> unsurroundedCells(n, vector<bool>(m, 0));
        queue<pair<int,int>> borderZeroesBfsQueue;
        for(int i = 0; i < m; ++i) {
            if(board[0][i] == 'O') borderZeroesBfsQueue.push({0, i});
            if(board[n-1][i] == 'O') borderZeroesBfsQueue.push({n - 1, i});               
        }
        for(int i = 0; i < n; ++i) {
            if(board[i][0] == 'O') borderZeroesBfsQueue.push({i, 0});
            if(board[i][m - 1] == 'O') borderZeroesBfsQueue.push({i, m - 1});
        }

        markUnsurroundedCellsUsingBfs(board, borderZeroesBfsQueue, unsurroundedCells);
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) 
                if(board[i][j] == 'O' and !unsurroundedCells[i][j]) board[i][j] = 'X';
        }        
    }
};
