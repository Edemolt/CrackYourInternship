class Solution {
public:
  void dfs(int row, int col, int m, int n, vector<vector<char>>& board, vector<vector<int>>& vis) {
    vis[row][col] = 1; // Mark current cell as visited

    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1}; // Directions for exploring neighbors

    for (int i = 0; i < 4; i++) {
      int nrow = row + drow[i];
      int ncol = col + dcol[i];

      // Check if new position is valid (within bounds and unvisited 'O')
      if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && board[nrow][ncol] == 'O' && !vis[nrow][ncol]) {
        dfs(nrow, ncol, m, n, board, vis); // Recursive call for exploration
      }
    }
  }

  void solve(vector<vector<char>>& board) {
    int m = board.size();
    int n = board[0].size();

    vector<vector<int>> vis(m, vector<int>(n, 0)); // Visited flag matrix

    // Start DFS from boundary 'O' cells
    for (int i = 0; i < m; i++) {
      if (board[i][0] == 'O' && !vis[i][0]) dfs(i, 0, m, n, board, vis); // Leftmost column
      if (board[i][n - 1] == 'O' && !vis[i][n - 1]) dfs(i, n - 1, m, n, board, vis); // Rightmost column
    }

    for (int j = 0; j < n; j++) {
      if (board[0][j] == 'O' && !vis[0][j]) dfs(0, j, m, n, board, vis); // Topmost row
      if (board[m - 1][j] == 'O' && !vis[m - 1][j]) dfs(m-1, j, m, n, board, vis); // Bottommost row
    }

    // Mark unvisited 'O' cells as 'X' (surrounded regions)
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (board[i][j] == 'O' && !vis[i][j]) {
          board[i][j] = 'X';
        }
      }
    }
  }
};
