class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>arr;
        int i = 0;
        for(i; i < n - k; i++) arr.push({nums[i], i});

        vector<int> ans;
        int mx = -1;
        for(i; i < n; i++){
            arr.push({ nums[i], i});
            while(arr.top()[1] < mx) arr.pop();
            ans.push_back(arr.top()[0]);
            mx = arr.top()[1];
            arr.pop();
        }

        return ans;
           
    }
};