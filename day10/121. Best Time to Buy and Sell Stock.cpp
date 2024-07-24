class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = 1e9;
        int sell = -1e9;

        for(int &price : prices){
            buy = min(buy, price);
            sell = max(sell, price - buy);
        }
        return sell;


    }
};