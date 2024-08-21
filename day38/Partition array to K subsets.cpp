//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
    int solve(int ind, int n, int arr[], int k, vector<int> &v, vector<int> &vis, int target){
        if(ind == n) return 1;
        
        for(int i = 0; i < k; i++){
            if( v[i] + arr[ind] <= target ){
                v[i] += arr[ind];
                if(solve(ind + 1, n, arr, k, v, vis, target)) return 1;
                v[i] -= arr[ind];
                
                if(v[i] == 0) break;
            }
        }
        return 0;
    }
    bool isKPartitionPossible(int a[], int n, int k)
    {
         //Your code here
        vector<int> v(k,0);
        int sum = 0;
        for(int i = 0; i < n; i++) sum += a[i];
        if(sum%k) return 0;
        int target = sum/k;
        sort(a, a + n);
        
        vector<int> vis(n, 0);
        
        return solve(0,n,a,k,v, vis, target);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	int k;
    	cin>>k;
    	Solution obj;
    	cout<<obj.isKPartitionPossible(a, n, k)<<endl;
    }
}
// } Driver Code Ends