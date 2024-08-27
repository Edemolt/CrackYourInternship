class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> distance(n, vector<int>(n, INT_MAX));
        for (int i = 0; i < n; ++i) {
            distance[i][i] = 0;
        }
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            distance[u][v] = w;
            distance[v][u] = w; 
        }

        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (distance[i][k] < INT_MAX && distance[k][j] < INT_MAX) {
                        distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
                    }
                }
            }
        }

        int resultCity = -1;
        int minReachableCount = n; 

        for (int i = 0; i < n; ++i) {
            int reachableCount = 0;
            for (int j = 0; j < n; ++j) {
                if (distance[i][j] <= distanceThreshold) {
                    ++reachableCount;
                }
            }
            if (reachableCount <= minReachableCount) {
                minReachableCount = reachableCount;
                resultCity = i;
            }
        }

        return resultCity;
    }
};
