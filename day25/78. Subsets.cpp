class Solution {
public:
    void generate(int ind, int n, vector<int> &nums, vector<vector<int> > &ans, vector<int> temp){
        if(ind == n){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[ind]);
        generate(ind+1, n, nums, ans, temp);
        temp.pop_back();
        generate(ind+1, n, nums, ans, temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > ans;
        int n = nums.size();
        vector<int> temp;
        generate(0, n, nums, ans, temp);
        return ans;
    }
};