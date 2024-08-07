class Solution {
public:
    void fn(int n, vector<int> &temp, vector<int> &nums, vector<int> &vis, set<vector<int> > &ans){
        if(temp.size() == n){
            ans.insert(temp);
            return;
        }

        for(int i = 0; i < n; i++){
            if(vis[i] == 0){
                vis[i] = 1;
                temp.push_back(nums[i]);
                fn(n, temp, nums, vis, ans);
                temp.pop_back();
                vis[i] = 0;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        set<vector<int> > ans;
        vector<int> temp;
        vector<int> vis(n, 0);

        fn(n, temp, nums, vis, ans);
        return vector<vector<int> >(ans.begin(), ans.end());
    }
};