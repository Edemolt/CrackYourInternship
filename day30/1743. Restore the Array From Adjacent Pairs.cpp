class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> mp;

        int n = adjacentPairs.size();
        for(int i = 0; i < n; i++){
            mp[adjacentPairs[i][0]].push_back(adjacentPairs[i][1]);
            mp[adjacentPairs[i][1]].push_back(adjacentPairs[i][0]);
        }

        int start;
        for(auto &it: mp){
            if(it.second.size() == 1){
                start = it.first;
                break;
            }
        }

        vector<int> res;
        unordered_set<int> vis;
        res.push_back(start);
        vis.insert(start);

        while(res.size() < mp.size()){
            int last = res.back();
            for(int k : mp[last]){
                if(vis.find(k) == vis.end()){
                    res.push_back(k);
                    vis.insert(k);
                    break;
                }
            }
        }
        return res;
    }
};