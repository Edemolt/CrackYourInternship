class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue< pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
        unordered_map<int, int> mp;
        vector<int> ans;

        for(int num : nums) mp[num] += 1;

        for(auto itr: mp){
            pq.push({itr.second, itr.first});
            if(pq.size() > k) pq.pop();
        }

        while(pq.size() > 0){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};