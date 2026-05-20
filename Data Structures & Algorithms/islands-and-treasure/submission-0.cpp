#define INF INT_MAX
class Solution {
    vector<int> dx = {0, 1, -1, 0};
    vector<int> dy = {1, 0, 0 , -1};
public:
    // Multi source BFS from treasures Time  O(m*n) Space O(m*n)
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int>> treasureBfsQueue;
        for(int i = 0; i < n; ++i) {
            for(int  j = 0; j < m; ++j) {
                if(grid[i][j] == 0) treasureBfsQueue.push({i, j});
            }
        }

        while(treasureBfsQueue.size()) {
            // treasure distance
            int x = treasureBfsQueue.front().first, y = treasureBfsQueue.front().second;
            treasureBfsQueue.pop();
            for(int k = 0; k < 4; ++k) {
                int nx = x + dx[k], ny = y + dy[k];
                if(nx < 0 or  ny < 0 or nx >= n  or ny >=m or grid[nx][ny] != INF) continue;
                grid[nx][ny] = grid[x][y] + 1;
                treasureBfsQueue.push({nx, ny});                
            }
        }        
    }
    // Add dfs(Time O(n*m*4^(m*n)), bfs(Time O(n*m)^2)(Space for both O(m*n)) from lands solution
};
