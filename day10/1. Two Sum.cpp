class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp;
        
        int n = nums.size();

        for(int i = 0; i < n; i++){
            if(mp.find(nums[i]) != mp.end()) return {mp[nums[i]], i};
            mp[target- nums[i]] = i;
        }
        return {-1, -1};
    }
};