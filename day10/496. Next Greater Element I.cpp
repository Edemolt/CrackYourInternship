class Solution {
public:
    unordered_map<int, int> generate(vector<int> &nums){
        stack<int> st;

        int n = nums.size();
        vector<int> ans(n);
        for(int i = n-1; i >= 0; i--){
            while(!(st.empty()) && st.top() <= nums[i]) st.pop();

            if(st.empty()) ans[i] = -1;
            else ans[i] = st.top();

            st.push(nums[i]);
        }

        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++) mp[nums[i]] = ans[i];

        return mp;
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp = generate(nums2);
        int n = nums1.size();
        vector<int> ans(n);

        for(int i = 0; i < n; i++){
            if(mp.find(nums1[i]) != mp.end()) ans[i] = mp[nums1[i]];
            else ans[i] = -1;
        }

        return ans;
    }
};