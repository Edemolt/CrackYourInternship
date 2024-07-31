#include <bits/stdc++.h>
using namespace std;

bool can(int arr[], int n, int c, int ind) {
    int pos = arr[0];
    int cnt = 1;
    
    for(int i = 1; i < n; i++) {
        if(arr[i] - pos >= ind) {
            cnt += 1;
            pos = arr[i];
        }
        if(cnt == c) return true;
    }
    return false;
}

int find(int arr[], int n, int c) {
    int l = 1, r = arr[n-1] - arr[0];
    int res = 0;
    
    while(l <= r) {
        int mid = l + (r - l) / 2;
        
        if(can(arr, n, c, mid)) {
            res = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    
    return res;
}

void solve() {
    int n, c;
    cin >> n >> c;
    
    vector<int> stalls(n);
    for(int i = 0; i < n; i++) cin >> stalls[i];
    sort(stalls.begin(), stalls.end());
    cout << find(stalls.data(), n, c) << "\n";
}

int main() {
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
