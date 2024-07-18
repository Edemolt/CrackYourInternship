class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalgas = 0, currgas = 0;
        int start = 0;

        int n = cost.size();
        for(int i = 0; i < n; i++){
            totalgas += gas[i] - cost[i];
            currgas += gas[i] - cost[i];

            if(currgas < 0){
                start = i + 1;
                currgas = 0;
            }
        }

        return totalgas < 0 ? -1 : start;
    }
};
