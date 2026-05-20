class Solution {
    vector<int> dx = {0, 1, -1, 0};
    vector<int> dy = {1, 0, 0, -1};
public:
    // DFS Time O(n*m) Aux Space O(1)
    void markIslandVisitedUsingDFS(vector<vector<char>> &grid, int i, int j) {
        if(i >= grid.size() or j >= grid[0].size() or i < 0 or j < 0 or grid[i][j] == '0') return;
        grid[i][j] = '0';
        for(int k = 0; k < 4; ++k) 
            markIslandVisitedUsingDFS(grid, i + dx[k], j + dy[k]);        
    }
    int numIslands(vector<vector<char>>& grid) {
        int islandCount = 0, n = grid.size(), m = grid[0].size();
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(grid[i][j] == '1') {
                    markIslandVisitedUsingDFS(grid, i, j);
                    ++islandCount;
                }
            }
        }
        return islandCount;
    }
};
