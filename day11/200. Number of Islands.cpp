class Solution {
public:
    void dfs(int x, int y, int m, int n, vector<vector<char> > &grid, vector<vector<int> > &vis){
        vis[x][y] = 1;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, -1, 0, 1};

        for(int i = 0; i < 4; i++){
            int nrow = x + drow[i];
            int ncol = y + dcol[i];

            if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && grid[nrow][ncol] == '1' &&
            !(vis[nrow][ncol])) dfs(nrow, ncol, m, n, grid, vis);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int> > vis(m, vector<int>(n,0));
        int cnt = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1' && !(vis[i][j])){
                    dfs(i, j, m, n, grid, vis);
                    cnt += 1;
                }
            }
        }
        return cnt;
    }
};