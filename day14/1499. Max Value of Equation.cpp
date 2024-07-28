class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        deque<pair< int, int> > dq;
        int mx = -1e9;
        int n = points.size();

        for(int i = 0; i < n; i++){
            int xi = points[i][0], yi = points[i][1];

            while(!(dq.empty()) && xi - dq.front().second > k) dq.pop_front();

            if(!(dq.empty())) mx = max( mx, yi + xi + dq.front().first);

            while(!(dq.empty()) && dq.back().first <= yi - xi) dq.pop_back();
            dq.emplace_back(yi - xi, xi);
        }
        return mx;
    }
};