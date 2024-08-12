//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};


// } Driver Code Ends
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution{
  public:
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
        int total_petrol = 0;
        int total_distance = 0;
        int current_balance = 0;
        int starting_point = 0;

        for(int i = 0; i < n; i++) {
            total_petrol += p[i].petrol;
            total_distance += p[i].distance;
            current_balance += (p[i].petrol - p[i].distance);

            // If current balance is negative, reset the starting point
            if(current_balance < 0) {
                starting_point = i + 1;
                current_balance = 0;
            }
        }

        // Check if the total petrol is enough to cover the total distance
        if(total_petrol >= total_distance) {
            return starting_point;
        } else {
            return -1;
        }
    }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        Solution obj;
        cout<<obj.tour(p,n)<<endl;
    }
}

// } Driver Code Ends