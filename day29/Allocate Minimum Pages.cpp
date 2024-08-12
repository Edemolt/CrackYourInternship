//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template in C++

class Solution {
  public:
    // Function to find minimum number of pages.
    bool can(int arr[], int n, int m, int mid) {
        int req = 1, curr = 0;
        
        for(int i = 0; i < n; i++) {
            if(arr[i] > mid) return false;
            
            if(curr + arr[i] > mid) {
                req += 1;
                curr = arr[i];
                if(req > m) return false;
            } else {
                curr += arr[i];
            }
        }
        return true;
    }
    long long findPages(int n, int arr[], int m) {
        // code here
        if(m > n) return -1;
        // sort(arr, arr + n);
        
        int sum = 0, mx = -1e9;
        
        for(int i = 0; i < n; i++){
            sum += arr[i];
            mx = max( mx, arr[i]);
        }
        int res = -1;
        
        int start = mx, end = sum;
        while(start <= end){
            int mid = ( start + end)/2;
            
            if( can(arr, n, m, mid)){
                res = mid;
                end = mid - 1;
            }else{
                start = mid + 1;
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        int m;
        cin >> m;
        Solution ob;
        cout << ob.findPages(n, A, m) << endl;
    }
    return 0;
}

// } Driver Code Ends