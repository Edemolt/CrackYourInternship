#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph(n);
        vector<vector<int>> bridges;
        vector<int> disc(n, -1);   
        vector<int> low(n, -1);     
        vector<bool> visited(n, false);
        int time = 0;

        for (const auto& edge : connections) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                dfs(i, -1, disc, low, visited, graph, bridges, time);
            }
        }
        
        return bridges;
    }

private:
    void dfs(int u, int parent, vector<int>& disc, vector<int>& low, vector<bool>& visited,
             const vector<vector<int>>& graph, vector<vector<int>>& bridges, int& time) {
        visited[u] = true;
        disc[u] = low[u] = ++time;

        for (int v : graph[u]) {
            if (!visited[v]) {          
                dfs(v, u, disc, low, visited, graph, bridges, time);
                low[u] = min(low[u], low[v]);

                if (low[v] > disc[u]) {
                    bridges.push_back({u, v});
                }
            } else if (v != parent) {
                low[u] = min(low[u], disc[v]);
            }
        }
    }
};
