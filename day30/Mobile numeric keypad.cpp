//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long getCount(int n) {
        // Your code goes here 
        if (n == 0) return 0;
    
    // Define the possible moves from each digit
    vector<vector<int>> moves = {
        {0, 8},         // from 0 you can move to 0 or 8
        {1, 2, 4},      // from 1 you can move to 1, 2, or 4
        {2, 1, 3, 5},   // from 2 you can move to 1, 2, 3, or 5
        {3, 2, 6},      // from 3 you can move to 2, 3, or 6
        {4, 1, 5, 7},   // from 4 you can move to 1, 4, 5, or 7
        {5, 2, 4, 6, 8},// from 5 you can move to 2, 4, 5, 6, or 8
        {6, 3, 5, 9},   // from 6 you can move to 3, 5, 6, or 9
        {7, 4, 8},      // from 7 you can move to 4, 7, or 8
        {8, 0, 5, 7, 9},// from 8 you can move to 0, 5, 7, 8, or 9
        {9, 6, 8}       // from 9 you can move to 6, 8, or 9
    };
    
    // DP table to store the count of sequences ending at each digit
    vector<vector<long long>> dp(n + 1, vector<long long>(10, 0));
    
    // Base case: sequences of length 1
    for (int j = 0; j <= 9; ++j) {
        dp[1][j] = 1;
    }
    
    // Fill the DP table for sequences of length 2 to n
    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j <= 9; ++j) {
            dp[i][j] = 0;
            for (int move : moves[j]) {
               dp[i][j] += (long long)dp[i - 1][move];
            }
        }
    }
    
    // Sum up the sequences of length n ending at each digit
    long long total_sequences = 0;
    for (int j = 0; j <= 9; ++j) {
        total_sequences += dp[n][j];
    }
    
    return total_sequences;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        cout << ob.getCount(n) << "\n";
    }
    return 0;
}

// } Driver Code Ends