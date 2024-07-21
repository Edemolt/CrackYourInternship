class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        int cnt = 0, sum = 0;
        map<int, int> mp;
        mp[0] = 1;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            if(mp.find(sum - k) != mp.end()) cnt += mp[sum - k];
            mp[sum] += 1;
        }        
        return cnt;
    }
};