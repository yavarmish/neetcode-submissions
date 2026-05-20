class Solution {
    vector<int> dx = {1, 0 , 0 , -1};
    vector<int> dy = {0, 1, -1, 0};
public:
    int getAreaOfCurrentIsland(vector<vector<int>>& grid, int i ,int j) {
        if(i < 0 or j < 0 or i >= grid.size() or j >= grid[0].size() or !grid[i][j]) return 0; 
        int res = 1;
        grid[i][j] = 0;
        for(int k = 0; k < 4; ++k) 
            res += getAreaOfCurrentIsland(grid, i + dx[k], j + dy[k]);
        return res;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int maxArea = 0;
        for(int i = 0 ; i < n ; ++i) {
            for(int j = 0; j < m; ++j) {
                if(grid[i][j])                     
                    maxArea = max(maxArea, getAreaOfCurrentIsland(grid, i, j));    
            }
        }
        return maxArea;
    }
};
