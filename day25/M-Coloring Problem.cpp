//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
     bool isSafe(int node, vector<vector<int>>& graph, vector<int>& color, int c) {
        for (int i = 0; i < graph.size(); i++) {
            if (graph[node][i] && color[i] == c) {
                return false;
            }
        }
        return true;
    }

    bool graphColoringUtil(vector<vector<int>>& graph, vector<int>& color, int m, int node) {
        int n = graph.size();
        if (node == n) return true;

        for (int c = 1; c <= m; c++) {
            if (isSafe(node, graph, color, c)) {
                color[node] = c;
                if (graphColoringUtil(graph, color, m, node + 1)) return true;
                color[node] = 0; // backtrack
            }
        }
        return false;
    }

    bool graphColoring(bool graph[101][101], int m, int n) {
        vector<vector<int>> adjMatrix(n, vector<int>(n, 0));
        vector<int> color(n, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                adjMatrix[i][j] = graph[i][j];
            }
        }

        return graphColoringUtil(adjMatrix, color, m, 0);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends