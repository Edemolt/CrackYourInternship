class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int> > ans;
        int i = 0;
        while(i < n - 3){
            int j = i+1;
            while(j < n-2){
                int l = j+1, r = n-1;
                while( l < r){
                    long long sum = nums[i] * 1ll + nums[j] * 1ll + nums[l] * 1ll + nums[r] * 1ll;
                    if(sum == target){
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                        l += 1;
                        r -= 1;
                    }else if(sum > target) r -= 1;
                    else if(sum < target) l += 1;
                }
                j += 1;
            }
            i += 1;
        }
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};