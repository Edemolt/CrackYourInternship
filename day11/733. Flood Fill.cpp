class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int drow[] = { -1, 0, 1, 0};
        int dcol[] = { 0, 1, 0, -1};

        int m = image.size();
        int n = image[0].size();

        queue<pair<int, int> > q;
        q.push({sr, sc});

        int ogcol = image[sr][sc];

        vector<vector<int> > vis(m, vector<int>(n, 0));

        while(!(q.empty())){
            auto node = q.front();
            int x = node.first;
            int y = node.second;
            q.pop();
            vis[x][y] = 1;

            if(image[x][y] == ogcol) image[x][y] = color;

            for(int i = 0; i < 4; i++){
                int nrow = x + drow[i];
                int ncol = y + dcol[i];
                if( nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && !(vis[nrow][ncol]) && image[nrow][ncol] == ogcol) q.push({nrow, ncol});
            }
        }
        return image;
    }
};