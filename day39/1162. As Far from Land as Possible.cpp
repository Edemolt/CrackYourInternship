class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));
        queue<pair<int, pair<int, int>>> q;

        // Push all land cells to the queue
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    q.push({0, {i, j}});
                    vis[i][j] = 1;
                }
            }
        }

        // Directions for moving in 4 directions (up, down, left, right)
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        int maxDistance = -1;

        // BFS
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            int steps = it.first;
            int x = it.second.first;
            int y = it.second.second;

            // Explore neighbors
            for(int i = 0; i < 4; i++) {
                int nrow = x + drow[i];
                int ncol = y + dcol[i];

                // If the neighboring cell is valid, is water, and hasn't been visited
                if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && grid[nrow][ncol] == 0 && vis[nrow][ncol] == 0) {
                    vis[nrow][ncol] = 1;
                    q.push({steps + 1, {nrow, ncol}});
                    maxDistance = max(maxDistance, steps + 1);
                }
            }
        }

        return maxDistance;
    }
};
