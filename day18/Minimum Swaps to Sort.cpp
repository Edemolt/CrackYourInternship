//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    int n = nums.size();
	    vector<int> temp = nums;
	    sort(temp.begin(), temp.end());
	    
	    unordered_map<int, int> mp;
	    for(int i = 0; i < n; i++) mp[temp[i]] = i;
	    
	    vector<int> target(n);
	    for(int i = 0; i < n; i++) target[i] = mp[nums[i]];
	    
	    vector<int> vis(n, 0);
	    int swaps = 0;
	    
	    for(int i = 0; i < n; i++){
	        if(vis[i] || target[i] == i) continue;
	        else{
	            int cycle = 0, j = i;
	            
	            while(!(vis[j])){
	                vis[j] = 1;
	                j = target[j];
	                cycle += 1;
	            }
	            
	            if(cycle > 0) swaps += cycle - 1;
	        }
	    }
	    return swaps;
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends