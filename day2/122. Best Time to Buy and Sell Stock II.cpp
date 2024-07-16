class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mx = 0;
        int n = prices.size();
        int start = prices[0];
        for(int i = 1; i < n; i++){
            if(prices[i] > start){
                mx += prices[i] - start;
            }
            start = prices[i];
        }

        return mx;
    }
};