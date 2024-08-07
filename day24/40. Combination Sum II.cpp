class Solution {
public:
    void find(int ind, int n, int k, vector<int> &nums, vector<int> &temp, vector<vector<int>> &ans){
        if(k == 0){
            ans.push_back(temp);
            return;
        }

        for(int i = ind; i < n; i++){
            // Skip duplicates
            if(i > ind && nums[i] == nums[i-1]) continue;
            if(nums[i] > k) break;

            temp.push_back(nums[i]);
            find(i + 1, n, k - nums[i], nums, temp, ans);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        
        vector<vector<int>> ans;
        vector<int> temp;
        int n = candidates.size();
        find(0, n, target, candidates, temp, ans);
        return ans;
    }
};
