class Solution {
public:
    struct UnionFind {
        vector<int> parent, rank;

        UnionFind(int n) : parent(n), rank(n, 1) {
            iota(parent.begin(), parent.end(), 0);
        }

        int find(int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        }

        bool unite(int x, int y) {
            int rootX = find(x);
            int rootY = find(y);
            if (rootX != rootY) {
                if (rank[rootX] > rank[rootY]) {
                    parent[rootY] = rootX;
                } else if (rank[rootX] < rank[rootY]) {
                    parent[rootX] = rootY;
                } else {
                    parent[rootY] = rootX;
                    rank[rootX]++;
                }
                return true;
            }
            return false;
        }
    };

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<tuple<int, int, int>> edges; 
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i + 1 < n) {
                    edges.push_back({max(grid[i][j], grid[i + 1][j]), i * n + j, (i + 1) * n + j});
                }
                if (j + 1 < n) {
                    edges.push_back({max(grid[i][j], grid[i][j + 1]), i * n + j, i * n + (j + 1)});
                }
            }
        }
        sort(edges.begin(), edges.end());
        
        UnionFind uf(n * n);
        for (const auto& [w, u, v] : edges) {
            uf.unite(u, v);
            if (uf.find(0) == uf.find(n * n - 1)) {
                return w;
            }
        }
        
        return 0; 
    }
};
