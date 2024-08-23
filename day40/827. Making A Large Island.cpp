class Solution {
public:
    vector<int> parent;
    vector<int> sz;
    
    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            parent[rootX] = rootY;
            sz[rootY] += sz[rootX];
        }
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        parent.resize(n * n);
        sz.resize(n * n, 1);
        
        for (int i = 0; i < n * n; ++i) {
            parent[i] = i;
        }
        
        vector<int> dirs = {-1, 0, 1, 0, -1};
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    for (int d = 0; d < 4; ++d) {
                        int ni = i + dirs[d];
                        int nj = j + dirs[d+1];
                        if (ni >= 0 && nj >= 0 && ni < n && nj < n && grid[ni][nj] == 1) {
                            unite(i * n + j, ni * n + nj);
                        }
                    }
                }
            }
        }
        
        int maxSize = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    unordered_set<int> uniqueIslands;
                    int currentSize = 1; 
                    
                    for (int d = 0; d < 4; ++d) {
                        int ni = i + dirs[d];
                        int nj = j + dirs[d+1];
                        if (ni >= 0 && nj >= 0 && ni < n && nj < n && grid[ni][nj] == 1) {
                            int root = find(ni * n + nj);
                            if (uniqueIslands.find(root) == uniqueIslands.end()) {
                                uniqueIslands.insert(root);
                                currentSize += sz[root];
                            }
                        }
                    }
                    
                    maxSize = max(maxSize, currentSize);
                }
            }
        }
        if (maxSize == 0) return n * n;
        
        return maxSize;
    }
};