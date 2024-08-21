#include <bits/stdc++.h>
using namespace std;

void solve(){
    int m, n;
    cin >> m >> n;
    
    priority_queue<pair< int, int> > pq;
    
    for(int i = 0; i < m - 1; i++){
        int cost;
        cin >> cost;
        pq.push({cost, 0});
    }
    
    for(int i = 0; i < n-1; i++){
        int cost;
        cin >> cost;
        pq.push({cost, 1});
    }
    
    int h = 1, v = 1;
    long long total = 0;
    
    while(!(pq.empty())){
        auto it = pq.top();
        pq.pop();
        int cost = it.first;
        int type = it.second;
        
        if(type){
            total += cost * v;
            h += 1;
        }else{
            total += cost * h;
            v += 1;
        }
    }
    
    cout<<total<<"\n";
    
    
    
}

int main(){
    int t;
    cin >> t;
    while( t-- ) solve();
}