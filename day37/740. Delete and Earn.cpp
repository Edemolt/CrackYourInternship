class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int m = *max_element(nums.begin(), nums.end());
        int dp[20005];
        vector<int> freq(20005);

        for(auto itr : nums)
            freq[itr] += 1;

        dp[1] = freq[1];
        dp[2] = max(dp[1], freq[2]*2);;

        for(int i = 3; i <= m; i++){
            dp[i] = max(dp[i-1], dp[i-2] + freq[i]*i);
        }
        return dp[m];
    }
};