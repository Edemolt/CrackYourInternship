class Solution {
public:
    int solve(int ind, int n, vector<int>& heights, int bricks, int ladders, vector<vector<vector<int>>>& dp) {
        if (ind == n) return n - 1;
        
        if (dp[ind][bricks][ladders] != -1) return dp[ind][bricks][ladders];
        
        int ans = ind - 1;  // If we can't move forward, return current index
        
        if (ind == 0 || heights[ind] <= heights[ind - 1]) {
            ans = solve(ind + 1, n, heights, bricks, ladders, dp);
        } else {
            int diff = heights[ind] - heights[ind - 1];
            
            if (bricks >= diff)
                ans = max(ans, solve(ind + 1, n, heights, bricks - diff, ladders, dp));
            
            if (ladders > 0)
                ans = max(ans, solve(ind + 1, n, heights, bricks, ladders - 1, dp));
        }
        
        return dp[ind][bricks][ladders] = ans;
    }

    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        // int n = heights.size();
        // vector<vector<vector<int>>> dp(n, vector<vector<int>>(bricks + 1, vector<int>(ladders + 1, -1)));
        // return solve(0, n, heights, bricks, ladders, dp);

        priority_queue<int> pq; // max heap
        int n = heights.size();
        
        for (int i = 0; i < n - 1; i++) {
            int diff = heights[i+1] - heights[i];
            
            if (diff > 0) {
                pq.push(diff);
                bricks -= diff;
                
                if (bricks < 0) {
                    if (ladders == 0) return i;
                    
                    ladders--;
                    bricks += pq.top();
                    pq.pop();
                }
            }
        }
        
        return n - 1;
    }
};