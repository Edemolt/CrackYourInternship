class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        if(m == 0 || n == 0) return 0;

        vector<vector<int>> dist(m, vector<int>(n, 1));

        set<pair<int, pair<int, int>>> s;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                s.insert({matrix[i][j], {i, j}});
            }
        }

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, -1, 0, 1};

        while(!s.empty()){
            auto it = *(s.begin());
            s.erase(it);
            int val = it.first;
            int row = it.second.first;
            int col = it.second.second;

            for(int i = 0; i < 4; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && matrix[nrow][ncol] > val){
                    if(dist[nrow][ncol] < dist[row][col] + 1){
                        s.erase({matrix[nrow][ncol], {nrow, ncol}});
                        dist[nrow][ncol] = dist[row][col] + 1;
                        s.insert({matrix[nrow][ncol], {nrow, ncol}});
                    }
                }
            }
        }

        int mx = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++) mx = max(mx, dist[i][j]);
        }
        return mx;
    }
};
