class Solution {
    vector<int> dx = {0, 1, -1, 0};
    vector<int> dy = {1, 0, 0, -1};
public:
    /* 
        Multi source BFS starting from both oceans 
        Time O(m*n) Space O(m*n)
    */
    void markVisitableCellsUsingBfs(vector<vector<bool>>& visitableCells, queue<pair<int,int>>& bfsQueue, vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        while(bfsQueue.size()) {
            int x = bfsQueue.front().first, y = bfsQueue.front().second;
            bfsQueue.pop();
            visitableCells[x][y] = true;
            for(int k = 0; k < 4; ++k) {
                int nx = x + dx[k], ny = y + dy[k];
                if(nx < 0 or ny < 0 or nx >= n or ny >= m or visitableCells[nx][ny] or heights[nx][ny] < heights[x][y]) continue;
                bfsQueue.push({nx, ny});
            }            
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<bool>> pacificVisitableCells(n, vector<bool>(m, false)), atlanticVisitableCells(n, vector<bool>(m, false));
        queue<pair<int, int>> pacificBfsQueue, atlanticBfsQueue;
        for(int i = 0; i < m; ++i) {
            pacificBfsQueue.push({0, i});
            atlanticBfsQueue.push({n-1, i});
        }
        for(int i = 0; i < n; ++i) {
            pacificBfsQueue.push({i, 0});
            atlanticBfsQueue.push({i, m - 1});
        }

        markVisitableCellsUsingBfs(pacificVisitableCells, pacificBfsQueue, heights);
        markVisitableCellsUsingBfs(atlanticVisitableCells, atlanticBfsQueue, heights);

        vector<vector<int>> resultantCells;
        for(int i = 0; i < n; ++i) {
            for(int j = 0 ; j < m; ++j) {
                if(pacificVisitableCells[i][j] and atlanticVisitableCells[i][j]) resultantCells.push_back({i,j});
            }
        }
        return resultantCells;
    }
};
