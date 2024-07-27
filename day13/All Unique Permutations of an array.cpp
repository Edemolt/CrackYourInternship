//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void find(vector<int> &used, int n, vector<int> &nums, set<vector<int> > &ans, vector<int> temp){
        if(temp.size() == n){
            ans.insert(temp);
            return;
        }
        
        for(int i = 0; i < n; i++){
            if(used[i]) continue;
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;
             
            used[i] = 1;
            temp.push_back(nums[i]);
            
            find(used, n, nums, ans, temp);
            
            used[i] = 0;
            temp.pop_back();
        }
    }
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        // code here
        set<vector<int> > ans;
        sort(arr.begin(), arr.begin() + n);
        vector<int> temp;
        vector<int> used(n, 0);
        find(used, n, arr, ans, temp);
        
        return vector<vector<int> >(ans.begin(), ans.end());
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;
        vector<int> arr(n);
        
        for(int i=0 ; i<n ; i++)
            cin>>arr[i];

        Solution ob;
        vector<vector<int>> res = ob.uniquePerms(arr,n);
        for(int i=0; i<res.size(); i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends