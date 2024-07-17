class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int> > dp(m+1, vector<int>(n+1, 0));

        for(int i = 1; i <= n; i++) dp[1][i] = grid[0][i-1] + dp[1][i-1];
        for(int j = 1; j <= m; j++) dp[j][1] = grid[j-1][0] + dp[j-1][1];

        for(int i = 2; i <= m; i++){
            for(int j = 2; j <= n; j++) dp[i][j] = grid[i-1][j-1] + min(dp[i-1][j], dp[i][j-1]);
        }
        return dp[m][n];
    }
};