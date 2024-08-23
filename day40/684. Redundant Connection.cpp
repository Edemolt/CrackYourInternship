class Disjoint_set{
    public:
        vector<int> rank, parent;

        Disjoint_set(int n){
            rank.resize(n+1,0);
            parent.resize(n+1,0);

            for(int i = 0; i <= n; i++) parent[i] = i;
        }

        int find_parent(int node){
            if(parent[node] == node) return node;
            return parent[node] = find_parent(parent[node]);
        }

        void union_by_rank(int node1, int node2){
            int parent1 = find_parent(node1);
            int parent2 = find_parent(node2);

            if(parent1 == parent2) return;

            if(rank[parent1] < rank[parent2]){
                parent[parent1] = parent2;
            }else if(rank[parent2] < rank[parent1]){
                parent[parent2] = parent1;
            }else{
                parent[parent1] = parent2;
                rank[parent2] += 1;
            }
        }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> ans;
        Disjoint_set *obj;
        int n = edges.size();
        obj = new Disjoint_set(n);

        for(int i = 0; i < n; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            if(obj->find_parent(u) == obj->find_parent(v)){
                ans.push_back(u);
                ans.push_back(v);
            }else obj->union_by_rank(u, v);
        }
        return ans;
    }
};