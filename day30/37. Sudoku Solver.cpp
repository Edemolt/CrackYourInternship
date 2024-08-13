class Solution {
public:

    int good(int row, int col, char num, vector<vector<char > > &board){
        for(int i = 0; i < 9; i++){
            if(board[i][col] == num) return 0;
            if(board[row][i] == num) return 0;

            if(board[3*(row/3) + i/3][3*(col/3)+ i%3] == num) return 0;
        }
        return 1;
    }

    int solve( vector<vector<char> > & board){
        int n = board.size();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == '.'){
                    for(int num = '1'; num <= '9'; num++){
                        if(good(i, j, num, board)){
                            board[i][j] = num;

                            if(solve(board)) return 1;
                            else board[i][j] = '.';
                        }
                    }
                return 0;
                }
            }
        }
        return 1;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};