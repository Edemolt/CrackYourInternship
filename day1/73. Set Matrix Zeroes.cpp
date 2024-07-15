class Solution {
public:

    void turn0(int x, int y, int n, int m, vector<vector<int> > &grid, vector<vector<int> > &vis){
        for(int i = 0; i < n; i++){
            if(grid[i][y] == 0) continue;
            grid[i][y] = 0;
            vis[i][y] = 1;
        }
        for(int j = 0; j < m; j++){
            if(grid[x][j] == 0) continue;
            grid[x][j] = 0;
            vis[x][j] = 1;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int> > vis(n, vector<int>(m,0));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == 0 && !(vis[i][j])) turn0(i,j,n,m,matrix, vis);
            }
        }
    }
};