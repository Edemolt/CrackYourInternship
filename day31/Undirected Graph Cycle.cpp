//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    int bfs(int src, int V, vector<int> &vis, vector<int> adj[]){
        queue<pair<int, int> > q;
        
        q.push({src, -1});
        vis[0] = 1;
        
        while(!(q.empty())){
            auto it = q.front();
            q.pop();
            int node = it.first;
            vis[node] = 1;
            int parent = it.second;
            
            for(int nd : adj[node]){
                if(vis[nd] == 1){
                    if(nd == parent) continue;
                    else return 1;
                }
                q.push({nd, node});
            }
        }
        return 0;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V, 0);
        
        for(int i = 0; i < V; i++){
            if(!(vis[i])){
                if(bfs(i, V, vis, adj)) return 1;
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Endss