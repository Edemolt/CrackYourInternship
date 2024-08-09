class Solution {
public:
    int fn(int ind, int sz, int m, int n, vector<string> &s, vector<vector<vector<int> > > &dp){
        if(ind == sz || (m == 0 && n == 0)) return 0; 
        if(m < 0 || n < 0) return -1e9;

        if(dp[ind][m][n] != -1) return dp[ind][m][n];

        int ans = 0;
        int mcnt = 0, ncnt = 0;
        for(char ch : s[ind]){
            if(ch == '0') mcnt += 1;
            else ncnt += 1;
        }

        if(m - mcnt >= 0 && n - ncnt >= 0) ans = 1 + fn( ind + 1, sz, m - mcnt, n - ncnt, s, dp);
        ans = max(ans, fn(ind + 1, sz, m, n, s, dp));

        return dp[ind][m][n] = ans;
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        // vector<vector<int> > v;
        int sz = strs.size();
       vector<vector<vector<int> > > dp(sz, vector<vector<int>>(m+1, vector<int>(n+1, -1)));
        return fn(0, sz, m, n, strs, dp);
    }
};