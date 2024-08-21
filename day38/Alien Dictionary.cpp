// User function Template for C++

class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        //code here
        vector<int> adj[K];
        
        for(int i = 0; i < N-1; i++){
            string s1 = dict[i];
            string s2 = dict[i+1];
            
            int len = min(s1.size(), s2.size());
            
            for(int j = 0; j < len; j++){
                if(s1[j] != s2[j]){
                    adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                    break;
                }
            }
        }
            
            vector<int> vis(K,0);
            
            for(int i = 0; i < K; i++){
                for(auto itr : adj[i]){
                    vis[itr] += 1;
                }
            }
            
            vector<int> ans;
            queue<int> q;
            
            for(int i = 0; i < K; i++){
                if(!(vis[i])) q.push(i);
            }
            
            while(!(q.empty())){
                int node = q.front();
                q.pop();
                ans.push_back(node);
                
                for(auto itr : adj[node]){
                    vis[itr] -= 1;
                    if(!(vis[itr])){
                        q.push(itr);
                    }
                }
            }
            string str = "";
            // for(auto itr : ans) cout<<itr <<"   ";
            
            if(ans.size() == K){
                for(auto itr : ans){
                    char ch = 'a' + itr;
                    // cout<<ch<<"   ";
                    str = str + ch;
                }
            }
            return str;
            
    }
};












