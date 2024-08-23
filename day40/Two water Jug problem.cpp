//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int minSteps(int m, int n, int d)
	{
	    // Code here
	    if(d > m && d > n) return -1;
	    if(d % __gcd(m, n) != 0) return -1;
	    queue<pair<int, int> > q;
	    set< pair< int, int> > vis;
	    
	    int steps = 0;
	    
	    q.push({ 0, 0});
	    vis.insert({ 0, 0});
	    
	    while(!( q.empty())){
	        int sz = q.size();
	        
	        for(int i = 0; i < sz; i++){
	            auto it = q.front();
	            q.pop();
	            int a =it.first;
	            int b = it.second;
	            
	            if(a == d || b == d) return steps;
	            
	            vector<pair<int, int>> nextStates = {
                    {m, b}, 
                    {a, n}, 
                    {0, b}, 
                    {a, 0}, 
                    {max(0, a - (n - b)), min(n, a + b)},
                    {min(m, a + b), max(0, b - (m - a))}  
                };
                
                for (auto &state : nextStates) {
                    if (vis.find(state) == vis.end()) {
                        q.push(state);
                        vis.insert(state);
                    }
                }
	        }
	        steps += 1;
	    }
	    
	    return -1;
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, d;
		cin >> m >> n >> d;
		Solution ob;
		int ans = ob.minSteps(m, n, d);
		cout << ans <<"\n";
	}  
	return 0;
}
// } Driver Code Ends