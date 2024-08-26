class DisjointSet {
private:
    vector<int> parent, rank;

public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        DisjointSet ds(n);
        unordered_map<int, int> rowMap, colMap;

        for (int i = 0; i < n; i++) {
            int row = stones[i][0], col = stones[i][1];
            
            if (rowMap.count(row)) {
                ds.unite(i, rowMap[row]);
            } else {
                rowMap[row] = i;
            }
            
            if (colMap.count(col)) {
                ds.unite(i, colMap[col]);
            } else {
                colMap[col] = i;
            }
        }

        unordered_set<int> components;
        for (int i = 0; i < n; i++) {
            components.insert(ds.find(i));
        }

        return n - components.size();
    }
};