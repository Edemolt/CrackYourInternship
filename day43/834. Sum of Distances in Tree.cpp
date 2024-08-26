class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> tree(n);
        vector<int> subtree_size(n, 1), dp(n, 0), result(n, 0);


        for (auto& edge : edges) {
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }
        function<void(int, int)> dfs = [&](int node, int parent) {
            for (int neighbor : tree[node]) {
                if (neighbor == parent) continue;
                dfs(neighbor, node);
                subtree_size[node] += subtree_size[neighbor];
                dp[node] += dp[neighbor] + subtree_size[neighbor];
            }
        };
        function<void(int, int)> dfs2 = [&](int node, int parent) {
            result[node] = dp[node];
            for (int neighbor : tree[node]) {
                if (neighbor == parent) continue;
                
                int dp_node_backup = dp[node];
                int dp_neighbor_backup = dp[neighbor];
                int size_node_backup = subtree_size[node];
                int size_neighbor_backup = subtree_size[neighbor];
                
                dp[node] -= dp[neighbor] + subtree_size[neighbor];
                subtree_size[node] -= subtree_size[neighbor];
                
                dp[neighbor] += dp[node] + subtree_size[node];
                subtree_size[neighbor] += subtree_size[node];
                
                dfs2(neighbor, node);
                dp[node] = dp_node_backup;
                dp[neighbor] = dp_neighbor_backup;
                subtree_size[node] = size_node_backup;
                subtree_size[neighbor] = size_neighbor_backup;
            }
        };

        dfs(0, -1);  
        dfs2(0, -1);  

        return result;
    }
};
