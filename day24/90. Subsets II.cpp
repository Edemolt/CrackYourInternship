class Solution {
public:

    void find(int ind, int n, vector<int> &temp, vector<int> &nums, set<vector<int> > &ans){
        if( ind == n){
            ans.insert(temp);
            return;
        }
        temp.push_back(nums[ind]);
        find(ind + 1, n, temp, nums, ans);
        temp.pop_back();
        find(ind + 1, n, temp, nums, ans);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int> > ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> temp;
        find(0, n, temp, nums, ans);
        return vector<vector<int> > (ans.begin(), ans.end());
    }
};