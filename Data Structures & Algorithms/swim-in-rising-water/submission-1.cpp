class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        // Dijkstra
        int n = grid.size(), ans = max(grid[0][0], grid[n-1][n-1]);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> bfsQueue;
        vector<vector<int>> visited(n, vector<int>(n, 0));
        visited[0][0] = 1;
        vector<int> dirx = {-1, 1, 0, 0};
        vector<int> diry = {0, 0, 1, -1};
        bfsQueue.push({ans, 0, 0});
        while (bfsQueue.size()) {
            auto cur = bfsQueue.top();
            bfsQueue.pop();
            ans = max(ans, cur[0]);
            for (int i = 0; i < 4; ++i) {
                int r = cur[1] + dirx[i], c = cur[2] + diry[i];
                if (r >= 0 && r < n && c >= 0 && c < n && visited[r][c] == 0) {
                    if (r == n-1 && c == n-1) return ans;
                    bfsQueue.push({grid[r][c], r, c});
                    visited[r][c] = 1;
                }
            }
        }
        return 0;
    }
};
