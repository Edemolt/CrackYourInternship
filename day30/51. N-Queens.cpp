class Solution {
public:
    int good(int row, int col, int n, vector<string> &board) {

    for (int i = 0; i < row; i++) 
        if (board[i][col] == 'Q') 
            return 0;

    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) 
        if (board[i][j] == 'Q') 
            return 0;

    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) 
        if (board[i][j] == 'Q') 
            return 0;

    return 1;
}
    void solve(int ind, int n, vector<string> &board, vector<vector<string> > &ans){
        if(ind == n){
            ans.push_back(board);
            return;
        }

        for(int i = 0; i < n; i++){
            if(good(ind, i, n, board)){
                board[ind][i] = 'Q';
                solve(ind + 1, n, board, ans);
                board[ind][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string > > ans;
        vector<string> board(n, string(n, '.'));
        solve(0, n, board, ans);
        return ans;
    }
};