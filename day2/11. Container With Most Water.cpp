class Solution {
public:
    int maxArea(vector<int>& heights) {
        int ans = 0;

        int l = 0;
        int r = heights.size() - 1;

        while(l < r){
            int mn = min(heights[l], heights[r]);
            ans = max(ans, mn * (r-l));
            if(heights[l] < heights[r]) l += 1;
            else r -= 1;
        }
        return ans;
    }
};