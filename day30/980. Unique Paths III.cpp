class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int start_x, start_y, empty = 1;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    start_x = i;
                    start_y = j;
                } else if (grid[i][j] == 0) {
                    empty++;
                }
            }
        }
        
        return dfs(grid, start_x, start_y, empty);
    }
    
private:
    int dfs(vector<vector<int>>& grid, int x, int y, int empty) {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == -1)
            return 0;
        
        if (grid[x][y] == 2)
            return empty == 0 ? 1 : 0;
        
        grid[x][y] = -1;
        empty--;
        
        int paths = dfs(grid, x+1, y, empty) + dfs(grid, x-1, y, empty) +
                    dfs(grid, x, y+1, empty) + dfs(grid, x, y-1, empty);
        
        grid[x][y] = 0;
        empty++;
        
        return paths;
    }
};