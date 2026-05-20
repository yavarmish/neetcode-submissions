class Solution {
    vector<int> dx = {0, 1, -1, 0};
    vector<int> dy = {1, 0, 0, -1};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int totalTime = 0, freshCount = 0;
        queue<pair<int, int>> rootenOrangesBfsQueue;
        for(int  i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(grid[i][j] == 2) rootenOrangesBfsQueue.push({i, j});
                else if(grid[i][j] == 1) ++freshCount;
            }
        }
        while(freshCount and rootenOrangesBfsQueue.size()) {
            int k = rootenOrangesBfsQueue.size();
            while(k--) {
                int x = rootenOrangesBfsQueue.front().first, y = rootenOrangesBfsQueue.front().second;
                rootenOrangesBfsQueue.pop();
                for(int k = 0; k < 4; ++k) {
                    int nx = x + dx[k], ny = y + dy[k];
                    if(nx < 0  or nx >=n  or ny < 0 or ny >=m  or grid[nx][ny] != 1) continue;
                    --freshCount;
                    grid[nx][ny] = 2;
                    rootenOrangesBfsQueue.push({nx, ny});
                }
            }
            ++totalTime;
        }
        return freshCount ? -1 : totalTime;    
    }
};
