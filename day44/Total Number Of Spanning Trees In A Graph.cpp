//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    
    int determinant(vector<vector<int>>& matrix, int size) {
        if(size == 1)
            return matrix[0][0];
        
        if(size == 2)
            return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
        
        int det = 0;
        for(int p = 0; p < size; p++) {
            vector<vector<int>> temp(size - 1, vector<int>(size - 1));
            for(int i = 1; i < size; i++) {
                int col = 0;
                for(int j = 0; j < size; j++) {
                    if(j != p) {
                        temp[i-1][col] = matrix[i][j];
                        col++;
                    }
                }
            }
            det += matrix[0][p] * pow(-1, p) * determinant(temp, size - 1);
        }
        
        return det;
    }
    
    
    // khirchoffs matrix tree theoram... why shoould i learn a theoram for a question
    int countSpanningTrees(vector<vector<int>>& graph, int n, int m) {
        vector<vector<int>> L(n, vector<int>(n, 0));
        
        for(int i = 0; i < m; i++) {
            int u = graph[i][0];
            int v = graph[i][1];
            L[u][u]++;
            L[v][v]++;
            L[u][v]--;
            L[v][u]--;
        }
        
         vector<vector<int>> cofactor(n-1, vector<int>(n-1));
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < n; j++) {
                cofactor[i-1][j-1] = L[i][j];
            }
        }
        
        return determinant(cofactor, n-1);
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, m;
	    cin >> n >> m;
	    vector<vector<int>>graph(m, vector<int>(2, 0));
	    for(int i = 0 ; i < m; i++){
	        cin >> graph[i][0] >> graph[i][1];
	    }
	    Solution ob;
	    int ans = ob.countSpanningTrees(graph, n, m);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends