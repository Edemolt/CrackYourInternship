class Solution {
public:
    int find(int ind, int n, vector<int> &nums, vector<vector<int>> &dp, int prev){
        if(ind == n) return 0;

        if(dp[ind][prev + 1] != -1) return dp[ind][prev + 1];

        int ans = find(ind + 1, n, nums, dp, prev);
        int take = 0;
        if(prev == -1 || nums[ind] > nums[prev]) take = 1 + find(ind + 1, n, nums, dp, ind);
        return dp[ind][prev+1] = max(ans, take); 
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int> > dp(n, vector<int>(n, -1));

        return find(0, n, nums, dp, -1);
    }
};