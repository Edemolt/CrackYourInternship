//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int> > vis(n, vector<int>(m, 0));
        
        queue<pair<int, pair<int, int> > > q;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    q.push({0,{i, j}});
                    vis[i][j] = 1;
                }
                if(grid[i][j] == 1) cnt += 1;
            }
        }
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        
        int mx = 0;
        while(!(q.empty())){
            auto it = q.front();
            q.pop();
            int steps = it.first;
            int x = it.second.first;
            int y = it.second.second;
            
            mx = steps;
            for(int i = 0; i < 4; i++){
                int nrow = x + drow[i];
                int ncol = y + dcol[i];
                
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && !(vis[nrow][ncol])){
                    q.push({ steps + 1, {nrow, ncol}});
                    vis[nrow][ncol] = 1;
                    grid[nrow][ncol] = 2;
                    cnt -= 1;
                }
            }
        }
        
        if(cnt > 0) return -1;
        return mx;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Endssw