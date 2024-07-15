class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> s;
        for(int num : nums) s.insert(num);
        nums = {};
        for(int num : s) nums.push_back(num);
        return nums.size();        
    }
};