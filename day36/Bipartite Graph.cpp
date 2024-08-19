//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

    int dfs(int node, vector<int> &vis, vector<int> adj[], int col){
        vis[node] = col;
        
        for(auto it: adj[node]){
            if(vis[it] == -1){
                if(!(dfs(it, vis, adj, !(col)))) return 0;
            }else if(vis[it] == col) return 0;
        }
        
        return 1;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> vis(V, -1);
	    for(int i = 0; i < V; i++){
	        if(vis[i] == -1){
	            if(!(dfs(i, vis, adj, 0))) return 0;
	        }
	    }
	    return 1;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends