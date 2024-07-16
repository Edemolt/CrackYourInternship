class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int, int> mp;

        vector<int> ans;
        for(int num : nums){
            if(mp.find(num) != mp.end()) ans.push_back(num);
            mp[num] += 1;
        }
        return ans;
    }
};