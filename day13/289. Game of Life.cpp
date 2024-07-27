class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int> > prev(m, vector<int>(n));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                prev[i][j] = board[i][j];
            }
        }

        int drow[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dcol[] = {-1, 0, 1, -1, 1, -1, 0, 1};

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int cnt = 0;
                for(int k = 0; k < 8; k++){
                    int nrow = i + drow[k];
                    int ncol = j + dcol[k];
                    if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n){
                        if(prev[nrow][ncol] == 1) cnt += 1;
                    }
                }
                if(prev[i][j] == 1){
                    if(cnt < 2 || cnt > 3) board[i][j] = 0;
                }
                if(prev[i][j] == 0){
                    if(cnt == 3) board[i][j] = 1;
                }
            }
        }
    }
};