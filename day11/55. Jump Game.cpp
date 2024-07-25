class Solution {
public:
    int check(int ind, int n, vector<int> &nums, vector<int> &dp) {
        if (ind >= n - 1) return 1;  // If reached or exceeded the last index, return 1
        if (dp[ind] != -1) return dp[ind];  // Return already computed result

        int maxJump = nums[ind];  // Maximum steps we can jump from current index
        for (int i = 1; i <= maxJump; i++) {
            if (check(ind + i, n, nums, dp)) {
                return dp[ind] = 1;  // If any jump leads to a solution, memoize and return 1
            }
        }
        return dp[ind] = 0;  // If no jump leads to a solution, memoize and return 0
    }

    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return check(0, n, nums, dp) == 1;
    }
};
