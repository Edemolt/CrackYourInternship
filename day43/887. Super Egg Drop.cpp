class Solution {
public:
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));
        int m = 0;
        while (dp[k][m] < n) {
            m++;
            for (int j = 1; j <= k; j++) {
                dp[j][m] = dp[j - 1][m - 1] + dp[j][m - 1] + 1;
            }
        }

        return m;
    }
};
