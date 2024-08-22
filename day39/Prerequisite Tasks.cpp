//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	 bool isPossible(int N, int P, vector<pair<int, int>>& prerequisites) {
        // Create an adjacency list
        vector<int> adj[N];
        
        // Fill the adjacency list based on prerequisites
        for (auto itr : prerequisites) {
            adj[itr.first].push_back(itr.second);
        }

        // Create a vector to store the in-degree of each node
        vector<int> inDegree(N, 0);
        
        // Fill the in-degree vector
        for (int i = 0; i < N; i++) {
            for (auto itr : adj[i])
                inDegree[itr]++;
        }

        // Create a queue to perform topological sorting
        queue<int> q;
        
        // Push nodes with in-degree 0 into the queue
        for (int i = 0; i < N; i++) {
            if (inDegree[i] == 0)
                q.push(i);
        }

        // Perform topological sort
        vector<int> topoOrder;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topoOrder.push_back(node);

            // Reduce the in-degree of adjacent nodes
            for (auto itr : adj[node]) {
                inDegree[itr]--;
                // If in-degree becomes 0, push it into the queue
                if (inDegree[itr] == 0)
                    q.push(itr);
            }
        }

        // If topological order includes all nodes, return true (no cycle)
        if (topoOrder.size() == N)
            return true;

        // Otherwise, return false (cycle detected)
        return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N,P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends