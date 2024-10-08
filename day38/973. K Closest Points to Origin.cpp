class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
         vector<vector<int>> ans;
        priority_queue<pair<int, int>> pq;

        for (int i = 0; i < points.size(); i++) {
            int dist = (points[i][0] * points[i][0]) + (points[i][1] * points[i][1]);
            pq.push({dist, i});
            if (pq.size() > k) {
                pq.pop();
            }
        }

        while (!pq.empty()) {
            int index = pq.top().second;
            pq.pop();
            ans.push_back(points[index]);
        }

        return ans;
    }

};