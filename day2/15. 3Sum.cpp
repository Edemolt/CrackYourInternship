class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = 0;
        vector<vector<int> > ans;
        while(i < n - 2){
            int j = n - 1;
            int k = i + 1;
            int sum;
            while(k < j){
                sum = nums[i] + nums[j] + nums[k];
                if(sum == 0){
                    ans.push_back({nums[i], nums[j], nums[k]});
                    k += 1;
                    j -= 1;
                }
                else if(sum > 0) j -= 1;
                else if(sum < 0) k += 1;
            }
            i++;
        }
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};