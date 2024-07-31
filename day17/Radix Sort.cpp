//{ Driver Code Starts
//Initial Template for C++

#include  <bits/stdc++.h> 
using namespace std; 
  

// } Driver Code Ends
//User function Template for C++

int getmax(int arr[], int n){
    int mx = arr[0];
    for(int i = 0; i < n; i++) mx = max(mx, arr[i]);
    
    return mx;
}

void sort(int arr[], int exp, int n) {
    // int n = arr.size();
    std::vector<int> output(n); // Output array to store sorted numbers
    int count[10] = {0};        // Count array to store occurrences of digits (0-9)

    // Store count of occurrences of each digit in count[]
    for (int i = 0; i < n; i++) {
        int index = (arr[i] / exp) % 10;
        count[index]++;
    }

    // Change count[i] so that it contains the actual position of this digit in output[]
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        int index = (arr[i] / exp) % 10;
        output[count[index] - 1] = arr[i];
        count[index]--;
    }

    // Copy the output array to arr[], so that arr now contains sorted numbers according to the current digit
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void radixSort(int arr[], int n) 
{ 
   // code here
   int mx = getmax(arr, n);
   
   for(int i = 1; mx / i > 0; i *= 10) sort(arr, i, n);
} 

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
  
        radixSort(arr, n); 
        
        for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";
        
        cout<<endl;
    }
    return 0; 
} 
// } Driver Code Ends