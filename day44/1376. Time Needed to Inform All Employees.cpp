class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int ans = 0;
        queue<pair<int, int>> q;
        q.push({headID, informTime[headID]});
        vector<int> adj[n];

        for(int i = 0; i < n; i++){
            if(manager[i] != -1)
                adj[manager[i]].push_back(i);
        }

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int node = it.first;
            int currTime = it.second;
            ans = max(ans, currTime);

            for(auto subordinate : adj[node]){
                q.push({subordinate, currTime + informTime[subordinate]});
            }
        }

        return ans;
    }
};