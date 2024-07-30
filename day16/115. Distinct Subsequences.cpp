class Solution {
public:
    int find(string &s, string &t,int ind1, int ind2, int n, int m, vector<vector<int> > &dp){
        if(ind2 >= m) return 1;
        if(ind1 >= n) return 0;

        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];

        int res1 = find(s, t, ind1 + 1, ind2, n, m, dp);
        if(s[ind1] == t[ind2]) res1 += find(s, t, ind1 + 1, ind2 + 1, n, m, dp);

        return dp[ind1][ind2] = res1;
    }
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();

        vector<vector<int> > dp(n, vector<int>(m, -1));

        return find(s,t,0,0,n,m, dp);
    }
};