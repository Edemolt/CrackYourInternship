class Solution {
public:
    bool dfs(int ind, int row, int col, int m, int n, vector<vector<char>> &board, string &word, vector<vector<int>> &vis, int drow[], int dcol[]) {
        // If we have matched all characters in the word
        if(ind == word.size()) return true;

        // Check for boundary conditions and whether the cell is visited or the character does not match
        if(row < 0 || row >= m || col < 0 || col >= n || vis[row][col] || board[row][col] != word[ind]) return false;

        // Mark the cell as visited
        vis[row][col] = 1;

        // Traverse in all 4 possible directions
        for(int i = 0; i < 4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if(dfs(ind + 1, nrow, ncol, m, n, board, word, vis, drow, dcol)) {
                return true;
            }
        }

        // Backtrack: Unmark the cell as visited
        vis[row][col] = 0;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == word[0]) {
                    vector<vector<int>> vis(m, vector<int>(n, 0));
                    if(dfs(0, i, j, m, n, board, word, vis, drow, dcol)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
