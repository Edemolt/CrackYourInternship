//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis, stack<int>& st) {
        vis[node] = 1;
        for (int neighbor : adj[node]) {
            if (!vis[neighbor]) {
                dfs(neighbor, adj, vis, st);
            }
        }
        st.push(node);
    }

    void dfsTranspose(int node, vector<vector<int>>& adjT, vector<int>& vis) {
        vis[node] = 1;
        for (int neighbor : adjT[node]) {
            if (!vis[neighbor]) {
                dfsTranspose(neighbor, adjT, vis);
            }
        }
    }

	// Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        // Step 1: Perform DFS and push nodes onto stack according to their finish time
        stack<int> st;
        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, adj, vis, st);
            }
        }

        // Step 2: Create the transposed graph
        vector<vector<int>> adjT(V);
        for (int i = 0; i < V; i++) {
            for (int neighbor : adj[i]) {
                adjT[neighbor].push_back(i);
            }
        }

        // Step 3: Perform DFS on the transposed graph
        fill(vis.begin(), vis.end(), 0);  // Reset visited array
        int cnt = 0;
        while (!st.empty()) {
            int node = st.top();
            st.pop();
            if (!vis[node]) {
                cnt++;
                dfsTranspose(node, adjT, vis);
            }
        }
        
        return cnt;
    }
};


//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends