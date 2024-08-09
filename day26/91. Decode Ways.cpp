class Solution {
public:
    int fn(int ind, int n, string &s, vector<int> &dp){
        if(ind == n) return 1;
        if(s[ind] == '0') return 0; // No valid decoding starts with '0'
        if(dp[ind] != -1) return dp[ind];

        int ans = 0;

        // Consider single digit
        ans += fn(ind + 1, n, s, dp);

        // Consider two digits
        if(ind + 1 < n && (s[ind] == '1' || (s[ind] == '2' && s[ind + 1] <= '6'))) {
            ans += fn(ind + 2, n, s, dp);
        }

        return dp[ind] = ans;
    }
    
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n, -1); // Memoization array
        return fn(0, n, s, dp);
    }
};
