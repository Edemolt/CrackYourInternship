//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to find the largest number after k swaps.
    string maxNum;
    
    void findMaximumNumUtil(string str, int k, int idx)
    {
        if(k == 0 || idx == str.length())
            return;
        
        char maxChar = str[idx];
        for(int i = idx + 1; i < str.length(); i++)
            if(str[i] > maxChar)
                maxChar = str[i];
        
        if(maxChar != str[idx])
            k--;
        
        for(int i = str.length() - 1; i >= idx; i--)
        {
            if(str[i] == maxChar)
            {
                swap(str[idx], str[i]);
                if(str.compare(maxNum) > 0)
                    maxNum = str;
                
                findMaximumNumUtil(str, k, idx + 1);
                
                swap(str[idx], str[i]);
            }
        }
        
        findMaximumNumUtil(str, k, idx + 1);
    }
    string findMaximumNum(string str, int k)
    {
       // code here.
        maxNum = str;
        findMaximumNumUtil(str, k, 0);
        return maxNum;
    }
};

//{ Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}

// } Driver Code Ends