class Solution {
public:
    int solve(int l, int r, int n, vector<int> &arr, int k, vector<vector<int> > &dp){
        if(k == 0) return 0;
        if(dp[l][r] != -1) return dp[l][r];
        int ans = arr[l] + solve(l + 1, r, n, arr, k-1, dp);
        ans = max(ans, arr[r] + solve(l, r-1, n, arr, k-1, dp));

        return dp[l][r] = ans;
    }
    int maxScore(vector<int>& arr, int k) {
        int n = arr.size();

        int lsum = 0, rsum = 0, mx = 0;

        for(int i = 0; i < k; i++) lsum += arr[i];
        mx = lsum;

        for(int l = k-1, r = n-1; l >= 0; l--, r--){
            lsum -= arr[l];
            rsum += arr[r];
            mx = max(mx, lsum + rsum);
        }

        return mx;
        // int l = 0, r = n-1;

        // vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));

        // for (int i = 1; i <= k; ++i) {
        //     for (int j = 0; j <= i; ++j) {
        //         int left_sum = (j > 0) ? arr[j - 1] + dp[i - 1][j - 1] : 0;
        //         int right_sum = (i - j > 0) ? arr[n - (i - j)] + dp[i - 1][j] : 0;
        //         dp[i][j] = max(left_sum, right_sum);
        //     }
        // }
        // int max_sum = 0;
        // for (int j = 0; j <= k; ++j) {
        //     max_sum = max(max_sum, dp[k][j]);
        // }

        // return max_sum;

        // vector<vector<int> > dp(n, vector<int>(n, -1));
        // return solve(l, r, n, arr, k, dp);
        // int l = 0, r = n-1;
        // int sum = 0;
        // while(k-- && l <= r){
        //     if(arr[l] > arr[r]){
        //         sum += arr[l];
        //         l += 1;
        //     }else{
        //         sum += arr[r];
        //         r -= 1;
        //     }
        // }
        // return sum;
    }
};