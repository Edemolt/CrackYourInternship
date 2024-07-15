class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        
        int k = 0;
        for(int i = 0; i < n; i++){
            if(nums[i]){
                swap(nums[i], nums[k]);
                k += 1;
            }
        }
    }
};