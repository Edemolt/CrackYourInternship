class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int pos1,pos2,pos3, pos4, pos5;
        pos1 = pos2 = pos3 = pos4 = pos5 = -1;
        int mx1,mx2,mx3;
        mx1 = mx2 = mx3 =-1e9;
        int n = nums.size();
        int mn1 = 1e9, mn2 = 1e9;

        for(int i = 0; i < n; i++){
            if(mx1 < nums[i]){
                mx1 = nums[i];
                pos1 = i;
            }
        }

        for(int i = 0; i < n; i++){
            if(mx2 < nums[i] && i != pos1){
                mx2 = nums[i];
                pos2 = i;
            }
        }

        for(int i = 0; i < n; i++){
            if(mx3 < nums[i] && i != pos1 && i != pos2){
                mx3 = nums[i];
                pos3 = i;
            }
        }

        for(int i = 0; i < n; i++){
            if(mn1 > nums[i]){
                mn1 = nums[i];
                pos4 = i;
            }
        }

        for(int i = 0; i < n; i++){
            if(mn2 > nums[i] && i != pos4){
                mn2 = nums[i];
                pos5 = i;
            }
        }

        return max(mx1 * mx2 * mx3, mn1 * mn2 * mx1);
    }
};