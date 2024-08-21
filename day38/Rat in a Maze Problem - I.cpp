//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    void solve(int x, int y, int n, int drow[], int dcol[], vector<vector<int> > &mat,
        string &str, vector<string> &ans, vector<vector<int> > &vis, int p1, int p2){
        if(x == n-1 && y == n-1){
            ans.push_back(str);
            return;
        }
        if(vis[x][y]) return;
        vis[x][y] = 1;
        
        for(int i = 0; i < 4; i++){
            int nrow = x + drow[i];
            int ncol = y + dcol[i];
            
            if(nrow == p1 && ncol == p2) continue;
            
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && mat[nrow][ncol] == 1 && !(vis[nrow][ncol])){
                if(i == 0) str.push_back('U');
                else if(i == 1) str.push_back('L');
                else if(i == 2) str.push_back('D');
                else str.push_back('R');
                solve(nrow, ncol, n, drow, dcol, mat, str, ans, vis, x, y);
                str.pop_back();
            }
        }
        
        vis[x][y] = 0;
    }
    vector<string> findPath(vector<vector<int>> &mat) {
        // Your code goes here
        int n = mat.size();
        if(mat[0][0] == 0 || mat[n-1][n-1] == 0) return {};
        vector<vector<int> > vis(n, vector<int>(n , 0));
    
        
        vector<string> ans;
        string str = "";
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, -1, 0, 1};
        
        solve(0, 0, n, drow, dcol, mat, str, ans, vis, -1e9, -1e9);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends