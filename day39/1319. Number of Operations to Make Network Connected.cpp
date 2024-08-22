#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    // Find function with path compression
    int find(int x, vector<int>& parent) {
        if (parent[x] != x) {
            parent[x] = find(parent[x], parent);
        }
        return parent[x];
    }

    // Union function with union by rank
    void unionSet(int x, int y, vector<int>& parent, vector<int>& rank) {
        int rootX = find(x, parent);
        int rootY = find(y, parent);

        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        // If there are not enough connections to connect all computers
        if (connections.size() < n - 1) {
            return -1;
        }

        // Initialize Union-Find structure
        vector<int> parent(n);
        vector<int> rank(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }

        // Apply union operations for each connection
        for (const auto& conn : connections) {
            unionSet(conn[0], conn[1], parent, rank);
        }

        // Count the number of unique components
        unordered_set<int> uniqueComponents;
        for (int i = 0; i < n; ++i) {
            uniqueComponents.insert(find(i, parent));
        }

        // The minimum number of connections needed to connect all components
        return uniqueComponents.size() - 1;
    }
};
