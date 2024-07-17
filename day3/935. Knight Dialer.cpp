const int mod = 1e9 +7;
class Solution {
public:
    vector<vector<int> > jumps = {
            {4,6},
            {6,8},
            {7,9},
            {4,8},
            {3, 9, 0},
            {},
            {1,7,0},
            {2,6},
            {1,3},
            {2,4}
        };
    int find(int n, int ind, vector<vector<int> > &dp){
        if( n == 0) return 1;

        if(dp[n][ind] != 0) return dp[n][ind];

        int ans = 0;
        for(int jump : jumps[ind]) ans = (ans + find(n-1, jump, dp)) % mod;

        return dp[n][ind] = ans;
        
    }
    int knightDialer(int n) {
        

        vector<vector<int> > dp(n+1, vector<int>(10, 0));
        int ans = 0;
        for(int i = 0; i < 10; i++) ans = ((ans % mod) + find(n-1, i, dp)%mod )%mod;

        return ans;
    }
};