const int mod = 1e9 + 7;
class Solution {
public:
    int countPalindromicSubsequences(string s) {
        int n = s.size();
        vector<vector<long long> > dp(n, vector<long long>(n, 0));

        for(int i = 0; i < n; i++) dp[i][i] = 1;

        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                if (s[i] == s[j]) {
                    int left = i + 1, right = j - 1;
                    while (left <= right && s[left] != s[i]) left++;
                    while (left <= right && s[right] != s[i]) right--;
                    
                    if (left > right) {
                        dp[i][j] = (dp[i + 1][j - 1] * 2 + 2) % mod;
                    } else if (left == right) {
                        dp[i][j] = (dp[i + 1][j - 1] * 2 + 1) % mod;
                    } else {
                        dp[i][j] = (dp[i + 1][j - 1] * 2 - dp[left + 1][right - 1] + mod) % mod;
                    }
                } else {
                    dp[i][j] = (dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1] + mod) % mod;
                }
            }
        }

        return dp[0][n - 1];
    }
};