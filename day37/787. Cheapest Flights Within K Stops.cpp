class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int ans = -1;

        vector<pair<int, int> > adj[n];

        for(auto flight : flights) adj[flight[0]].push_back({flight[1], flight[2]});

        queue<pair<int, pair<int, int> > > q;
        q.push({0, {src, 0}});
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        while(!(q.empty())){
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            if(stops > k) continue;

            for(auto it : adj[node]){
                int adjnode = it.first;
                int adjcost = it.second;

                if( cost + adjcost < dist[adjnode] && stops <= k){
                    dist[adjnode] = cost + adjcost;
                    q.push({stops + 1, { adjnode, cost + adjcost}});
                }
            }

        }
            if(dist[dst] == 1e9) return -1;
            return dist[dst];
    }
};